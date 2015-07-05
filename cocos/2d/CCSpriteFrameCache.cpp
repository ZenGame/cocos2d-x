/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2009      Jason Booth
Copyright (c) 2009      Robert J Payne
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "2d/CCSpriteFrameCache.h"

#include <vector>


#include "2d/CCSprite.h"
#include "platform/CCFileUtils.h"
#include "base/CCNS.h"
#include "base/ccMacros.h"
#include "base/CCDirector.h"
#include "renderer/CCTexture2D.h"
#include "renderer/CCTextureCache.h"


#include "deprecated/CCString.h"

#include "CCHash.h"

using namespace std;

NS_CC_BEGIN

static SpriteFrameCache *_sharedSpriteFrameCache = nullptr;

SpriteFrameCache* SpriteFrameCache::getInstance()
{
    if (! _sharedSpriteFrameCache)
    {
        _sharedSpriteFrameCache = new (std::nothrow) SpriteFrameCache();
        _sharedSpriteFrameCache->init();
    }

    return _sharedSpriteFrameCache;
}

void SpriteFrameCache::destroyInstance()
{
    CC_SAFE_RELEASE_NULL(_sharedSpriteFrameCache);
}

bool SpriteFrameCache::init()
{
    //_spriteFrames.reserve(20);
	_spriteFramesHash.reserve(20);
    _spriteFramesAliases.reserve(20);
    _loadedFileNames = new std::set<std::string>();
    return true;
}

SpriteFrameCache::~SpriteFrameCache()
{
    CC_SAFE_DELETE(_loadedFileNames);
}

void SpriteFrameCache::addSpriteFramesWithDictionary(ValueMap& dictionary, Texture2D* texture, const std::string& prefix)
{
    /*
    Supported Zwoptex Formats:

    ZWTCoordinatesFormatOptionXMLLegacy = 0, // Flash Version
    ZWTCoordinatesFormatOptionXML1_0 = 1, // Desktop Version 0.0 - 0.4b
    ZWTCoordinatesFormatOptionXML1_1 = 2, // Desktop Version 1.0.0 - 1.0.1
    ZWTCoordinatesFormatOptionXML1_2 = 3, // Desktop Version 1.0.2+
    */

	if (dictionary.find("frames") == dictionary.end())
		return;

    ValueMap& framesDict = dictionary["frames"].asValueMap();
    int format = 0;

    // get the format
    if (dictionary.find("metadata") != dictionary.end())
    {
        ValueMap& metadataDict = dictionary["metadata"].asValueMap();
        format = metadataDict["format"].asInt();
    }

    // check the format
    CCASSERT(format >=0 && format <= 3, "format is not supported for SpriteFrameCache addSpriteFramesWithDictionary:textureFilename:");

	frames_lock();
    for (auto iter = framesDict.begin(); iter != framesDict.end(); ++iter)
    {
        ValueMap& frameDict = iter->second.asValueMap();
		std::string spriteFrameName = prefix + iter->first;
        //SpriteFrame* spriteFrame = _spriteFrames.at(spriteFrameName);
		SpriteFrame* spriteFrame = _spriteFramesHash.at(cocos2d::SP::CCHash::hashString(spriteFrameName.c_str()));
        if (spriteFrame)
        {
            continue;
        }

        if(format == 0) 
        {
            float x = frameDict["x"].asFloat();
            float y = frameDict["y"].asFloat();
            float w = frameDict["width"].asFloat();
            float h = frameDict["height"].asFloat();
            float ox = frameDict["offsetX"].asFloat();
            float oy = frameDict["offsetY"].asFloat();
            int ow = frameDict["originalWidth"].asInt();
            int oh = frameDict["originalHeight"].asInt();
            // check ow/oh
            if(!ow || !oh)
            {
                CCLOGWARN("cocos2d: WARNING: originalWidth/Height not found on the SpriteFrame. AnchorPoint won't work as expected. Regenrate the .plist");
            }
            // abs ow/oh
            ow = abs(ow);
            oh = abs(oh);
            // create frame
            spriteFrame = SpriteFrame::createWithTexture(texture,
                                                         Rect(x, y, w, h),
                                                         false,
                                                         Vec2(ox, oy),
                                                         Size((float)ow, (float)oh)
                                                         );
        } 
        else if(format == 1 || format == 2) 
        {
            Rect frame = RectFromString(frameDict["frame"].asString());
            bool rotated = false;

            // rotation
            if (format == 2)
            {
                rotated = frameDict["rotated"].asBool();
            }

            Vec2 offset = PointFromString(frameDict["offset"].asString());
            Size sourceSize = SizeFromString(frameDict["sourceSize"].asString());

            // create frame
            spriteFrame = SpriteFrame::createWithTexture(texture,
                                                         frame,
                                                         rotated,
                                                         offset,
                                                         sourceSize
                                                         );
        } 
        else if (format == 3)
        {
            // get values
            Size spriteSize = SizeFromString(frameDict["spriteSize"].asString());
            Vec2 spriteOffset = PointFromString(frameDict["spriteOffset"].asString());
            Size spriteSourceSize = SizeFromString(frameDict["spriteSourceSize"].asString());
            Rect textureRect = RectFromString(frameDict["textureRect"].asString());
            bool textureRotated = frameDict["textureRotated"].asBool();

            // get aliases
            ValueVector& aliases = frameDict["aliases"].asValueVector();

            for(const auto &value : aliases) {
                std::string oneAlias = value.asString();
                if (_spriteFramesAliases.find(oneAlias) != _spriteFramesAliases.end())
                {
                    CCLOGWARN("cocos2d: WARNING: an alias with name %s already exists", oneAlias.c_str());
                }

                _spriteFramesAliases[oneAlias] = Value(spriteFrameName);
            }
            
            // create frame
            spriteFrame = SpriteFrame::createWithTexture(texture,
                                                         Rect(textureRect.origin.x, textureRect.origin.y, spriteSize.width, spriteSize.height),
                                                         textureRotated,
                                                         spriteOffset,
                                                         spriteSourceSize);
        }
		
        // add sprite frame
       // _spriteFrames.insert(spriteFrameName, spriteFrame);
		_spriteFramesHash.insert(cocos2d::SP::CCHash::hashString(spriteFrameName.c_str()), spriteFrame);
		//CCLOG("add frames %s",spriteFrameName.c_str());
    }
	frames_unlock();
}

void SpriteFrameCache::addSpriteFramesWithFile(const std::string& pszPlist, Texture2D *pobTexture, const std::string& prefix)
{
	file_lock();
	if (_loadedFileNames->find(pszPlist) != _loadedFileNames->end())
    {
		file_unlock();
        return; // We already added it
    }
	file_unlock();

    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(pszPlist);
    ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);

    addSpriteFramesWithDictionary(dict, pobTexture, prefix);
	file_lock();
	_loadedFileNames->insert(pszPlist);
	file_unlock();
}

void SpriteFrameCache::addSpriteFramesWithFileContent(const std::string& plist_content, Texture2D *texture)
{
    ValueMap dict = FileUtils::getInstance()->getValueMapFromData(plist_content.c_str(), static_cast<int>(plist_content.size()));
    addSpriteFramesWithDictionary(dict, texture);
}

void SpriteFrameCache::addSpriteFramesWithFile(const std::string& plist, const std::string& textureFileName, const std::string& prefix)
{
	file_lock();
    if (_loadedFileNames->find(plist) != _loadedFileNames->end())
    {
		file_unlock();
        return; // We already added it
    }
	file_unlock();

    CCASSERT(textureFileName.size()>0, "texture name should not be null");
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(textureFileName);

    if (texture)
    {
        addSpriteFramesWithFile(plist, texture, prefix);
    }
    else
    {
        CCLOG("cocos2d: SpriteFrameCache: couldn't load texture file. File not found %s", textureFileName.c_str());
    }
}

void SpriteFrameCache::addSpriteFramesWithFile(const std::string& plist)
{
    CCASSERT(plist.size()>0, "plist filename should not be nullptr");

	file_lock();
    if (_loadedFileNames->find(plist) == _loadedFileNames->end())
    {
        std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
        ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);

        string texturePath("");

        if (dict.find("metadata") != dict.end())
        {
            ValueMap& metadataDict = dict["metadata"].asValueMap();
            // try to read  texture file name from meta data
            texturePath = metadataDict["textureFileName"].asString();
        }

        if (!texturePath.empty())
        {
            // build texture path relative to plist file
            texturePath = FileUtils::getInstance()->fullPathFromRelativeFile(texturePath.c_str(), plist);
        }
        else
        {
            // build texture path by replacing file extension
            texturePath = plist;

            // remove .xxx
            size_t startPos = texturePath.find_last_of("."); 
            texturePath = texturePath.erase(startPos);

            // append .png
            texturePath = texturePath.append(".png");

            CCLOG("cocos2d: SpriteFrameCache: Trying to use file %s as texture", texturePath.c_str());
        }

        Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(texturePath.c_str());

        if (texture)
        {
            addSpriteFramesWithDictionary(dict, texture);
            _loadedFileNames->insert(plist);
        }
        else
        {
            CCLOG("cocos2d: SpriteFrameCache: Couldn't load texture");
        }
    }
	file_unlock();
}

void SpriteFrameCache::addSpriteFrame(SpriteFrame* frame, const std::string& frameName)
{
	frames_lock();
    //_spriteFrames.insert(frameName, frame);
	_spriteFramesHash.insert(cocos2d::SP::CCHash::hashString(frameName.c_str()), frame);
	frames_unlock();
}

void SpriteFrameCache::removeSpriteFrames()
{
	frames_lock();
    //_spriteFrames.clear();
	_spriteFramesHash.clear();
    _spriteFramesAliases.clear();
	frames_unlock();

	file_lock();
    _loadedFileNames->clear();
	file_unlock();
}

void SpriteFrameCache::removeUnusedSpriteFrames()
{
    bool removed = false;
    //std::vector<std::string> toRemoveFrames;
	std::vector<int> toRemoveFrames;
	frames_lock();
    //for (auto iter = _spriteFrames.begin(); iter != _spriteFrames.end(); ++iter)
	for (auto iter = _spriteFramesHash.begin(); iter != _spriteFramesHash.end();++iter)
    {
        SpriteFrame* spriteFrame = iter->second;
        if( spriteFrame->getReferenceCount() == 1 )
        {
            toRemoveFrames.push_back(iter->first);
            //CCLOG("cocos2d: SpriteFrameCache: removing unused frame: %s", iter->first.c_str());
			CCLOG("coocs2d: SpriteFrameCache: removing unused frame: hash 0x%08x", iter->first);
            removed = true;
        }
    }
	
   // _spriteFrames.erase(toRemoveFrames);
	_spriteFramesHash.erase(toRemoveFrames);
	frames_unlock();
    
    // FIXME:. Since we don't know the .plist file that originated the frame, we must remove all .plist from the cache
    if( removed )
    {
		file_lock();
        _loadedFileNames->clear();
		file_unlock();
    }
}


void SpriteFrameCache::removeSpriteFrameByName(const std::string& name)
{
    // explicit nil handling
    if( !(name.size()>0) )
        return;

    // Is this an alias ?
    std::string key = _spriteFramesAliases[name].asString();

	frames_lock();
    if (!key.empty())
    {
        //_spriteFrames.erase(key);
		_spriteFramesHash.erase(cocos2d::SP::CCHash::hashString(key.c_str()));
        _spriteFramesAliases.erase(key);
    }
    else
    {
        //_spriteFrames.erase(name);
		_spriteFramesHash.erase(cocos2d::SP::CCHash::hashString(name.c_str()));
    }
	frames_unlock();
    // XXX. Since we don't know the .plist file that originated the frame, we must remove all .plist from the cache
	file_lock();

    // FIXME:. Since we don't know the .plist file that originated the frame, we must remove all .plist from the cache
    _loadedFileNames->clear();
	file_unlock();
}

void SpriteFrameCache::removeSpriteFramesFromFile(const std::string& plist)
{
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
    ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);
    if (dict.empty())
    {
        CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: create dict by %s fail.",plist.c_str());
        return;
    }
// #if COCOS2D_DEBUG>=1
// 	CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: begin to clean frames in %s", plist.c_str());
// #endif
	removeSpriteFramesFromDictionary(dict);
// #if COCOS2D_DEBUG>=1
// 	CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: clean frames in %s end", plist.c_str());
// #endif
    // remove it from the cache
	file_lock();
	std::set<string>::iterator ret = _loadedFileNames->find(plist);
    if (ret != _loadedFileNames->end())
    {
        _loadedFileNames->erase(ret);
		CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: erase %s ok", plist.c_str());
    }
	else
	{
		ret = _loadedFileNames->find(fullPath);
		if (ret != _loadedFileNames->end())
		{
			_loadedFileNames->erase(ret);
			CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: erase %s ok (full path)", fullPath.c_str());
		}
// #if COCOS2D_DEBUG>=1
// 		else
// 			CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: cannot find %s (full path)", fullPath.c_str());
// #endif
	}
	file_unlock();
}


void SpriteFrameCache::removeSpriteFramesFromFile(const std::string& plist, const std::string& prefix)
{
	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
	ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);
	if (dict.empty())
	{
		CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: create dict by %s fail.", plist.c_str());
		return;
	}
// #if COCOS2D_DEBUG>=1
// 	CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: begin to clean frames in %s prefix is %s", plist.c_str(), prefix.c_str());
// #endif
	removeSpriteFramesFromDictionary(dict, prefix);
// #if COCOS2D_DEBUG>=1
// 	CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: clean frames in %s end prefix is %s", plist.c_str(), prefix.c_str());
// #endif
	// remove it from the cache
	file_lock();
	std::set<string>::iterator ret = _loadedFileNames->find(plist);
	if (ret != _loadedFileNames->end())
	{
		_loadedFileNames->erase(ret);
		CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: erase %s ok", plist.c_str());
	}
	else
	{
		ret = _loadedFileNames->find(fullPath);
		if (ret != _loadedFileNames->end())
		{
			_loadedFileNames->erase(ret);
			CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: erase %s ok (full path)", fullPath.c_str());
		}
// #if COCOS2D_DEBUG>=1
// 		else
// 			CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFile: cannot find %s (full path)", fullPath.c_str());
// #endif
	}
		
	file_unlock();
}

void SpriteFrameCache::removeSpriteFramesFromFileContent(const std::string& plist_content)
{
    ValueMap dict = FileUtils::getInstance()->getValueMapFromData(plist_content.data(), static_cast<int>(plist_content.size()));
    if (dict.empty())
    {
        CCLOG("cocos2d:SpriteFrameCache:removeSpriteFramesFromFileContent: create dict by fail.");
        return;
    }
    removeSpriteFramesFromDictionary(dict);
}

void SpriteFrameCache::removeSpriteFramesFromDictionary(ValueMap& dictionary)
{
    ValueMap framesDict = dictionary["frames"].asValueMap();
    //std::vector<std::string> keysToRemove;
	std::vector<int> keysToRemove;
	frames_lock();
    for (auto iter = framesDict.cbegin(); iter != framesDict.cend(); ++iter)
    {
        
		int hash = cocos2d::SP::CCHash::hashString(iter->first.c_str());
		//if (_spriteFrames.at(iter->first))
		if (_spriteFramesHash.at(hash))
        {
           // keysToRemove.push_back(iter->first);
			keysToRemove.push_back(hash);
        }
    }

    //_spriteFrames.erase(keysToRemove);
	_spriteFramesHash.erase(keysToRemove);
	frames_unlock();
}


void SpriteFrameCache::removeSpriteFramesFromDictionary(ValueMap& dictionary,const std::string& prefix)
{
    ValueMap framesDict = dictionary["frames"].asValueMap();
    //std::vector<std::string> keysToRemove;
	std::vector<int> keysToRemove;
	frames_lock();
    for (auto iter = framesDict.cbegin(); iter != framesDict.cend(); ++iter)
    {
    	std::string name=prefix+iter->first;
		int hash = cocos2d::SP::CCHash::hashString(name.c_str());
        //if (_spriteFrames.at(name))
		if (_spriteFramesHash.at(hash))
        {
            //keysToRemove.push_back(name);
			keysToRemove.push_back(hash);
        }

    }
    //_spriteFrames.erase(keysToRemove);
	_spriteFramesHash.erase(keysToRemove);
	frames_unlock();
}



void SpriteFrameCache::removeSpriteFramesFromTexture(Texture2D* texture)
{
    //std::vector<std::string> keysToRemove;
	std::vector<int> keysToRemove;
	frames_lock();
	//for (auto iter = _spriteFrames.cbegin(); iter != _spriteFrames.cend(); ++iter)
	for (auto iter = _spriteFramesHash.cbegin(); iter != _spriteFramesHash.cend(); ++iter)
	{
		//std::string key = iter->first;
		//SpriteFrame* frame = _spriteFrames.at(key);
		int hash = iter->first;
		SpriteFrame* frame = _spriteFramesHash.at(hash);
		if (frame && (frame->getTexture() == texture))
		{
			//keysToRemove.push_back(key);
			keysToRemove.push_back(hash);
		}
	}
    //_spriteFrames.erase(keysToRemove);
	_spriteFramesHash.erase(keysToRemove);
	frames_unlock();
}

void SpriteFrameCache::removePlistFile(const std::string& plistFullFileName)
{
	// remove it from the cache
	file_lock();
	set<string>::iterator ret = _loadedFileNames->find(plistFullFileName);
	if (ret != _loadedFileNames->end())
	{
		_loadedFileNames->erase(ret);
		CCLOG("cocos2d:SpriteFrameCache:removePlistFile: erase %s ok", plistFullFileName.c_str());
	}
	//else
		//CCLOG("cocos2d:SpriteFrameCache:removePlistFile: cannot find  %s", plistFullFileName.c_str());
	file_unlock();
}

SpriteFrame* SpriteFrameCache::getSpriteFrameByName(const std::string& name)
{
    //SpriteFrame* frame = _spriteFrames.at(name);
	SpriteFrame* frame = _spriteFramesHash.at(cocos2d::SP::CCHash::hashString(name.c_str()));
    if (!frame)
    {
        // try alias dictionary
        std::string key = _spriteFramesAliases[name].asString();
        if (!key.empty())
        {
            //frame = _spriteFrames.at(key);
			frame = _spriteFramesHash.at(cocos2d::SP::CCHash::hashString(key.c_str()));
            if (!frame)
            {
                CCLOG("cocos2d: SpriteFrameCache: Frame '%s' not found", name.c_str());
            }
        }
    }
    return frame;
}

void SpriteFrameCache::printAll()
{
//     for (auto iter = _spriteFrames.begin(); iter != _spriteFrames.end(); ++iter)
//     {
//         SpriteFrame* spriteFrame = iter->second;
// 		std::string name=iter->first;
// 		CCLOG("cocos2d: SpriteFrameCache: %s %d",name.c_str(),spriteFrame->getReferenceCount());
//     }
	for (auto iter = _spriteFramesHash.begin(); iter != _spriteFramesHash.end(); ++iter)
	{
		SpriteFrame* spriteFrame = iter->second;
		int hash = iter->first;
		CCLOG("cocos2d: SpriteFrameCache: 0x%08x %d", iter->first, spriteFrame->getReferenceCount());
	}
	auto iter = _loadedFileNames->begin();

	while (iter!=_loadedFileNames->end())
	{
		std::string name = *iter;
		iter++;
		CCLOG("cocos2d: SpriteFrameCache:plist %s ", name.c_str());
	}
}

NS_CC_END


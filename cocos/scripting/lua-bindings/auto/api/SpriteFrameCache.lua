
--------------------------------
-- @module SpriteFrameCache
-- @extend Ref
-- @parent_module cc

--------------------------------
--  Adds multiple Sprite Frames from a plist file content. The texture will be associated with the created sprite frames. <br>
-- js addSpriteFrames<br>
-- lua addSpriteFrames
-- @function [parent=#SpriteFrameCache] addSpriteFramesWithFileContent 
-- @param self
-- @param #string plist_content
-- @param #cc.Texture2D texture
        
--------------------------------
-- @overload self, string, string, string         
-- @overload self, string         
-- @overload self, string, cc.Texture2D, string         
-- @function [parent=#SpriteFrameCache] addSpriteFramesWithFile
-- @param self
-- @param #string plist
-- @param #cc.Texture2D texture
-- @param #string prefix

--------------------------------
--  Adds an sprite frame with a given name.<br>
-- If the name already exists, then the contents of the old name will be replaced with the new one.
-- @function [parent=#SpriteFrameCache] addSpriteFrame 
-- @param self
-- @param #cc.SpriteFrame frame
-- @param #string frameName
        
--------------------------------
--  Removes unused sprite frames.<br>
-- Sprite Frames that have a retain count of 1 will be deleted.<br>
-- It is convenient to call this method after when starting a new Scene.
-- @function [parent=#SpriteFrameCache] removeUnusedSpriteFrames 
-- @param self
        
--------------------------------
--  Returns an Sprite Frame that was previously added.<br>
-- If the name is not found it will return nil.<br>
-- You should retain the returned copy if you are going to use it.<br>
-- js getSpriteFrame<br>
-- lua getSpriteFrame
-- @function [parent=#SpriteFrameCache] getSpriteFrameByName 
-- @param self
-- @param #string name
-- @return SpriteFrame#SpriteFrame ret (return value: cc.SpriteFrame)
        
--------------------------------
-- 
-- @function [parent=#SpriteFrameCache] removePlistFile 
-- @param self
-- @param #string plistFullFileName
        
--------------------------------
-- 
-- @function [parent=#SpriteFrameCache] printAll 
-- @param self
        
--------------------------------
-- @overload self, string, string         
-- @overload self, string         
-- @function [parent=#SpriteFrameCache] removeSpriteFramesFromFile
-- @param self
-- @param #string plist
-- @param #string prefix

--------------------------------
-- 
-- @function [parent=#SpriteFrameCache] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
--  Purges the dictionary of loaded sprite frames.<br>
-- Call this method if you receive the "Memory Warning".<br>
-- In the short term: it will free some resources preventing your app from being killed.<br>
-- In the medium term: it will allocate more resources.<br>
-- In the long term: it will be the same.
-- @function [parent=#SpriteFrameCache] removeSpriteFrames 
-- @param self
        
--------------------------------
--  Removes all Sprite Frames associated with the specified textures.<br>
-- It is convenient to call this method when a specific texture needs to be removed.<br>
-- since v0.995.
-- @function [parent=#SpriteFrameCache] removeSpriteFramesFromTexture 
-- @param self
-- @param #cc.Texture2D texture
        
--------------------------------
--  Removes multiple Sprite Frames from a plist file content.<br>
-- Sprite Frames stored in this file will be removed.<br>
-- It is convenient to call this method when a specific texture needs to be removed.
-- @function [parent=#SpriteFrameCache] removeSpriteFramesFromFileContent 
-- @param self
-- @param #string plist_content
        
--------------------------------
--  Deletes an sprite frame from the sprite frame cache. 
-- @function [parent=#SpriteFrameCache] removeSpriteFrameByName 
-- @param self
-- @param #string name
        
--------------------------------
-- 
-- @function [parent=#SpriteFrameCache] removeSpriteFramesFromDictionary 
-- @param self
-- @param #map_table dictionary
-- @param #string prefix
        
--------------------------------
--  Destroys the cache. It releases all the Sprite Frames and the retained instance. 
-- @function [parent=#SpriteFrameCache] destroyInstance 
-- @param self
        
--------------------------------
--  Returns the shared instance of the Sprite Frame cache 
-- @function [parent=#SpriteFrameCache] getInstance 
-- @param self
-- @return SpriteFrameCache#SpriteFrameCache ret (return value: cc.SpriteFrameCache)
        
return nil

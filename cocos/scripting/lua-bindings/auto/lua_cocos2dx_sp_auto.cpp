#include "lua_cocos2dx_sp_auto.hpp"
#include "cocos-sp-auto-bind.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_sp_CCUtil_getImageSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Size ret = cocos2d::SP::CCUtil::getImageSize(arg0);
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getImageSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCUtil_getImageSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCUtil_sleepms(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocos2d::SP::CCUtil::sleepms(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sleepms",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCUtil_sleepms'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCUtil_sleeps(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCUtil",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocos2d::SP::CCUtil::sleeps(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sleeps",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCUtil_sleeps'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCUtil)");
    return 0;
}

int lua_register_cocos2dx_sp_CCUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCUtil");
    tolua_cclass(tolua_S,"CCUtil","ccsp::CCUtil","",nullptr);

    tolua_beginmodule(tolua_S,"CCUtil");
        tolua_function(tolua_S,"getImageSize", lua_cocos2dx_sp_CCUtil_getImageSize);
        tolua_function(tolua_S,"sleepms", lua_cocos2dx_sp_CCUtil_sleepms);
        tolua_function(tolua_S,"sleeps", lua_cocos2dx_sp_CCUtil_sleeps);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCUtil).name();
    g_luaType[typeName] = "ccsp::CCUtil";
    g_typeCast["CCUtil"] = "ccsp::CCUtil";
    return 1;
}

int lua_cocos2dx_sp_CCFile_read(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCFile_read'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        int ret = cobj->read(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "read",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_read'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCFile_write(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCFile_write'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        int ret = cobj->write(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "write",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_write'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCFile_writeLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCFile_writeLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        bool ret = cobj->writeLine(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "writeLine",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_writeLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCFile_close(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCFile_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->close();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "close",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_close'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCFile_readLine(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCFile*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCFile_readLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        int arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        bool ret = cobj->readLine(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "readLine",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_readLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCFile_open(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::SP::CCFile* ret = cocos2d::SP::CCFile::open(arg0);
        object_to_luaval<cocos2d::SP::CCFile>(tolua_S, "ccsp::CCFile",(cocos2d::SP::CCFile*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "open",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_open'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFile_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::SP::CCFile* ret = cocos2d::SP::CCFile::create(arg0);
        object_to_luaval<cocos2d::SP::CCFile>(tolua_S, "ccsp::CCFile",(cocos2d::SP::CCFile*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFile_createNotTruncate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::SP::CCFile* ret = cocos2d::SP::CCFile::createNotTruncate(arg0);
        object_to_luaval<cocos2d::SP::CCFile>(tolua_S, "ccsp::CCFile",(cocos2d::SP::CCFile*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createNotTruncate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_createNotTruncate'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFile_openWithMode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFile",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::SP::CCFile* ret = cocos2d::SP::CCFile::openWithMode(arg0, arg1);
        object_to_luaval<cocos2d::SP::CCFile>(tolua_S, "ccsp::CCFile",(cocos2d::SP::CCFile*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "openWithMode",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_openWithMode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFile_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCFile* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::SP::CCFile();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ccsp::CCFile");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCFile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFile_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_sp_CCFile_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCFile)");
    return 0;
}

int lua_register_cocos2dx_sp_CCFile(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCFile");
    tolua_cclass(tolua_S,"CCFile","ccsp::CCFile","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCFile");
        tolua_function(tolua_S,"read",lua_cocos2dx_sp_CCFile_read);
        tolua_function(tolua_S,"write",lua_cocos2dx_sp_CCFile_write);
        tolua_function(tolua_S,"writeLine",lua_cocos2dx_sp_CCFile_writeLine);
        tolua_function(tolua_S,"close",lua_cocos2dx_sp_CCFile_close);
        tolua_function(tolua_S,"readLine",lua_cocos2dx_sp_CCFile_readLine);
        tolua_function(tolua_S,"new",lua_cocos2dx_sp_CCFile_constructor);
        tolua_function(tolua_S,"open", lua_cocos2dx_sp_CCFile_open);
        tolua_function(tolua_S,"create", lua_cocos2dx_sp_CCFile_create);
        tolua_function(tolua_S,"createNotTruncate", lua_cocos2dx_sp_CCFile_createNotTruncate);
        tolua_function(tolua_S,"openWithMode", lua_cocos2dx_sp_CCFile_openWithMode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCFile).name();
    g_luaType[typeName] = "ccsp::CCFile";
    g_typeCast["CCFile"] = "ccsp::CCFile";
    return 1;
}

int lua_cocos2dx_sp_CCFileControl_unzip(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCFileControl::unzip(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "unzip",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_unzip'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_unzipInBack(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::SP::CCFileControl::unzipInBack(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "unzipInBack",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_unzipInBack'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getPackageName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCFileControl::getPackageName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getPackageName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getPackageName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_move(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCFileControl::move(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "move",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_move'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        long long ret = cocos2d::SP::CCFileControl::getSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getUnzipCurrentSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCFileControl::getUnzipCurrentSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getUnzipCurrentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getUnzipCurrentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getUnzipTotalSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCFileControl::getUnzipTotalSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getUnzipTotalSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getUnzipTotalSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_del(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCFileControl::del(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "del",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_del'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getExt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCFileControl::getExt(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getExt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getExt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getFullPathName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCFileControl::getFullPathName(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getFullPathName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getFullPathName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getUnzipPercent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCFileControl::getUnzipPercent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getUnzipPercent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getUnzipPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_copy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCFileControl::copy(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "copy",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_getZipFileUncompressedSize(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCFileControl::getZipFileUncompressedSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getZipFileUncompressedSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_getZipFileUncompressedSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCFileControl_setExecutable(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCFileControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCFileControl::setExecutable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setExecutable",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCFileControl_setExecutable'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCFileControl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCFileControl)");
    return 0;
}

int lua_register_cocos2dx_sp_CCFileControl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCFileControl");
    tolua_cclass(tolua_S,"CCFileControl","ccsp::CCFileControl","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCFileControl");
        tolua_function(tolua_S,"unzip", lua_cocos2dx_sp_CCFileControl_unzip);
        tolua_function(tolua_S,"unzipInBack", lua_cocos2dx_sp_CCFileControl_unzipInBack);
        tolua_function(tolua_S,"getPackageName", lua_cocos2dx_sp_CCFileControl_getPackageName);
        tolua_function(tolua_S,"move", lua_cocos2dx_sp_CCFileControl_move);
        tolua_function(tolua_S,"getSize", lua_cocos2dx_sp_CCFileControl_getSize);
        tolua_function(tolua_S,"getUnzipCurrentSize", lua_cocos2dx_sp_CCFileControl_getUnzipCurrentSize);
        tolua_function(tolua_S,"getUnzipTotalSize", lua_cocos2dx_sp_CCFileControl_getUnzipTotalSize);
        tolua_function(tolua_S,"del", lua_cocos2dx_sp_CCFileControl_del);
        tolua_function(tolua_S,"getExt", lua_cocos2dx_sp_CCFileControl_getExt);
        tolua_function(tolua_S,"getFullPathName", lua_cocos2dx_sp_CCFileControl_getFullPathName);
        tolua_function(tolua_S,"getUnzipPercent", lua_cocos2dx_sp_CCFileControl_getUnzipPercent);
        tolua_function(tolua_S,"copy", lua_cocos2dx_sp_CCFileControl_copy);
        tolua_function(tolua_S,"getZipFileUncompressedSize", lua_cocos2dx_sp_CCFileControl_getZipFileUncompressedSize);
        tolua_function(tolua_S,"setExecutable", lua_cocos2dx_sp_CCFileControl_setExecutable);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCFileControl).name();
    g_luaType[typeName] = "ccsp::CCFileControl";
    g_typeCast["CCFileControl"] = "ccsp::CCFileControl";
    return 1;
}

int lua_cocos2dx_sp_CCDirControl_findDirList(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            std::vector<std::string> ret = cocos2d::SP::CCDirControl::findDirList(arg0, arg1);
            ccvector_std_string_to_luaval(tolua_S, ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            std::vector<std::string> ret = cocos2d::SP::CCDirControl::findDirList(arg0);
            ccvector_std_string_to_luaval(tolua_S, ret);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "findDirList",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_findDirList'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCDirControl::create(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_getFullPathName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCDirControl::getFullPathName(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getFullPathName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_getFullPathName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_getCurDir(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCDirControl::getCurDir();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getCurDir",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_getCurDir'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_findFileList(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        std::vector<std::string> ret = cocos2d::SP::CCDirControl::findFileList(arg0, arg1);
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "findFileList",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_findFileList'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_isDirExist(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCDirControl::isDirExist(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "isDirExist",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_isDirExist'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_del(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCDirControl::del(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "del",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_del'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_copy(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cocos2d::SP::CCDirControl::copy(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "copy",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCDirControl_getWritablePath(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCDirControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCDirControl::getWritablePath();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getWritablePath",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCDirControl_getWritablePath'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCDirControl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCDirControl)");
    return 0;
}

int lua_register_cocos2dx_sp_CCDirControl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCDirControl");
    tolua_cclass(tolua_S,"CCDirControl","ccsp::CCDirControl","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCDirControl");
        tolua_function(tolua_S,"findDirList", lua_cocos2dx_sp_CCDirControl_findDirList);
        tolua_function(tolua_S,"create", lua_cocos2dx_sp_CCDirControl_create);
        tolua_function(tolua_S,"getFullPathName", lua_cocos2dx_sp_CCDirControl_getFullPathName);
        tolua_function(tolua_S,"getCurDir", lua_cocos2dx_sp_CCDirControl_getCurDir);
        tolua_function(tolua_S,"findFileList", lua_cocos2dx_sp_CCDirControl_findFileList);
        tolua_function(tolua_S,"isDirExist", lua_cocos2dx_sp_CCDirControl_isDirExist);
        tolua_function(tolua_S,"del", lua_cocos2dx_sp_CCDirControl_del);
        tolua_function(tolua_S,"copy", lua_cocos2dx_sp_CCDirControl_copy);
        tolua_function(tolua_S,"getWritablePath", lua_cocos2dx_sp_CCDirControl_getWritablePath);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCDirControl).name();
    g_luaType[typeName] = "ccsp::CCDirControl";
    g_typeCast["CCDirControl"] = "ccsp::CCDirControl";
    return 1;
}

int lua_cocos2dx_sp_CCHttp_uploadNoWait(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_uploadNoWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->uploadNoWait(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "uploadNoWait",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_uploadNoWait'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_postNoWait(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_postNoWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->postNoWait(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "postNoWait",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_postNoWait'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_get(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_get'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        const char* arg0;
        unsigned char* arg1;
        int arg2;
        int* arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

        #pragma warning NO CONVERSION TO NATIVE FOR int*;
        if(!ok)
            return 0;
        int ret = cobj->get(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "get",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_get'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_isFinished(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_isFinished'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFinished();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFinished",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_isFinished'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_upload(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_upload'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        unsigned char* arg3;
        int arg4;
        int* arg5;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4);

        #pragma warning NO CONVERSION TO NATIVE FOR int*;
        if(!ok)
            return 0;
        int ret = cobj->upload(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "upload",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_upload'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_getNoWait(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_getNoWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->getNoWait(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNoWait",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_getNoWait'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_getError(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_getError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getError();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getError",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_getError'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_clean(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clean();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_download(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_download'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->download(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "download",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_download'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_post(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_post'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        const char* arg0;
        const char* arg1;
        unsigned char* arg2;
        int arg3;
        int* arg4;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);

        #pragma warning NO CONVERSION TO NATIVE FOR int*;
        if(!ok)
            return 0;
        int ret = cobj->post(arg0, arg1, arg2, arg3, arg4);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "post",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_post'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_getData(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_getData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        char* ret = cobj->getData();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_getData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_downloadNoWait(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCHttp*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCHttp_downloadNoWait'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->downloadNoWait(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "downloadNoWait",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_downloadNoWait'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCHttp_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::SP::CCHttp* ret = cocos2d::SP::CCHttp::create();
        object_to_luaval<cocos2d::SP::CCHttp>(tolua_S, "ccsp::CCHttp",(cocos2d::SP::CCHttp*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCHttp_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCHttp",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::SP::CCHttp* ret = cocos2d::SP::CCHttp::getInstance();
        object_to_luaval<cocos2d::SP::CCHttp>(tolua_S, "ccsp::CCHttp",(cocos2d::SP::CCHttp*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCHttp_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCHttp* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::SP::CCHttp();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ccsp::CCHttp");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "CCHttp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCHttp_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_sp_CCHttp_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCHttp)");
    return 0;
}

int lua_register_cocos2dx_sp_CCHttp(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCHttp");
    tolua_cclass(tolua_S,"CCHttp","ccsp::CCHttp","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCHttp");
        tolua_function(tolua_S,"uploadNoWait",lua_cocos2dx_sp_CCHttp_uploadNoWait);
        tolua_function(tolua_S,"postNoWait",lua_cocos2dx_sp_CCHttp_postNoWait);
        tolua_function(tolua_S,"get",lua_cocos2dx_sp_CCHttp_get);
        tolua_function(tolua_S,"isFinished",lua_cocos2dx_sp_CCHttp_isFinished);
        tolua_function(tolua_S,"upload",lua_cocos2dx_sp_CCHttp_upload);
        tolua_function(tolua_S,"getNoWait",lua_cocos2dx_sp_CCHttp_getNoWait);
        tolua_function(tolua_S,"init",lua_cocos2dx_sp_CCHttp_init);
        tolua_function(tolua_S,"getError",lua_cocos2dx_sp_CCHttp_getError);
        tolua_function(tolua_S,"clean",lua_cocos2dx_sp_CCHttp_clean);
        tolua_function(tolua_S,"download",lua_cocos2dx_sp_CCHttp_download);
        tolua_function(tolua_S,"post",lua_cocos2dx_sp_CCHttp_post);
        tolua_function(tolua_S,"getData",lua_cocos2dx_sp_CCHttp_getData);
        tolua_function(tolua_S,"downloadNoWait",lua_cocos2dx_sp_CCHttp_downloadNoWait);
        tolua_function(tolua_S,"new",lua_cocos2dx_sp_CCHttp_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_sp_CCHttp_create);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_sp_CCHttp_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCHttp).name();
    g_luaType[typeName] = "ccsp::CCHttp";
    g_typeCast["CCHttp"] = "ccsp::CCHttp";
    return 1;
}

int lua_cocos2dx_sp_CCEncrypt_decrypt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCEncrypt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        unsigned char* arg0;
        int arg1;
        unsigned char* arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCEncrypt::decrypt(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "decrypt",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCEncrypt_decrypt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCEncrypt_encrypt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCEncrypt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        unsigned char* arg0;
        int arg1;
        unsigned char* arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCEncrypt::encrypt(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "encrypt",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCEncrypt_encrypt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCEncrypt_encrypt_rand_1(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCEncrypt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCEncrypt::encrypt_rand_1();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "encrypt_rand_1",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCEncrypt_encrypt_rand_1'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCEncrypt_encrypt_rand(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCEncrypt",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        unsigned int ret = cocos2d::SP::CCEncrypt::encrypt_rand();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "encrypt_rand",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCEncrypt_encrypt_rand'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCEncrypt_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCEncrypt)");
    return 0;
}

int lua_register_cocos2dx_sp_CCEncrypt(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCEncrypt");
    tolua_cclass(tolua_S,"CCEncrypt","ccsp::CCEncrypt","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCEncrypt");
        tolua_function(tolua_S,"decrypt", lua_cocos2dx_sp_CCEncrypt_decrypt);
        tolua_function(tolua_S,"encrypt", lua_cocos2dx_sp_CCEncrypt_encrypt);
        tolua_function(tolua_S,"encrypt_rand_1", lua_cocos2dx_sp_CCEncrypt_encrypt_rand_1);
        tolua_function(tolua_S,"encrypt_rand", lua_cocos2dx_sp_CCEncrypt_encrypt_rand);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCEncrypt).name();
    g_luaType[typeName] = "ccsp::CCEncrypt";
    g_typeCast["CCEncrypt"] = "ccsp::CCEncrypt";
    return 1;
}

int lua_cocos2dx_sp_CCMD5_getHash(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCMD5",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCMD5::getHash(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getHash",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCMD5_getHash'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCMD5_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCMD5)");
    return 0;
}

int lua_register_cocos2dx_sp_CCMD5(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCMD5");
    tolua_cclass(tolua_S,"CCMD5","ccsp::CCMD5","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCMD5");
        tolua_function(tolua_S,"getHash", lua_cocos2dx_sp_CCMD5_getHash);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCMD5).name();
    g_luaType[typeName] = "ccsp::CCMD5";
    g_typeCast["CCMD5"] = "ccsp::CCMD5";
    return 1;
}

int lua_cocos2dx_sp_CCSPString_explode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCSPString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        unsigned char* arg0;
        int32_t arg1;
        char** arg2;
        int arg3;
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*;
        ok &= luaval_to_int32(tolua_S, 3,&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR char**;
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCSPString::explode(arg0, arg1, arg2, arg3);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "explode",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCSPString_explode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCSPString_rand(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCSPString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCSPString::rand(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "rand",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCSPString_rand'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCSPString_convertString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCSPString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::CCSPString::convertString(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "convertString",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCSPString_convertString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCSPString_stricmp(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCSPString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCSPString::stricmp(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "stricmp",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCSPString_stricmp'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCSPString_strnicmp(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCSPString",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        const char* arg1;
        int arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCSPString::strnicmp(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "strnicmp",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCSPString_strnicmp'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCSPString_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCSPString)");
    return 0;
}

int lua_register_cocos2dx_sp_CCSPString(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCSPString");
    tolua_cclass(tolua_S,"CCSPString","ccsp::CCSPString","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCSPString");
        tolua_function(tolua_S,"explode", lua_cocos2dx_sp_CCSPString_explode);
        tolua_function(tolua_S,"rand", lua_cocos2dx_sp_CCSPString_rand);
        tolua_function(tolua_S,"convertString", lua_cocos2dx_sp_CCSPString_convertString);
        tolua_function(tolua_S,"stricmp", lua_cocos2dx_sp_CCSPString_stricmp);
        tolua_function(tolua_S,"strnicmp", lua_cocos2dx_sp_CCSPString_strnicmp);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCSPString).name();
    g_luaType[typeName] = "ccsp::CCSPString";
    g_typeCast["CCSPString"] = "ccsp::CCSPString";
    return 1;
}

int lua_cocos2dx_sp_FlyInput_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onEnter();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_onExit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->onExit();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_getString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_setPasswd(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_setPasswd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPasswd(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswd",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_setPasswd'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_setString(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setString(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_init(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Size arg0;
        const char* arg1;
        double arg2;

        ok &= luaval_to_size(tolua_S, 2, &arg0);

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_initCursorSprite(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::FlyInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_FlyInput_initCursorSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->initCursorSprite(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initCursorSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_initCursorSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_FlyInput_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::FlyInput",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        cocos2d::Size arg0;
        const char* arg1;
        double arg2;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cocos2d::SP::FlyInput* ret = cocos2d::SP::FlyInput::create(arg0, arg1, arg2);
        object_to_luaval<cocos2d::SP::FlyInput>(tolua_S, "ccsp::FlyInput",(cocos2d::SP::FlyInput*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_FlyInput_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::FlyInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocos2d::SP::FlyInput();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ccsp::FlyInput");
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "FlyInput",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_FlyInput_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_sp_FlyInput_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FlyInput)");
    return 0;
}

int lua_register_cocos2dx_sp_FlyInput(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::FlyInput");
    tolua_cclass(tolua_S,"FlyInput","ccsp::FlyInput","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"FlyInput");
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_sp_FlyInput_onEnter);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_sp_FlyInput_onExit);
        tolua_function(tolua_S,"getString",lua_cocos2dx_sp_FlyInput_getString);
        tolua_function(tolua_S,"setPasswd",lua_cocos2dx_sp_FlyInput_setPasswd);
        tolua_function(tolua_S,"setString",lua_cocos2dx_sp_FlyInput_setString);
        tolua_function(tolua_S,"init",lua_cocos2dx_sp_FlyInput_init);
        tolua_function(tolua_S,"initCursorSprite",lua_cocos2dx_sp_FlyInput_initCursorSprite);
        tolua_function(tolua_S,"new",lua_cocos2dx_sp_FlyInput_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_sp_FlyInput_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::FlyInput).name();
    g_luaType[typeName] = "ccsp::FlyInput";
    g_typeCast["FlyInput"] = "ccsp::FlyInput";
    return 1;
}

int lua_cocos2dx_sp_DeviceInfoCPP_getGPUInfo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::DeviceInfoCPP",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::DeviceInfoCPP::getGPUInfo();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getGPUInfo",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_DeviceInfoCPP_getGPUInfo'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_DeviceInfoCPP_getString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::DeviceInfoCPP",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        std::string ret = cocos2d::SP::DeviceInfoCPP::getString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getString",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_DeviceInfoCPP_getString'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_DeviceInfoCPP_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DeviceInfoCPP)");
    return 0;
}

int lua_register_cocos2dx_sp_DeviceInfoCPP(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::DeviceInfoCPP");
    tolua_cclass(tolua_S,"DeviceInfoCPP","ccsp::DeviceInfoCPP","",nullptr);

    tolua_beginmodule(tolua_S,"DeviceInfoCPP");
        tolua_function(tolua_S,"getGPUInfo", lua_cocos2dx_sp_DeviceInfoCPP_getGPUInfo);
        tolua_function(tolua_S,"getString", lua_cocos2dx_sp_DeviceInfoCPP_getString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::DeviceInfoCPP).name();
    g_luaType[typeName] = "ccsp::DeviceInfoCPP";
    g_typeCast["DeviceInfoCPP"] = "ccsp::DeviceInfoCPP";
    return 1;
}

int lua_cocos2dx_sp_PicMgr_createHighlightSprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::PicMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cocos2d::SP::PicMgr::createHighlightSprite(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createHighlightSprite",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_PicMgr_createHighlightSprite'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_PicMgr_createGraySpritePlist(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::PicMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cocos2d::SP::PicMgr::createGraySpritePlist(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createGraySpritePlist",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_PicMgr_createGraySpritePlist'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_PicMgr_createMem(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::PicMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        unsigned char* ret = cocos2d::SP::PicMgr::createMem(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR unsigned char*;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createMem",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_PicMgr_createMem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_PicMgr_createGraySprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::PicMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Sprite* ret = cocos2d::SP::PicMgr::createGraySprite(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createGraySprite",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_PicMgr_createGraySprite'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_PicMgr_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PicMgr)");
    return 0;
}

int lua_register_cocos2dx_sp_PicMgr(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::PicMgr");
    tolua_cclass(tolua_S,"PicMgr","ccsp::PicMgr","",nullptr);

    tolua_beginmodule(tolua_S,"PicMgr");
        tolua_function(tolua_S,"createHighlightSprite", lua_cocos2dx_sp_PicMgr_createHighlightSprite);
        tolua_function(tolua_S,"createGraySpritePlist", lua_cocos2dx_sp_PicMgr_createGraySpritePlist);
        tolua_function(tolua_S,"createMem", lua_cocos2dx_sp_PicMgr_createMem);
        tolua_function(tolua_S,"createGraySprite", lua_cocos2dx_sp_PicMgr_createGraySprite);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::PicMgr).name();
    g_luaType[typeName] = "ccsp::PicMgr";
    g_typeCast["PicMgr"] = "ccsp::PicMgr";
    return 1;
}

int lua_cocos2dx_sp_CCUIControl_setUIGLState(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SP::CCUIControl* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ccsp::CCUIControl",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SP::CCUIControl*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_sp_CCUIControl_setUIGLState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::ui::Widget* arg0;
        cocos2d::GLProgramState* arg1;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0);

        ok &= luaval_to_object<cocos2d::GLProgramState>(tolua_S, 3, "cc.GLProgramState",&arg1);
        if(!ok)
            return 0;
        cobj->setUIGLState(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUIGLState",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCUIControl_setUIGLState'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_sp_CCUIControl_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCUIControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::SP::CCUIControl* ret = cocos2d::SP::CCUIControl::getInstance();
        object_to_luaval<cocos2d::SP::CCUIControl>(tolua_S, "ccsp::CCUIControl",(cocos2d::SP::CCUIControl*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCUIControl_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCUIControl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCUIControl)");
    return 0;
}

int lua_register_cocos2dx_sp_CCUIControl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCUIControl");
    tolua_cclass(tolua_S,"CCUIControl","ccsp::CCUIControl","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCUIControl");
        tolua_function(tolua_S,"setUIGLState",lua_cocos2dx_sp_CCUIControl_setUIGLState);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_sp_CCUIControl_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCUIControl).name();
    g_luaType[typeName] = "ccsp::CCUIControl";
    g_typeCast["CCUIControl"] = "ccsp::CCUIControl";
    return 1;
}

int lua_cocos2dx_sp_CCProcessControl_getMemoryTotal(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCProcessControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCProcessControl::getMemoryTotal();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getMemoryTotal",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCProcessControl_getMemoryTotal'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCProcessControl_getCurrentProcessMemory(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCProcessControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCProcessControl::getCurrentProcessMemory();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getCurrentProcessMemory",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCProcessControl_getCurrentProcessMemory'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_sp_CCProcessControl_getMemoryNotUsed(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ccsp::CCProcessControl",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        int ret = cocos2d::SP::CCProcessControl::getMemoryNotUsed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getMemoryNotUsed",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_sp_CCProcessControl_getMemoryNotUsed'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_sp_CCProcessControl_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCProcessControl)");
    return 0;
}

int lua_register_cocos2dx_sp_CCProcessControl(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ccsp::CCProcessControl");
    tolua_cclass(tolua_S,"CCProcessControl","ccsp::CCProcessControl","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCProcessControl");
        tolua_function(tolua_S,"getMemoryTotal", lua_cocos2dx_sp_CCProcessControl_getMemoryTotal);
        tolua_function(tolua_S,"getCurrentProcessMemory", lua_cocos2dx_sp_CCProcessControl_getCurrentProcessMemory);
        tolua_function(tolua_S,"getMemoryNotUsed", lua_cocos2dx_sp_CCProcessControl_getMemoryNotUsed);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SP::CCProcessControl).name();
    g_luaType[typeName] = "ccsp::CCProcessControl";
    g_typeCast["CCProcessControl"] = "ccsp::CCProcessControl";
    return 1;
}
TOLUA_API int register_all_cocos2dx_sp(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccsp",0);
	tolua_beginmodule(tolua_S,"ccsp");

	lua_register_cocos2dx_sp_CCSPString(tolua_S);
	lua_register_cocos2dx_sp_CCEncrypt(tolua_S);
	lua_register_cocos2dx_sp_CCMD5(tolua_S);
	lua_register_cocos2dx_sp_CCUtil(tolua_S);
	lua_register_cocos2dx_sp_PicMgr(tolua_S);
	lua_register_cocos2dx_sp_CCProcessControl(tolua_S);
	lua_register_cocos2dx_sp_CCFile(tolua_S);
	lua_register_cocos2dx_sp_FlyInput(tolua_S);
	lua_register_cocos2dx_sp_CCFileControl(tolua_S);
	lua_register_cocos2dx_sp_CCHttp(tolua_S);
	lua_register_cocos2dx_sp_CCDirControl(tolua_S);
	lua_register_cocos2dx_sp_CCUIControl(tolua_S);
	lua_register_cocos2dx_sp_DeviceInfoCPP(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}



--------------------------------
-- @module CCDirControl
-- @extend Ref
-- @parent_module ccsp

--------------------------------
-- @overload self, char, char         
-- @overload self, char         
-- @function [parent=#CCDirControl] findDirList
-- @param self
-- @param #char szSrcDir
-- @param #char fileRep
-- @return array_table#array_table ret (return value: array_table)

--------------------------------
-- 
-- @function [parent=#CCDirControl] create 
-- @param self
-- @param #char szdirName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] getFullPathName 
-- @param self
-- @param #char szFileName
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] getCurDir 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] findFileList 
-- @param self
-- @param #char szSrcDir
-- @param #char fileRep
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] isDirExist 
-- @param self
-- @param #char szDir
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] del 
-- @param self
-- @param #char szdirName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] copy 
-- @param self
-- @param #char szSrcName
-- @param #char szDstDir
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCDirControl] getWritablePath 
-- @param self
-- @return string#string ret (return value: string)
        
return nil


--------------------------------
-- @module CCDirControl
-- @extend Ref

--------------------------------
-- overload function: findDirList(char, char)
--          
-- overload function: findDirList(char)
--          
-- @function [parent=#CCDirControl] findDirList
-- @param self
-- @param #char char
-- @param #char char
-- @return array_table#array_table ret (retunr value: array_table)

--------------------------------
-- @function [parent=#CCDirControl] create 
-- @param self
-- @param #char char
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#CCDirControl] getFullPathName 
-- @param self
-- @param #char char
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#CCDirControl] getCurDir 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#CCDirControl] findFileList 
-- @param self
-- @param #char char
-- @param #char char
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- @function [parent=#CCDirControl] isDirExist 
-- @param self
-- @param #char char
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#CCDirControl] del 
-- @param self
-- @param #char char
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#CCDirControl] copy 
-- @param self
-- @param #char char
-- @param #char char
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#CCDirControl] getWritablePath 
-- @param self
-- @return string#string ret (return value: string)
        
return nil


--------------------------------
-- @module CCFileControl
-- @extend Ref
-- @parent_module ccsp

--------------------------------
-- 
-- @function [parent=#CCFileControl] unzip 
-- @param self
-- @param #char zipFileFullName
-- @param #char newPath
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] unzipInBack 
-- @param self
-- @param #char zipFileFullName
-- @param #char newPath
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] move 
-- @param self
-- @param #char szSrcName
-- @param #char szDstName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getSize 
-- @param self
-- @param #char szName
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getUnzipCurrentSize 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getUnzipTotalSize 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] del 
-- @param self
-- @param #char szName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getExt 
-- @param self
-- @param #char fileName
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getFullPathName 
-- @param self
-- @param #char fileName
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getUnzipPercent 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] copy 
-- @param self
-- @param #char szSrcName
-- @param #char szDstName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] getZipFileUncompressedSize 
-- @param self
-- @param #char zipFileFullName
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CCFileControl] setExecutable 
-- @param self
-- @param #char fileName
-- @return bool#bool ret (return value: bool)
        
return nil

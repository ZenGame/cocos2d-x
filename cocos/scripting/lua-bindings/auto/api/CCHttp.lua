
--------------------------------
-- @module CCHttp
-- @extend Ref
-- @parent_module ccsp

--------------------------------
-- 
-- @function [parent=#CCHttp] uploadNoWait 
-- @param self
-- @param #char szUrl
-- @param #char szPost
-- @param #char szFileName
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] postNoWait 
-- @param self
-- @param #char szUrl
-- @param #char szParam
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] get 
-- @param self
-- @param #char szUrl
-- @param #unsigned char szBuf
-- @param #int dwBufSize
-- @param #int dwNeedBufSize
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] isFinished 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] upload 
-- @param self
-- @param #char szUrl
-- @param #char szPost
-- @param #char szFileName
-- @param #unsigned char szBuf
-- @param #int dwBufSize
-- @param #int dwNeedBufSize
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] getNoWait 
-- @param self
-- @param #char szUrl
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] getError 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] clean 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#CCHttp] download 
-- @param self
-- @param #char szUrl
-- @param #char szFileName
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] post 
-- @param self
-- @param #char szUrl
-- @param #char szParam
-- @param #unsigned char szBuf
-- @param #int dwBufSize
-- @param #int dwNeedBufSize
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] getData 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] downloadNoWait 
-- @param self
-- @param #char szUrl
-- @param #char szFileName
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] create 
-- @param self
-- @return SP::CCHttp#SP::CCHttp ret (return value: cc.SP::CCHttp)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] getInstance 
-- @param self
-- @return SP::CCHttp#SP::CCHttp ret (return value: cc.SP::CCHttp)
        
--------------------------------
-- 
-- @function [parent=#CCHttp] CCHttp 
-- @param self
        
return nil

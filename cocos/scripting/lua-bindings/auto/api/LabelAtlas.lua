
--------------------------------
-- @module LabelAtlas
-- @extend AtlasNode,LabelProtocol

--------------------------------
-- 
-- @function [parent=#LabelAtlas] setString 
-- @param self
-- @param #string label
        
--------------------------------
-- overload function: initWithString(string, string)
--          
-- overload function: initWithString(string, string, int, int, int)
--          
-- overload function: initWithString(string, cc.Texture2D, int, int, int)
--          
-- @function [parent=#LabelAtlas] initWithString
-- @param self
-- @param #string string
-- @param #cc.Texture2D texture
-- @param #int itemWidth
-- @param #int itemHeight
-- @param #int startCharMap
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#LabelAtlas] updateAtlasValues 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#LabelAtlas] getString 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- overload function: create(string, string, int, int, int)
--          
-- overload function: create()
--          
-- overload function: create(string, string)
--          
-- @function [parent=#LabelAtlas] create
-- @param self
-- @param #string string
-- @param #string charMapFile
-- @param #int itemWidth
-- @param #int itemHeight
-- @param #int startCharMap
-- @return LabelAtlas#LabelAtlas ret (return value: cc.LabelAtlas)

--------------------------------
-- 
-- @function [parent=#LabelAtlas] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
return nil


--------------------------------
-- @module Event
-- @extend Ref

--------------------------------
--  Checks whether the event has been stopped 
-- @function [parent=#Event] isStopped 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
--  Gets the event type 
-- @function [parent=#Event] getType 
-- @param self
-- @return Event::Type#Event::Type ret (return value: cc.Event::Type)
        
--------------------------------
--  @brief Gets current target of the event<br>
-- return The target with which the event associates.<br>
-- note It onlys be available when the event listener is associated with node. <br>
-- It returns 0 when the listener is associated with fixed priority.
-- @function [parent=#Event] getCurrentTarget 
-- @param self
-- @return Node#Node ret (return value: cc.Node)
        
--------------------------------
--  Stops propagation for current event 
-- @function [parent=#Event] stopPropagation 
-- @param self
        
return nil

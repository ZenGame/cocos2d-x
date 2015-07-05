
--------------------------------
-- @module ControlSwitch
-- @extend Control

--------------------------------
-- 
-- @function [parent=#ControlSwitch] setEnabled 
-- @param self
-- @param #bool enabled
        
--------------------------------
-- overload function: setOn(bool)
--          
-- overload function: setOn(bool, bool)
--          
-- @function [parent=#ControlSwitch] setOn
-- @param self
-- @param #bool isOn
-- @param #bool animated

--------------------------------
-- 
-- @function [parent=#ControlSwitch] isOn 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- overload function: initWithMaskSprite(cc.Sprite, cc.Sprite, cc.Sprite, cc.Sprite, cc.Label, cc.Label)
--          
-- overload function: initWithMaskSprite(cc.Sprite, cc.Sprite, cc.Sprite, cc.Sprite)
--          
-- @function [parent=#ControlSwitch] initWithMaskSprite
-- @param self
-- @param #cc.Sprite maskSprite
-- @param #cc.Sprite onSprite
-- @param #cc.Sprite offSprite
-- @param #cc.Sprite thumbSprite
-- @param #cc.Label onLabel
-- @param #cc.Label offLabel
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#ControlSwitch] hasMoved 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ControlSwitch] locationFromTouch 
-- @param self
-- @param #cc.Touch touch
-- @return Vec2#Vec2 ret (return value: cc.Vec2)
        
--------------------------------
-- overload function: create(cc.Sprite, cc.Sprite, cc.Sprite, cc.Sprite)
--          
-- overload function: create(cc.Sprite, cc.Sprite, cc.Sprite, cc.Sprite, cc.Label, cc.Label)
--          
-- @function [parent=#ControlSwitch] create
-- @param self
-- @param #cc.Sprite maskSprite
-- @param #cc.Sprite onSprite
-- @param #cc.Sprite offSprite
-- @param #cc.Sprite thumbSprite
-- @param #cc.Label onLabel
-- @param #cc.Label offLabel
-- @return ControlSwitch#ControlSwitch ret (return value: cc.ControlSwitch)

--------------------------------
-- 
-- @function [parent=#ControlSwitch] onTouchMoved 
-- @param self
-- @param #cc.Touch pTouch
-- @param #cc.Event pEvent
        
--------------------------------
-- 
-- @function [parent=#ControlSwitch] onTouchEnded 
-- @param self
-- @param #cc.Touch pTouch
-- @param #cc.Event pEvent
        
--------------------------------
-- 
-- @function [parent=#ControlSwitch] onTouchCancelled 
-- @param self
-- @param #cc.Touch pTouch
-- @param #cc.Event pEvent
        
--------------------------------
-- 
-- @function [parent=#ControlSwitch] onTouchBegan 
-- @param self
-- @param #cc.Touch pTouch
-- @param #cc.Event pEvent
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- js ctor
-- @function [parent=#ControlSwitch] ControlSwitch 
-- @param self
        
return nil

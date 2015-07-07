
--------------------------------
-- @module Scheduler
-- @extend Ref
-- @parent_module cc

--------------------------------
--  Modifies the time of all scheduled callbacks.<br>
-- You can use this property to create a 'slow motion' or 'fast forward' effect.<br>
-- Default is 1.0. To create a 'slow motion' effect, use values below 1.0.<br>
-- To create a 'fast forward' effect, use values higher than 1.0.<br>
-- since v0.8<br>
-- warning It will affect EVERY scheduled selector / action.
-- @function [parent=#Scheduler] setTimeScale 
-- @param self
-- @param #float timeScale
-- @return Scheduler#Scheduler self (return value: cc.Scheduler)
        
--------------------------------
-- 
-- @function [parent=#Scheduler] disableScriptFunc 
-- @param self
-- @param #unsigned int entryID
-- @return Scheduler#Scheduler self (return value: cc.Scheduler)
        
--------------------------------
-- 
-- @function [parent=#Scheduler] setScriptFuncInner 
-- @param self
-- @param #unsigned int entryID
-- @param #float v
-- @return Scheduler#Scheduler self (return value: cc.Scheduler)
        
--------------------------------
-- 
-- @function [parent=#Scheduler] getScriptFuncState 
-- @param self
-- @param #unsigned int entryID
-- @return int#int ret (return value: int)
        
--------------------------------
-- Gets the time scale of schedule callbacks.<br>
-- see Scheduler::setTimeScale()
-- @function [parent=#Scheduler] getTimeScale 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#Scheduler] findScriptHandlerEntry 
-- @param self
-- @param #unsigned int entryID
-- @return SchedulerScriptHandlerEntry#SchedulerScriptHandlerEntry ret (return value: cc.SchedulerScriptHandlerEntry)
        
--------------------------------
-- 
-- @function [parent=#Scheduler] enableScriptFunc 
-- @param self
-- @param #unsigned int entryID
-- @return Scheduler#Scheduler self (return value: cc.Scheduler)
        
--------------------------------
-- Constructor<br>
-- js ctor
-- @function [parent=#Scheduler] Scheduler 
-- @param self
-- @return Scheduler#Scheduler self (return value: cc.Scheduler)
        
return nil

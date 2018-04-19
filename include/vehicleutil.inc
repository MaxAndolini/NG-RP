// SA-MP Vehicle States Helper Functions
// (c) 2012 SA-MP Team
// All rights reserved.

// VehicleParamsEx toggle helpers
stock ToggleVehicleEngine(vid)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(engine == VEHICLE_PARAMS_UNSET || engine == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vid,VEHICLE_PARAMS_ON,lights,alarm,doors,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,VEHICLE_PARAMS_OFF,lights,alarm,doors,bonnet,boot,objective);
}
stock ToggleVehicleLights(vid)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(lights == VEHICLE_PARAMS_UNSET || lights == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vid,engine,VEHICLE_PARAMS_ON,alarm,doors,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,engine,VEHICLE_PARAMS_OFF,alarm,doors,bonnet,boot,objective);
}
stock ToggleVehicleDoorsLocked(vid)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(doors == VEHICLE_PARAMS_UNSET || doors == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vid,engine,lights,alarm,VEHICLE_PARAMS_ON,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,VEHICLE_PARAMS_OFF,bonnet,boot,objective);
}
stock ToggleVehicleHood(vid)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(bonnet == VEHICLE_PARAMS_UNSET || bonnet == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vid,engine,lights,alarm,doors,VEHICLE_PARAMS_ON,boot,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,doors,VEHICLE_PARAMS_OFF,boot,objective);
}
stock ToggleVehicleTrunk(vid)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(boot == VEHICLE_PARAMS_UNSET || boot == VEHICLE_PARAMS_OFF) SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,VEHICLE_PARAMS_ON,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,VEHICLE_PARAMS_OFF,objective);
}
// VehicleParamsEx state setter helpers
stock SetVehicleEngineState(vid, setstate)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(setstate) SetVehicleParamsEx(vid,VEHICLE_PARAMS_ON,lights,alarm,doors,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,VEHICLE_PARAMS_OFF,lights,alarm,doors,bonnet,boot,objective);
}
stock SetVehicleLightsState(vid, setstate)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(setstate) SetVehicleParamsEx(vid,engine,VEHICLE_PARAMS_ON,alarm,doors,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,engine,VEHICLE_PARAMS_OFF,alarm,doors,bonnet,boot,objective);
}
stock SetVehicleDoorsLockedState(vid, setstate)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(setstate) SetVehicleParamsEx(vid,engine,lights,alarm,VEHICLE_PARAMS_ON,bonnet,boot,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,VEHICLE_PARAMS_OFF,bonnet,boot,objective);
}
stock SetVehicleHoodState(vid, setstate)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(setstate) SetVehicleParamsEx(vid,engine,lights,alarm,doors,VEHICLE_PARAMS_ON,boot,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,doors,VEHICLE_PARAMS_OFF,boot,objective);
}
stock SetVehicleTrunkState(vid, setstate)
{
     new engine,lights,alarm,doors,bonnet,boot,objective;
     GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	 if(setstate) SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,VEHICLE_PARAMS_ON,objective);
	 else SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,VEHICLE_PARAMS_OFF,objective);
}
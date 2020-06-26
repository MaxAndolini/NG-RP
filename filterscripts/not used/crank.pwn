// Kareemtastics Change
#include <a_samp>
#include <YSI_Data\y_iterate>
#include <Pawn.CMD>

forward IsPlayerInInvalidNosVehicle(playerid,vehicleid);

forward CrankTick();
new cranked[MAX_PLAYERS];

public OnFilterScriptInit()
{
	SetTimer("CrankTick", 3500, 1);
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 0;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate==PLAYER_STATE_ONFOOT&&oldstate==PLAYER_STATE_DRIVER)
	{
		cranked[playerid]=0;
	}
}

CMD:crank(playerid, params[])
{
	if(IsPlayerInInvalidNosVehicle(playerid, GetPlayerVehicleID(playerid))==1){SendClientMessage(playerid,0xAAAAAAAA, "You can't crank this.");return 1;}
	AddVehicleComponent(GetPlayerVehicleID(playerid),1087);
	AddVehicleComponent(GetPlayerVehicleID(playerid),1075);
	AddVehicleComponent(GetPlayerVehicleID(playerid),1010);
	SendClientMessage(playerid, 0xFFFFFFFF, "CRANKED");
	cranked[playerid]=1;
	return 1;
}

public IsPlayerInInvalidNosVehicle(playerid,vehicleid)
{
    #define MAX_INVALID_NOS_VEHICLES 30
    new InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
    {
	581,523,462,521,463,522,461,448,468,586,
	509,481,510,472,473,493,595,484,430,453,
	452,446,454,590,569,537,538,570,449,520
    };
    vehicleid = GetPlayerVehicleID(playerid);
    if(IsPlayerInVehicle(playerid,vehicleid)) {
	for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++) {
	    if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i])
		{
	        return true;
	    }
	}
    }
    return 0;
}

public CrankTick()
{
	foreach(new i : Player)
	{
		if(!cranked[i]) continue;
		{
			if(!IsPlayerInInvalidNosVehicle(i, GetPlayerVehicleID(i))){AddVehicleComponent(GetPlayerVehicleID(i),1010);}
		}
	}
}

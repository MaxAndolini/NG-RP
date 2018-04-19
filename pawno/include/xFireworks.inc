#include <a_samp>

//------------------------------------------------------------------------------

#if defined _xfireworks_included
	#endinput
#endif
#define _xfireworks_included
#pragma library xfireworks

/*
native xFireworks_OnObjectMoved();
native CreateFirework(Float:x,Float:y,Float:z,Float:height,Float:leandir,Float:windoffset,Float:climespeed,expltype,Float:explsize);
*/

//------------------------------------------------------------------------------

enum fireworks
{
	Float:f_height,
	Float:f_leandir,
	f_status,
	f_expltype,
	f_objectid,
	Float:f_explsize,
	Float:f_climespeed,
	Float:f_windoffset,
	bool:f_inuse
}

new Fireworks[MAX_OBJECTS][fireworks];

new colortypes[] = {354, 3666};

xFireworks_OnObjectMoved(objectid)
{
	new id = GetFireworkID(objectid);
	if(id == -1) return 0;
	switch(Fireworks[id][f_status])
	{
	    case 1..4:
	    {
	        new Float:x, Float:y, Float:z;
	        GetObjectPos(objectid,x,y,z);
    		GetXYInFrontOfPosition(x,y,Fireworks[id][f_leandir],Fireworks[id][f_windoffset] / 5);
			z += Fireworks[id][f_height] / 5;
    		Fireworks[id][f_status]++;
    		MoveObject(Fireworks[id][f_objectid],x,y,z,Fireworks[id][f_climespeed]);
	    }
	    default:
	    {
	        new Float:x, Float:y, Float:z;
	        GetObjectPos(objectid,x,y,z);
	        CreateExplosion(x,y,z,Fireworks[id][f_expltype],Fireworks[id][f_explsize]);
	        DestroyFirework(id);
	    }
	}
	return 1;
}

CreateFirework(Float:x,Float:y,Float:z,Float:height,Float:leandir,Float:windoffset,Float:climespeed,expltype,Float:explsize)
{
	new id = GetFreeID();
	if(id == -1) return 0;
	Fireworks[id][f_objectid] = CreateObject(colortypes[random(sizeof(colortypes))],x,y,z,0.0,0.0,0.0);
	Fireworks[id][f_height] = height;
	Fireworks[id][f_leandir] = leandir;
	Fireworks[id][f_expltype] = expltype;
	Fireworks[id][f_climespeed] = climespeed;
	Fireworks[id][f_windoffset] = windoffset;
	Fireworks[id][f_explsize] = explsize;
	Fireworks[id][f_inuse] = true;
    Fireworks[id][f_status] = 1;
    z += height / 5;
    GetXYInFrontOfPosition(x,y,leandir,windoffset / 5);
    MoveObject(Fireworks[id][f_objectid],x,y,z,climespeed);
    return 1;
}

stock GetFreeID()
{
	for(new i = 0; i < sizeof(Fireworks); i++)
	{
	    if(!Fireworks[i][f_inuse])
	    {
	        return i;
		}
	}
	return -1;
}

stock GetFireworkID(objectid)
{
	for(new i = 0; i < sizeof(Fireworks); i++)
	{
	    if(Fireworks[i][f_objectid] == objectid)
	    {
	        return i;
		}
	}
	return -1;
}

stock DestroyFirework(id)
{
	DestroyObject(Fireworks[id][f_objectid]);
	Fireworks[id][f_inuse] = false;
}

stock GetXYInFrontOfPosition(&Float:x, &Float:y, Float:a, Float:distance)
{
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
}

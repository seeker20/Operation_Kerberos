/*
	Author: Dorbedo
	
	Description:
		Selects Mission
	
	Parameter(s):
		0 : STRING	- TASKID
	
*/
#include "script_component.hpp"
SCRIPT(choose);
params [["_taskID",format["NOTNUMMER%1",random 1000000],[""]]];
TRACEV_1(_taskID);

private ["_taskarray","_armys","_army","_config","_task"];
_taskarray = [];
_armys = [];
_config = missionconfigfile>>"missions_config">>"main";
for "_i" from 0 to (count _config)-1 do {
	_taskarray pushBack [configname (_config select _i),getNumber((_config select _i)>>"probability")];
};

_task = ([_taskarray,1] call EFUNC(common,sel_array_weighted))select 0;

/// choose the army
_armys = getArray(missionconfigfile>>"missions_config">>"main">>_task>>"armys");
_army = ([_armys,1] call EFUNC(common,sel_array_weighted))select 0;
//[_army] call EFUNC(spawn,army_set);
["regular"] call EFUNC(spawn,army_set);

/// choose the position
private ["_positions","_positiontypes","_position"];
_positiontypes = getArray(missionconfigfile>>"missions_config">>"main">>_task>>"location">>"areas");
_positions = [];
{
	_positions append (missionnamespace getVariable [_x,[]]);
}forEach _positiontypes;
CHECK(_positions isEqualTo [])
_position = (_positions SELRND);
_distance = getnumber(missionconfigfile>>"missions_config">>"main">>_task>>"location">>"distance");


[_task,((_position)select 1),_distance,_taskID,(_position select 0)] call FUNC(mainmission_create);
LOG("RTB");
//[((_position)select 1),_task] call FUNC(rtb);
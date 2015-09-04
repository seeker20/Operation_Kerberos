/*
	Author: iJesuz
	
	Description:
		Überläufer erstellen
		Eigenschaften:
			Flugangst --> wenn er geflogen wird der Radius der Infos größer
			Paranoia --> wenn er mit zuviel Ammis in Kontakt kommt, denkt er sich zufällige Positionen aus
			Suizidgefährdet --> wenn er nach dem ersten Kontakt mit Ammis den Kontakt zu lang verliert, macht er Selbstmord
			nichts --> nichts

	Parameter(s):
		0 : Array - Position
		1 : Array of String - [Sidetaskname, Taskname]
*/
#include "script_component.hpp"

SCRIPT(obj_sideby_ueberlaeufer);

private ["_position", "_task_array", "_dest", "_ziel", "_zielPos", "_buildings", "_kleidung", "_description", "_fnc_conter", "_temp"];

DORB_SIDEBY_OBJECTS = [];

params ["_position", "_task_array"];

#ifdef TEST
	_position = getMarkerPos "spawn_side";
	_dest = getMarkerPos "spawn_conter";
	DORB_SIDE = east;
#else
	private "_buffer";
	_buffer = GETMVAR(DORB_MILITAER,[]);
	for "_i" from 1 to 130 do {
		_dest = ((_buffer SELRND) select 1) + [0];
		if ((_dest distance _position) > 6000) exitWith {};
	};
#endif

_zielPos = [_position, 50, 0] call DORB_fnc_random_pos;
_buildings = _position nearObjects ["House", 50];
if (!(_buildings isEqualTo [])) then {
	_zielPos = ([_buildings SELRND] call BIS_fnc_buildingPositions) SELRND;
};

_ziel = [_zielPos, createGroup civilian, "C_man_polo_1_F"] call FM(spawn_unit);
SETVAR(_ziel,DORB_IS_TARGET,true);
DORB_SIDEBY_OBJECTS pushBack _ziel;
removeAllWeapons _ziel; removeAllItems _ziel; removeAllAssignedItems _ziel; removeUniform _ziel; removeVest _ziel; removeBackpack _ziel; removeHeadgear _ziel; removeGoggles _ziel;
_ziel forceAddUniform (getText (missionConfigFile >> "sideby_config" >> "deserter" >> "uniform"));
for "_i" from 1 to (getNumber (missionConfigFile >> "sideby_config" >> "deserter" >> "magc")) do {_ziel addItemToUniform (getText (missionConfigFile >> "sideby_config" >> "deserter" >> "mag"));};
_ziel addHeadgear (getText (missionConfigFile >> "sideby_config" >> "deserter" >> "headgear"));
_ziel addGoggles (getText (missionConfigFile >> "sideby_config" >> "deserter" >> "googles"));
_ziel addWeapon (getText (missionConfigFile >> "sideby_config" >> "deserter" >> "weapon"));
for "_i" from 1 to 3 do {_ziel addItemToUniform "ACE_fieldDressing";}; _ziel addItemToUniform "ACE_EarPlugs"; for "_i" from 1 to 2 do {_ziel addItemToUniform "ACE_morphine";}; _ziel addItemToUniform "ACE_atropine"; _ziel addItemToUniform "ACE_epinephrine"; _ziel addItemToUniform "ACE_packingBandage"; _ziel addItemToUniform "ACE_elasticBandage";
_eigenschaften = ["Flugangst", "Paranoia", "suizidgefaehrdet", "nichts"];
_wichtung = [0.125, 0.25, 0.01, 1];
_eigenschaft = [_eigenschaften, _wichtung] call BIS_fnc_selectRandomWeighted;

LOG(FORMAT_2("[SIDEBY] Ueberlaeufer an Position %1 mit Eigenschaft %2 erstellt!", position _ziel, _eigenschaft));

switch (_eigenschaft) do
{
	case "Flugangst":
	{
		_description = "STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_2";
	};
	case "Paranoia":
	{
		_description = "STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_3";
	};
	case "suizidgefaehrdet":
	{
		_description = "STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_3";
	};
	case "nichts":
	{
		_description = "STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_1";
	};
};

["STR_DORB_SIDE_SIDEMISSION",["STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_SHORT"],"",false] call FM(disp_info_global);

_temp = [_task_array, true, [_description, "STR_DORB_SIDE_UEBERLAEUFER_DESCRIPTION_SHORT", "STR_DORB_SIDE_UEBERLAEUFER_MARKER"], _position,"AUTOASSIGNED",0,false,true,"",true] call BIS_fnc_setTask;
missionNamespace setVariable ["DORB_CURRENT_SIDEMISSION",_temp];

[_ziel, _eigenschaft, _task_array] spawn FM(TRIPLES(obj,sideby,ueberlaeuferVerhoeren));

_conter_size = "big";
_fnc_conter = {
	private ["_veh", "_group", "_veh_group", "_dest", "_target", "_ret", "_wp"];
	_veh = _this select 0;
	_group = _this select 1;
	_dest = _this select 2 select 0;
	_target = _this select 2 select 1;
	_ret = _this select 2 select 2;

	_veh_group = group driver _veh;
	(units _veh_group) join _group;

	_wp = [ _group addWaypoint [ [_dest, position leader _group, 100] call FM(pointBetween) , 0 ] ]; // _wp0
	(_wp select 0) setWaypointType "GETOUT";

	_wp = _wp + [ _group addWaypoint [ [_dest, position leader _group, 10] call FM(pointBetween) , 0 ] ]; // _wp1
	(_wp select 1) setWaypointType "MOVE";
	(_wp select 1) setWaypointBehaviour "AWARE";
	(_wp select 1) setWaypointStatements ["true", "{ if ((side _x) == civilian) then { _x setDamage 1; }; } forEach ((position this) nearEntities ['Man', 100])"];

	_wp = _wp + [ _group addWaypoint [ _veh, 0 ] ]; // _wp2
	(_wp select 2) setWaypointType "GETIN";

	_wp = _wp + [ _group addWaypoint [ _ret, 0 ] ]; // _wp3
	(_wp select 3) setWaypointType "MOVE";
	(_wp select 3) setWaypointStatements ["true","[group this, position this, 400] call BIS_fnc_taskPatrol;"];
};
[_conter_size, _dest, _fnc_conter, [_zielPos, _ziel, [_task_array select 1] call BIS_fnc_taskDestination]] spawn FM(TRIPLES(obj,sideby,conter));
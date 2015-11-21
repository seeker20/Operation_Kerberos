#include "script_component.hpp"

ADDON = false;

PREP(cleanup_big);
PREP(cleanup_small);

PREP(debug_marker_clean);
PREP(debug_marker_create);
PREP(determineHC);

PREP(EventExec);
PREP(EventExecLocal);
PREP(EventGlobal);
PREP(EventLocal);

PREP(get_buildings);
PREP(get_cfg_subclasses);
PREP(get_cfglocations);

PREP(handledamage_C4);
PREP(headless);
PREP(headless_determine);
PREP(headless_move);

PREP(list_groups);

PREP(moveToHC);

PREP(players);
PREP(pointBetween);
PREP(pos_flatempty);
PREP(pos_random);
PREP(pos_square);
PREP(pos_surrounding);
PREP(positionsMean);

PREP(rep);
//PREP(repairpoint);
//PREP(repairpoint_init);

PREP(sel_array_weighted);
PREP(setVarArray);

PREP(waitAndExec);

ADDON = true;

/// Setvariables
[
	{
		CHECK(GVAR(setVarSyncArray) isEqualTo [])
		private["_temp"];
		_temp = GVAR(setVarSyncArray);
		GVAR(setVarSyncArray) = [];
		{
			(_x select 2) setVariable [(_x select 0),(_x select 1),(_x select 3)];
		}forEach _temp;
	},
	1,
	[]
] call CBA_fnc_addPerFrameHandler;

If (!isServer) then {
	[
		{
			CHECK(GVAR(setVarSyncServerArray) isEqualTo [])
			private["_temp"];
			_temp = GVAR(setVarSyncServerArray);
			GVAR(setVarSyncServerArray) = [];
			{
				(_x select 2) setVariable [(_x select 0),(_x select 1),(_x select 3)];
			}forEach _temp;
		},
		5,
		[]
	] call CBA_fnc_addPerFrameHandler;
}else{
	//QGVAR(setVarSyncServerArray) addPublicVariableEventHandler {_this };
};

GVARMAIN(EVENTLOCAL)=[];
GVARMAIN(EVENTEXEC)=[];

if (!hasInterface) then {
	QGVARMAIN(EVENTLOCAL) addpublicVariableEventHandler {(_this select 1) call FUNC(EventLocal);};
	QGVARMAIN(EVENTEXEC) addpublicVariableEventHandler {(_this select 1) call FUNC(EventExec);};
}else{
	[] spawn {
		waitUntil {alive player};
		QGVARMAIN(EVENTLOCAL) addpublicVariableEventHandler {(_this select 1) call FUNC(EventLocal);};
		QGVARMAIN(EVENTEXEC) addpublicVariableEventHandler {(_this select 1) call FUNC(EventExec);};
	};
};

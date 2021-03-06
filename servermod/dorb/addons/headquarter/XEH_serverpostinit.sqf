/*
    Author: Dorbedo

    Description:
        postinit server
*/
#include "script_component.hpp"

GVAR(handles) = HASH_CREATE;
private "_handle";

["medical_onUnconscious", {
    _this params ["_unit", "_status"];
    if ((isplayer _unit)&&(_status)) then {
        [_unit] call FUNC(onUnconscious);
    };
}] call ace_common_fnc_addEventHandler;
/*************************
*
*       waypoints
*
************************/
GVAR(waypoints) = HASH_CREATE;

/*************************
*
*           FDC
*
*************************/

ISNIL(FDC_mortars,[]);
ISNIL(FDC_artilleries,[]);
ISNIL(FDC_rockets,[]);
ISNIL(FDC_firemissions,[]);

_handle = [LINKFUNC(fdc_handle),INTERVALL_FDC,[]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"fdc_main",_handle);

/*************************
*
*       Anti Air
*
*************************/
GVAR(antiair) = HASH_CREATE;
HASH_SET(GVAR(antiair),"mobile",[]);
HASH_SET(GVAR(antiair),"static",[]);
/*************************
*
*       Headquarter
*
*************************/
GVAR(active) = false;
GVAR(handle) = scriptNull;
GVAR(costs) = HASH_CREATE;
GVAR(strength) = HASH_CREATE;
GVAR(defence) = HASH_CREATE;

/*************************
*
*       Drones
*
*************************/
GVAR(drones_isActive) = false;
GVAR(drones_attackIntervall) = 600;
GVAR(drones_lastAttackRequest) = CBA_missiontime;
GVAR(drones_reconIntervall) = 600;
GVAR(drones_lastReconRequest) = CBA_missiontime;
GVAR(drones_requestedAirstrikes) = [];
GVAR(drones_requestedReconnaissances) = [];
GVAR(drones_availableAttackDrones) = [];
GVAR(drones_availableReconDrones) = [];

GVAR(drones_handle) = [LINKFUNC(drones_handle),10,[]] call CBA_fnc_addPerFrameHandler;


/// ressources
GVAR(ressources) = HASH_CREATE;
HASH_GET(GVAR(ressources),"amount",0);
{
    HASH_SET(GVAR(ressources),_x,HASH_CREATE);
} forEach ["cas","helicopter","airinterception"];

/// groups - player & ai
GVAR(AIGroups) = [];
GVAR(groups) = HASH_CREATE;
HASH_SET(GVAR(groups),"playergroups",[]);

GVAR(playergroups_new) = 0;

/// radars
GVAR(radars) = HASH_CREATE;
HASH_SET(GVAR(radars),"objects",[]);
HASH_SET(GVAR(radars),"targets",[]);
GVAR(radar_nextAI) = 0;

/// dangerzones
GVAR(dangerzones) = HASH_CREATE;
HASH_SET(GVAR(dangerzones),"definitions",[ARR_3(2000,100,20)]);
HASH_SET(GVAR(dangerzones),"gridsize",100);
HASH_SET(GVAR(dangerzones),"distance",2000);
GVAR(UnitKilledCoeff) = 1;

/// Strategy
GVAR(strategy_memory) = HASH_SERIALIZE(profileNamespace getVariable [ARR_2(QGVAR(strategy_memory),HASH_CREATE)]);

/// AttaclPos
GVAR(attackpos) = HASH_CREATE;
HASH_SET(GVAR(attackpos),"Locations",[]);

/// POI
GVAR(POI) = HASH_CREATE;
HASH_SET(GVAR(POI),"locations",[]);

/// Handles
_handle = [LINKFUNC(handle),INTERVALL_HQ,[]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"main",_handle);
_handle = [LINKFUNC(handleRadars),INTERVALL_RADARS,[]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"radars",_handle);
_handle = [LINKFUNC(handlePlayerGroups),INTERVALL_PLAYERGROUPS,[false]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"playergroups",_handle);
_handle = [LINKFUNC(handleAA),INTERVALL_AA,[]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"antiair",_handle);
_handle = [LINKFUNC(ressources_handle),INTERVALL_RESSOURCES,[]] call CBA_fnc_addPerFrameHandler;
HASH_SET(GVAR(handles),"ressources",_handle);

/// Events
[QEGVAR(mission,start_server),{_this call FUNC(MissionInit);}] call CBA_fnc_addEventHandler;
[QEGVAR(mission,start_server),{_this call FUNC(ressources_onMissionInit);}] call CBA_fnc_addEventHandler;
[QEGVAR(mission,end_server),{_this call FUNC(MissionCleanUp);}] call CBA_fnc_addEventHandler;
[QGVAR(registerRadar),{_this call FUNC(registerRadar)}] call CBA_fnc_addEventHandler;
[QGVAR(registerArtillery),{_this call FUNC(fdc_register)}] call CBA_fnc_addEventHandler;
[QGVAR(killedUnit),{_this call FUNC(onKilled);}] call CBA_fnc_addEventHandler;
[QGVAR(registerCenterPos),{HASH_SET(GVAR(dangerzones),"centerpos",_this select 0);}] call CBA_fnc_addEventHandler;
[QGVAR(disableCollisionWith),
    {
        (_this select 0) disableCollisionWith (_this select 1);
    }
] call CBA_fnc_addEventHandler;

// Statemachines
GVAR(statemachine_AIGroups_object) = [ConfigFile >> "CfgKerberos" >> "headquarter" >> QGVAR(statemachine_AIGroups)] spawn CBA_statemachine_fnc_createFromConfig;

// DEBUG
#ifdef DEBUG_MODE_FULL
If (isDedicated) then {
    GVAR(debugMarkerActive) = false;
    GVAR(debugMarkerActive) = true;
    [LINKFUNC(handleDebugMarker),60,[]] call CBA_fnc_addPerFrameHandler;
};
#endif

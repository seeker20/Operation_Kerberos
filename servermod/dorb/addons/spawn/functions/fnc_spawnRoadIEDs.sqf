/*
 *  Author: Dorbedo
 *
 *  Description:
 *      spawn IEDs on roads
 *
 *  Parameter(s):
 *      0 : ARRAY - Roadlist
 *      1 : SCALAR - amount
 *
 *  Returns:
 *      none
 *
 */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_this params [["_roadlist",[],[[]]],["_amount",0,[0]]];
TRACEV_2(_roadlist,_amount);
private _roadsReturn =+ _roadlist;
_roadlist = _roadlist call BIS_fnc_arrayshuffle;
_roadlist resize (((count _roadlist) min _amount) max 0);

{
    private _distance = switch ((_x select 2)) do {
        case 1 : {((random 4)+1.5)};
        case 2 : {((random 5)+1.5)};
        default {((random 3)+1.5)};
    };
    private _dir = [(_x select 1)+90,(_x select 1)+90] select (floor(random 2));
    private _spawnpos = (_x select 0) getPos [_distance,_dir];
    [_spawnpos,3,random(360)] call FUNC(spawnExplosive);
    #ifdef DEBUG_MODE_FULL
        [_spawnpos,"","","MinefieldAP"] call EFUNC(common,debug_marker_create);
    #endif
} forEach _roadlist;

_roadsReturn - _roadlist;

/*
 *  Author: Dorbedo
 *
 *  Description:
 *      displays the clock
 *
 *  Parameter(s):
 *      0 : DIALOG - dialog
 *
 *  Returns:
 *      none
 *
 */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

disableSerialization;
_this params ["_dialog"];

If !(canSuspend) exitWith {[_dialog] spawn FUNC(clock);};

private _clockPFH = _dialog getVariable QGVAR(clockPFH);

if !(isNil "_clockPFH") then {
    [_clockPFH] call CBA_fnc_removePerFrameHandler;
    _dialog setVariable [QGVAR(clockPFH),nil];
};


private _clockPFH = [
    LINKFUNC(clockPFH),
    1,
    _dialog
] call CBA_fnc_addPerFrameHandler;

_dialog setVariable [QGVAR(clockPFH),_clockPFH];
TRACEV_2(_dialog,_clockPFH);

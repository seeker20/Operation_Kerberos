/*
    Author: Dorbedo

    Description:
        adds Arsenal to a unit
        can be called via unit-init
*/
#include "script_component.hpp"
_this params [["_target",objNull,[objNull]],["_side",west,[west]],["_onlyGear",false,[true]]];

CHECK(isNull _target)

If ((isNil format[QGVAR(arsenalList_%1),str _side])||(GVAR(forceReload))) then {
    [_side,_onlyGear] call FUNC(getSideRestrictedArsenal);
};
(missionNamespace getVariable format[QGVAR(arsenalList_%1),str _side]) params ["_addWeapons","_addMagazines","_addItems","_addBackpacks",["_fixWeapons",[],[[]]],["_fixMagazines",[],[[]]],["_fixItems",[],[[]]],["_fixBackpacks",[],[[]]]];

[_target,_addWeapons,true,false] call bis_fnc_addVirtualWeaponCargo;
[_target,_addMagazines,true,false] call bis_fnc_addVirtualMagazineCargo;
[_target,_addItems,true,false] call bis_fnc_addVirtualItemCargo;
[_target,_addBackpacks,true,false] call bis_fnc_addVirtualBackpackCargo;
//[["AmmoboxServer",_target,true],"bis_fnc_arsenal",false] call bis_fnc_mp;
TRACEV_5(_side,_addItems,_addBackpacks,_addMagazines,_addWeapons);
private _fix = _target getVariable ["bis_addVirtualWeaponCargo_cargo",[[],[],[],[]]];
{
    private _index = _forEachIndex;
    {
        (_fix select _index) pushBackUnique _x;
    } forEach _x;
} forEach [_fixItems,_fixWeapons,_fixMagazines,_fixBackpacks];
GVAR(curList) = (_fix select 0) + (_fix select 1) + (_fix select 2) + (_fix select 3);
GVAR(curList) = (GVAR(curList) arrayIntersect GVAR(curList)) apply {toLower _x};
[] call FUNC(getFastArsenalList);
_target setVariable ["bis_addVirtualWeaponCargo_cargo",_fix,true];

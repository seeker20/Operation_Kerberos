/*
	Author: Dorbedo
	
	Description:
	
	
*/
#include "script_component.hpp"
SCRIPT(playeraddaction);
[["<t color='#FFFF00'>"+localize "STR_DORB_TFR_SHORT"+"</t>",{[]call FM(ui_tfr_OpenMenu);},[],0.5,false,true,"","alive _target"]] call CBA_fnc_addPlayerAction.sqf;

/*
If ((isClass(configFile >> "CfgPatches" >> "rhsusf_c_weapons"))) then {
	[["<t size='1.5' shadow='2' color='#ffffff'>"+localize "STR_DORB_ARSENAL_OPEN_DESC"+"</t>",{["Open",true] call RHS_fnc_arsenal;},[],4,false,true,"","alive _target and((getposatl player) distance (getposatl base))<50"]] call CBA_fnc_addPlayerAction.sqf;
}else{
	[["<t size='1.5' shadow='2' color='#ffffff'>"+localize "STR_DORB_ARSENAL_OPEN_DESC"+"</t>",{["Open",true] call BIS_fnc_arsenal;},[],4,false,true,"","alive _target and((getposatl player) distance (getposatl base))<50"]] call CBA_fnc_addPlayerAction.sqf;
};
*/
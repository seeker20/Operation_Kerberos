/*
	Author: Dorbedo
	
	Description:
	
	Requirements:
	
	Parameter(s):
		0 : ARRAY	- Example
		1 : ARRAY	- Example
		2 : STRIN	- Example
	
	Return
	BOOL
*/
#include "script_component.hpp"
SCRIPT(stadt_found_intel);
PARAMS_1(_obj);


_obj addAction [localize "STR_DORB_INTEL_GRAB", 
	{
		deleteVehicle (_this select 0);
		[-1,{[_this select 0,format[localize (_this select 1),_this select 2]] spawn EFUNC(interface,disp_message);},["STR_DORB_INTEL_TASK","STR_DORB_INTEL_FOUND",name player]] FMP;
	},[], 2, true, true, "",""];
#include "script_component.hpp"

ADDON = false;

RECOMPILE_START;

#include "XEH_PREP.sqf"

RECOMPILE_END;

ADDON = true;

ISNIL(ship,[]);
ISNIL(default,[]);
ISNIL(air,[]);
ISNIL(infanterie,[]);
ISNIL(pos_ship,[]);
ISNIL(pos_default,[]);
ISNIL(pos_air,[]);
ISNIL(pos_infanterie,[]);
ISNIL(teleport_lead_active,false);

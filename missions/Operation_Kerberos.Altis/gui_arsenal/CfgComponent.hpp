/*
 *  Author: Dorbedo
 *
 *  Description:
 *      the config of the component
 *
 */
#define CBA_OFF
#include "script_component.hpp"

class DOUBLES(CfgComponent,ADDON) {
    version = "2017.08.09";
    class clientpostinit {server = 0;};
    class postinitServer {client = 0;};
    class clientRespawn {server = 0;};
    class preinit {};
    class dependencies {
        CfgPatches[] = {};
        CfgComponents[] = {"common","gui","gui_echidna"};
    };
};
#include "config\arsenal.hpp"
#include "config\dialog.hpp"

#include "script_component.hpp"
class Man {
	class ADDON {
		init = QUOTE(_this call FUNC(addNVG));
	};
};
class rhsusf_M1083A1P2_B_M2_d_Medical_fmtv_usarmy {
	class ADDON {
		init = QUOTE(_this call FUNC(addACEMedicalItems));
	};
};
class rhsusf_M1083A1P2_B_M2_d_MHQ_fmtv_usarmy {
	class ADDON {
		//init = QUOTE(SETPVAR(_this select 0,tf_hasRadio,true));
		init = "(_this select 0) setVariable ['tf_hasRadio',true,true];";
	};
};
class rhs_gaz66_ap2_base {
	class ADDON {
		init = QUOTE(_this call FUNC(addACEMedicalItems));
	};
};
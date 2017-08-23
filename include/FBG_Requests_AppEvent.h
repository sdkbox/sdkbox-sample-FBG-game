#ifndef FBG_APP_EVENTS_H
#define FBG_APP_EVENTS_H

#include "FBG_Types.h"
#include "FBG_FormData.h"
#include "OVR_Platform_Defs.h"

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_LogAppEvent(
	const char* eventName,
	const fbgFormDataHandle formData
);

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_LogAppEventWithValueToSum(
	const char* eventName,
	const fbgFormDataHandle formData,
	float valueToSum
);

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_ActivateApp();
#endif

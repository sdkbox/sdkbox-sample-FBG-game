#ifndef FBG_REQUESTS_OVRACCESSTOKEN_H
#define FBG_REQUESTS_OVRACCESSTOKEN_H

#include "FBG_Types.h"
#include "OVR_Platform_Defs.h"

// Asynchronously request an access token that can be used to 
// initialize the Oculus platform
OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_FetchOVRAccessToken();

#endif

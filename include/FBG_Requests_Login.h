#ifndef FBG_REQUESTS_LOGIN_H
#define FBG_REQUESTS_LOGIN_H

#include "FBG_Types.h"
#include "OVR_Platform_Defs.h"

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_Login();

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_Login_WithScopes(
  uint32_t scopeCount,
  fbgLoginScope* loginScopes
);

#endif

#ifndef FBG_LOGIN_SCOPES
#define FBG_LOGIN_SCOPES

#include "OVR_Platform_Defs.h"

typedef enum _fbgLoginScope {
  public_profile,
  email,
  user_friends,
  publish_actions,
  unknown
} fbgLoginScope;

OVRP_PUBLIC_FUNCTION(const char *) fbgLoginScope_ToString(fbgLoginScope loginScope);

#endif

#ifndef FBG_ACCESS_TOKEN_H
#define FBG_ACCESS_TOKEN_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"
#include <stddef.h>

typedef struct fbgAccessToken *fbgAccessTokenHandle;

OVRP_PUBLIC_FUNCTION(fbgAccessTokenHandle) fbg_AccessToken_GetActiveAccessToken();

OVRP_PUBLIC_FUNCTION(bool) fbg_AccessToken_IsValid(const fbgAccessTokenHandle obj);

OVRP_PUBLIC_FUNCTION(fbid) fbg_AccessToken_GetUserID(const fbgAccessTokenHandle obj);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_AccessToken_GetTokenString(const fbgAccessTokenHandle obj, char* buffer, size_t bufferIn);

OVRP_PUBLIC_FUNCTION(uint64_t) fbg_AccessToken_GetExpirationTimestamp(const fbgAccessTokenHandle obj);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_AccessToken_GetPermissions(const fbgAccessTokenHandle obj, fbgLoginScope* buffer, size_t bufferIn);

#endif

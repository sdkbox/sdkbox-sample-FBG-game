#ifndef FBG_OVR_ACCESSTOKEN_H
#define FBG_OVR_ACCESSTOKEN_H

#include "FBG_OCSdkAccountType.h"
#include "OVR_Platform_Defs.h"

typedef struct fbgOVRAccessToken *fbgOVRAccessTokenHandle;

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_OVRAccessToken_GetTokenString(
	const fbgOVRAccessTokenHandle obj,
	char *buffer,
	size_t bufferIn
);

// Returns the number of accounts owned by the logged in user.
OVRP_PUBLIC_FUNCTION(size_t) fbg_OVRAccessToken_GetNumberOfAccounts(
	const fbgOVRAccessTokenHandle obj
);

OVRP_PUBLIC_FUNCTION(OCSdkAccountType) fbg_OVRAccessToken_GetAccountType(
	const fbgOVRAccessTokenHandle obj,
	size_t accountIndex
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_OVRAccessToken_GetAccountID(
	const fbgOVRAccessTokenHandle obj,
	size_t accountIndex,
	char *buffer,
	size_t bufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_OVRAccessToken_GetAccountAccessTokenString(
	const fbgOVRAccessTokenHandle obj,
	size_t accountIndex,
	char *buffer,
	size_t bufferIn
);

#endif

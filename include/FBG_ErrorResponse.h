#ifndef FBG_ERROR_RESPONSE_H
#define FBG_ERROR_RESPONSE_H

#include "OVR_Platform_Defs.h"

typedef struct fbgResponse *fbgResponseHandle;

OVRP_PUBLIC_FUNCTION(bool) fbg_Error_IsResponseError(const fbgResponseHandle obj);
OVRPL_PUBLIC_FUNCTION(bool) fbg_Error_IsResponseCancelled(const fbgResponseHandle obj);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
// Provides a string representing the error that occured or
// an empty string if no error occured
OVRP_PUBLIC_FUNCTION(size_t) fbg_Error_GetErrorMessage(const fbgResponseHandle obj, char *buffer, size_t bufferIn);

#endif

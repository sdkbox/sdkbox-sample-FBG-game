#ifndef FBG_APP_REQUEST_H
#define FBG_APP_REQUEST_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"
#include <stddef.h>

typedef struct fbgAppRequest *fbgAppRequestHandle;

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_AppRequest_GetRequestObjectId(
  const fbgAppRequestHandle obj,
  char *buffer,
  size_t bufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_AppRequest_GetTo(
  const fbgAppRequestHandle obj,
  char *buffer,
  size_t bufferIn
);

// Usable only if fbg_AppRequestWithPreSendCallback was called.
// This will cause the app request to actually be sent.
OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_AppRequest_Send(
	const fbgAppRequestHandle obj
);

// Returns true if the App Request was sent with fbg_AppRequestWithPreSendCallback()
// and fbg_AppRequest_Send has not already been called on this App Request
OVRP_PUBLIC_FUNCTION(bool) fbg_AppRequest_HasBeenSent(
	const fbgAppRequestHandle obj
);

#endif

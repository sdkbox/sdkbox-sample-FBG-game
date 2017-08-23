#ifndef FBG_APP_REQUEST_RECIPIENT_H
#define FBG_APP_REQUEST_RECIPIENT_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"

// Returns the number of app requests the player launched the game with.
OVRP_PUBLIC_FUNCTION(uint32_t) fbg_AppRequestRecipient_GetNumberRequestIDs();

// Returns 0 if an invalid index is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
// Places the app request received when the player launched the game
// from the specified index in the provided buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_AppRequestRecipient_GetRequestIDAtIndex(
	char* buffer,
	size_t bufferIn,
	uint32_t index
);

#endif
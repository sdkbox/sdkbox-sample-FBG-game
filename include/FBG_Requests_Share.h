#ifndef FBG_REQUESTS_SHARE_H
#define FBG_REQUESTS_SHARE_H

#include "FBG_Types.h"
#include "OVR_Platform_Defs.h"

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_FeedShare(
  const char* toId,
  const char* link,
  const char* linkName,
  const char* linkCaption,
  const char* linkDescription,
  const char* pictureLink,
  const char* mediaSource
);

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_AppRequest(
  const char* message,
  const char* actionType,
  const char* objectId,
  const char* to,
  const char* filters,
  const char* excludeIDs,
  uint32_t maxRecipients,
  const char* data,
  const char* title
);

// Use to perform operations after the user selects friends to send
// app request to and before the app requests are actually sent.
// This will have a response of fbgMessage_AppRequest placed in the queue 
// once the user interacts with the dialog. If the user did not cancel the
// request, the app request can then be sent with fbg_AppRequest_Send()
OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_AppRequestWithPreSendCallback(
	const char* message,
	const char* actionType,
	const char* objectId,
	const char* to,
	const char* filters,
	const char* excludeIDs,
	uint32_t maxRecipients,
	const char* data,
	const char* title
);

#endif

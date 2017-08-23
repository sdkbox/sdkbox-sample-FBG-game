#ifndef FBG_MESSAGETYPE_H
#define FBG_MESSAGETYPE_H

#include "OVR_Platform_Defs.h"

typedef enum fbgMessageType_ {
  fbgMessage_Unknown,
  fbgMessage_AccessToken,
  fbgMessage_FeedShare,
  fbgMessage_Purchase,
  fbgMessage_HasLicense,
  fbgMessage_AppRequest,
	fbgMessage_OVRAccessToken,
} fbgMessageType;

OVRPL_PUBLIC_FUNCTION(const char*) fbgMessageType_ToString(
  fbgMessageType value
);

#endif

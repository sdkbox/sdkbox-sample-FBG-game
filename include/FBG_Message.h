#ifndef FBG_MESSAGE_H
#define FBG_MESSAGE_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"
#include "FBG_AccessToken.h"
#include "FBG_FeedShare.h"
#include "FBG_Purchase.h"
#include "FBG_HasLicense.h"
#include "FBG_AppRequest.h"
#include "FBG_OVRAccessToken.h"
#include <stddef.h>

typedef struct fbgMessage *fbgMessageHandle;

OVRP_PUBLIC_FUNCTION(fbgAccessTokenHandle) fbg_Message_AccessToken(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgFeedShareHandle) fbg_Message_FeedShare(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgPurchaseHandle) fbg_Message_Purchase(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgHasLicenseHandle) fbg_Message_HasLicense(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgAppRequestHandle) fbg_Message_AppRequest(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgOVRAccessTokenHandle) fbg_Message_OVRAccessToken(const fbgMessageHandle obj);
OVRP_PUBLIC_FUNCTION(fbgMessageType) fbg_Message_GetType(const fbgMessageHandle obj);

#endif

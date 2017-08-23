#ifndef FBG_PLATFORM_H
#define FBG_PLATFORM_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "OVR_Platform_Defs.h"
#include "FBG_PlatformInitializeResult.h"
#include "FBG_Types.h"
#include "FBG_AccessToken.h"
#include "FBG_FeedShare.h"
#include "FBG_Purchase.h"
#include "FBG_HasLicense.h"
#include "FBG_MessageType.h"
#include "FBG_AccessToken.h"
#include "FBG_FormData.h"
#include "FBG_OVRAccessToken.h"
#include "FBG_PlatformVersion.h"
#include "FBG_Message.h"
#include "FBG_Requests_Login.h"
#include "FBG_Requests_Share.h"
#include "FBG_Requests_Purchase.h"
#include "FBG_Requests_AppEvent.h"
#include "FBG_Requests_OVRAccessToken.h"
#include "FBG_ErrorResponse.h"
#include "FBG_AppRequestRecipient.h"

OVRP_PUBLIC_FUNCTION(bool) fbg_IsPlatformInitialized();

#if defined(OVRPL_DISABLED)

/// Performs the initialization of the platform for use on Windows. Requires
// your app ID (not access token). This call may fail for a variety of reasons,
// and will return an error code in that case. It is critical to respect this
// error code and either exit or make no further platform calls.
OVRP_PUBLIC_FUNCTION(fbgPlatformInitializeResult) fbg_PlatformInitializeWindows(const char* appId);

#else

/// Performs the initialization of the platform for use on Windows. Requires
// your app ID (not access token). This call may fail for a variety of reasons,
// and will return an error code in that case. It is critical to respect this
// error code and either exit or make no further platform calls.
OVRPL_PUBLIC_FUNCTION(fbgPlatformInitializeResult) fbg_PlatformInitializeWindowsEx(const char* appId, int productVersion, int majorVersion);

/// Wrapper for fbg_PlatformInitializeWindowsEx that automatically passes the
// key version information as defined in this header package. This is used to
// ensure that the version in your headers matches the version of the static
// library.
#define fbg_PlatformInitializeWindows(appId) fbg_PlatformInitializeWindowsEx((appId), FBG_PLATFORM_PRODUCT_VERSION, FBG_PLATFORM_MAJOR_VERSION)

#endif

OVRP_PUBLIC_FUNCTION(bool) fbg_IsLoggedIn();

OVRPL_PUBLIC_FUNCTION(fbgMessageHandle) fbg_PopMessage();
OVRP_PUBLIC_FUNCTION(void) fbg_FreeMessage(fbgMessageHandle);

#endif

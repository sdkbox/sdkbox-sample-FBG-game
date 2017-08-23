#ifndef FBG_PLATFORM_INITIALIZE_RESULT_H
#define FBG_PLATFORM_INITIALIZE_RESULT_H

#include "OVR_Platform_Defs.h"

/// Describes the various results possible when attempting to initialize the
/// platform. Anything other than fbgPlatformInitialize_Success should be
/// considered a fatal error with respect to using the platform, as the
/// platform is not guaranteed to be legitimate or work correctly.
typedef enum fbgPlatformInitializeResult_ {
  fbgPlatformInitialize_Success = 0,
  fbgPlatformInitialize_Uninitialized = -1,
  fbgPlatformInitialize_PreLoaded = -2,
  fbgPlatformInitialize_FileInvalid = -3,
  fbgPlatformInitialize_SignatureInvalid = -4,
  fbgPlatformInitialize_UnableToVerify = -5,
  fbgPlatformInitialize_VersionMismatch = -6,
  fbgPlatformInitialize_Unknown = -7,
  fbgPlatformInitialize_InvalidCredentials = -8,
  fbgPlatformInitialize_NotEntitled = -9,
  fbgPlatformInitialize_InvalidAppID = -10,
  fbgPlatformInitialize_InvalidNamedPipe = -11,
  fbgPlatformInitialize_FailedToEstablishNamedPipeConnection = -12,

} fbgPlatformInitializeResult;

/// Converts an fbgPlatformInitializeResult enum value to a string
/// The returned string does not need to be freed
OVRP_PUBLIC_FUNCTION(const char *)
fbgPlatformInitializeResult_ToString(fbgPlatformInitializeResult value);

// Converts a string representing an fbgPlatformInitializeResult
// enum value to an enum value
OVRP_PUBLIC_FUNCTION(fbgPlatformInitializeResult)
fbgPlatformInitializeResult_FromString(const char *str);

#endif

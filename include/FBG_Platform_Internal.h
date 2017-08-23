#ifndef FBG_PLATFORM_INTERNAL_H
#define FBG_PLATFORM_INTERNAL_H

#include "FBG_Platform.h"
#include "FBG_Types.h"

// Specify a log sink for the platform library.  This function should be called
// before initializing the platform SDK.  The logging sink takes two const char*
// arguments, representing the tag and the message, respectively.
OVRP_PUBLIC_FUNCTION(void) fbg_SetPlatformLogFunc(LogFunctionPtr logFunc);

#endif

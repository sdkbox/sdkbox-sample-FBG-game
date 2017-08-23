// This file was @generated with LibFBGPlatform/codegen/main. Do not modify it!

#ifndef FBG_KEY_VALUE_PAIR_TYPE_H
#define FBG_KEY_VALUE_PAIR_TYPE_H

#include "OVR_Platform_Defs.h"

typedef enum fbgKeyValuePairType_ {
  fbgKeyValuePairType_String,
  fbgKeyValuePairType_Int,
  fbgKeyValuePairType_Double,
  fbgKeyValuePairType_Unknown,
} fbgKeyValuePairType;

/// Converts an fbgKeyValuePairType enum value to a string
/// The returned string does not need to be freed
OVRPL_PUBLIC_FUNCTION(const char*) fbgKeyValuePairType_ToString(fbgKeyValuePairType value);

/// Converts a string representing an fbgKeyValuePairType enum value to an enum value
///
OVRPL_PUBLIC_FUNCTION(fbgKeyValuePairType) fbgKeyValuePairType_FromString(const char* str);

#endif

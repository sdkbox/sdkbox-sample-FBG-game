#ifndef FBG_TYPES_H
#define FBG_TYPES_H

#include "FBG_LoginScopes.h"
#include "FBG_OCSdkAccountType.h"

#include "FBG_KeyValuePairType.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

  /// Represents a single state change in the platform such as the
  /// response to a request, or some new information from the backend.
  typedef uint64_t fbgRequest;

  // Represents an RequestID that can used as a default.
  // We guarantee that no valid Request ID will equal fbgInvalidRequestID
  const uint64_t fbgInvalidRequestID = 0;

  // Represents an invalid MessageID that can used as a default.
  // We guarantee that no valid Message ID will equal fbgInvalidMessageID
  const uint64_t fbgInvalidMessageID = 0;


  /// A unique identifier for some entity in the system (user, room, etc).
  ///
  typedef uint64_t fbid;

  /// Convert a string into an fbgID.  Returns false if the input is
  /// malformed (either out of range, or not an integer).
  bool fbid_FromString(fbid *outId, const char* inId);

  /// Convert an ID back into a string.  This function round trips with
  /// fbgID_FromString().  Note: the id format may change in the future.
  /// Developers should not rely on the string representation being an
  /// integer.
  ///
  /// Length of outParam should be > 20.
  bool fbid_ToString(char *outParam, size_t bufferLength, fbid id);

  typedef void(*LogFunctionPtr)(const char *, const char *);
  extern LogFunctionPtr DoLogging;

#ifdef __cplusplus
}
#endif

#endif

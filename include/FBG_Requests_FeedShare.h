#ifndef FBG_REQUESTS_FEEDSHARE_H
#define FBG_REQUESTS_FEEDSHARE_H

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

#endif

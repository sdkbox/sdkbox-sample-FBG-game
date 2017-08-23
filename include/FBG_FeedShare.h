#ifndef FBG_FEEDSHARE_H
#define FBG_FEEDSHARE_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"
#include <stddef.h>

typedef struct fbgFeedShare *fbgFeedShareHandle;

OVRP_PUBLIC_FUNCTION(fbid) fbg_FeedShare_GetPostID(
  const fbgFeedShareHandle obj
);

#endif

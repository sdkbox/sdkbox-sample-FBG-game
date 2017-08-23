#ifndef FBG_HAS_LICENSE_H
#define FBG_HAS_LICENSE_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"
#include <stddef.h>

typedef struct fbgHasLicense *fbgHasLicenseHandle;

OVRP_PUBLIC_FUNCTION(fbid) fbg_HasLicense_GetHasLicense(const fbgHasLicenseHandle obj);

#endif

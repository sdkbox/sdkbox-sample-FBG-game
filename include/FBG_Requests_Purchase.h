#ifndef FBG_REQUESTS_PAY_H
#define FBG_REQUESTS_PAY_H

#include "FBG_Types.h"
#include "OVR_Platform_Defs.h"

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_PurchaseIAP(
  const char* product,
  uint32_t quantity,
  uint32_t quantityMin,
  uint32_t quantityMax,
  const char* requestId,
  const char* pricePointId,
  const char* testCurrency
);

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_PurchaseIAPWithProductURL(
  const char* product,
  uint32_t quantity,
  uint32_t quantityMin,
  uint32_t quantityMax,
  const char* requestId,
  const char* pricePointId,
  const char* testCurrency
);

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_PayPremium();

OVRP_PUBLIC_FUNCTION(fbgRequest) fbg_HasLicense();

#endif

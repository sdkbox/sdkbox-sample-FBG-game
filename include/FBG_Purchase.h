#ifndef FBG_PAY_H
#define FBG_PAY_H

#include "OVR_Platform_Defs.h"
#include "FBG_Types.h"

typedef struct fbgPurchase *fbgPurchaseHandle;

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetPaymentID(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

OVRP_PUBLIC_FUNCTION(uint32_t) fbg_Purchase_GetAmount(
  const fbgPurchaseHandle obj
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetCurrency(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

OVRP_PUBLIC_FUNCTION(uint64_t) fbg_Purchase_GetPurchaseTime(
  const fbgPurchaseHandle obj
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetProductId(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetPurchaseToken(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

OVRP_PUBLIC_FUNCTION(uint32_t) fbg_Purchase_GetQuantity(
  const fbgPurchaseHandle obj
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetRequestId(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetStatus(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetSignedRequest(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

OVRP_PUBLIC_FUNCTION(uint64_t) fbg_Purchase_GetErrorCode(
  const fbgPurchaseHandle obj
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
OVRP_PUBLIC_FUNCTION(size_t) fbg_Purchase_GetErrorMessage(
  const fbgPurchaseHandle obj,
  char* buffer,
  size_t bufferIn
);

#endif

#ifndef FBG_FORM_DATA_H
#define FBG_FORM_DATA_H

#include "OVR_Platform_Defs.h"

typedef struct fbgFormData *fbgFormDataHandle;

// Creates a new form data structure and returns a handle to the structure
// This will need to be disposed explicitly using fbg_FormData_Dispose()
OVRP_PUBLIC_FUNCTION(const fbgFormDataHandle) fbg_FormData_CreateNew();

// Sets a key/value pair in the provided fbgFormDataHandle
OVRP_PUBLIC_FUNCTION(void) fbg_FormData_Set(
	const fbgFormDataHandle obj,
	char *fieldNameBuffer,
	size_t fieldNameBufferIn,
	char *valueBuffer,
	size_t valueBufferIn
);

// Returns 0 if an invalid handle is provided.
// If provided buffer size is not large enough returns
// buffer size necessary.
// Otherwise returns the size written to the buffer.
// Writes the value of the form data if it exists to the value buffer	
OVRP_PUBLIC_FUNCTION(size_t) fbg_FormData_Get(
	const fbgFormDataHandle obj,
	char *fieldNameBuffer,
	size_t fieldNameBufferIn,
	char *valueBuffer,
	size_t valueBufferIn
);

// Deletes a key from the provided fbgFormDataHandle
OVRP_PUBLIC_FUNCTION(void) fbg_FormData_Delete(
	const fbgFormDataHandle obj,
	char *fieldNameBuffer,
	size_t fieldNameBufferIn
);

// Returns true if the form data structure contains the key passed in
// otherwise returns false
OVRP_PUBLIC_FUNCTION(bool) fbg_FormData_Has(
	const fbgFormDataHandle obj,
	char *fieldNameBuffer,
	size_t fieldNameBufferIn
);

// Frees the memory allocated to the provided fbgFormDataHandle
OVRP_PUBLIC_FUNCTION(void) fbg_FormData_Dispose(
	const fbgFormDataHandle obj
);

#endif
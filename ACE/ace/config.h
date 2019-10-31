#define ACE_HAS_IPV6 1
#define ACE_HAS_CPP11
#define ACE_LACKS_SYSTEM 1 // removed in Xcode 9
#include "config-macosx-iOS-hardware.h"

// some idiotic defines config-macosx-leopard.h that are incompatible
// with Xcode 10.3
#undef ACE_LACKS_CLOCKID_T
#undef ACE_LACKS_CLOCK_MONOTONIC
#undef ACE_LACKS_CLOCK_REALTIME

#define ACE_AS_STATIC_LIBS 1
#define ACE_HAS_IPV6 1
#define ACE_LACKS_GETIPNODEBYADDR 1 /* missing in android netdb.h */
#define ACE_LACKS_GETIPNODEBYNAME_IPV6 1
#define ACE_HAS_CPP11
#include "config-android.h"
#undef ACE_LACKS_FD_MASK

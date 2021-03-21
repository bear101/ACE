shared_libs=0
static_libs_only=1
ssl=1
ipv6=1
c++11=1

CPPFLAGS+=-isysroot $(SDK) -mmacosx-version-min=10.9
LDFLAGS+=-isysroot $(SDK) -mmacosx-version-min=10.9

SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE
include $(ACE_ROOT)/include/makeinclude/platform_macosx_mojave.GNU

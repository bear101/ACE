shared_libs=0
static_libs_only=1
ssl=1
ipv6=1

CPPFLAGS+=-isysroot $(SDK) -mmacosx-version-min=10.4
LDFLAGS+=-isysroot $(SDK) -mmacosx-version-min=10.4

INSTALL_PREFIX=/Users/bdr/libraries/ACE
include $(ACE_ROOT)/include/makeinclude/platform_macosx_mountainlion.GNU

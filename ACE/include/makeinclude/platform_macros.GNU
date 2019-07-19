shared_libs=0
static_libs=1
ssl=1
ipv6=1
c++11=1

#enable on x86_64
CPPFLAGS+=-fPIC -DPIC
LDFLAGS+=-fPIC

INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE
include $(ACE_ROOT)/include/makeinclude/platform_linux.GNU

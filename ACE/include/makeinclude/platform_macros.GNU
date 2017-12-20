shared_libs=0
static_libs=1
ssl=1
ipv6=1
c++11=1

#enable on x86_64
CPPFLAGS+=-fPIC -DPIC
LDFLAGS+=-fPIC

# CPPFLAGS += -DOPENSSL_NO_SSL2=1
SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE
include $(ACE_ROOT)/include/makeinclude/platform_linux.GNU

shared_libs=0
static_libs=1
static_libs_only=1
ssl=1
c++11=1

CPPFLAGS += -D__ANDROID_API__=21

CPPFLAGS+=-fPIC -DPIC
LDFLAGS+=-fPIC

SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE

include $(ACE_ROOT)/include/makeinclude/platform_android.GNU

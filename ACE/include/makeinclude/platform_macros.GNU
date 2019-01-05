ssl=1
c++11=1

# CPPFLAGS += -DOPENSSL_NO_SSL2=1
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE
SSL_ROOT=$(TTLIBS_ROOT)/openssl
include $(ACE_ROOT)/include/makeinclude/platform_macosx_iOS.GNU


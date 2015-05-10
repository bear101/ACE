ssl=1
CPPFLAGS += -DOPENSSL_NO_SSL2=1
INSTALL_PREFIX=/Users/bdr/libraries/ios/arm64/ACE
SSL_ROOT=/Users/bdr/libraries/ios/arm64/openssl
include $(ACE_ROOT)/include/makeinclude/platform_macosx_iOS.GNU


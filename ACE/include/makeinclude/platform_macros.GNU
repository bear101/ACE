# Create toolchain from Android NDK
#
# unzip android-ndk-r17-darwin-x86_64.zip into LIBS
#
# $ build/tools/make_standalone_toolchain.py --arch arm64 --api 24 --stl gnustl --install-dir $LIBS/toolchain-aarch64-linux-android
# Android API < 24 doesn't have stderr and inaddr6_any defined
#

shared_libs=0
static_libs_only=1
ssl=1
c++11=1

SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE

include $(ACE_ROOT)/include/makeinclude/platform_android.GNU



# Create toolchain from Android NDK
#
# unzip android-ndk-r17-darwin-x86_64.zip into LIBS
#
# $ build/tools/make_standalone_toolchain.py --arch x86 --api 24 --stl gnustl --install-dir $LIBS/toolchain-i686-linux-android
# Android API < 24 doesn't have stderr and inaddr6_any defined
#

# $ export NDK=$LIBS/android-ndk-r17
# $ export ANDROID_ABI=x86
# $ export ANDROID_ARCH=x86
# $ export ARCH=$ANDROID_ARCH
# $ export PATH=$LIBS/toolchain-i686-linux-android/bin:$PATH

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

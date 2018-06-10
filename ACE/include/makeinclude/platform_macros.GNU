# create toolchain from Android NDK
# $ make-standalone-toolchain.sh --toolchain=aarch64-linux-android-4.9 --platform=android-21 --install-dir=toolchain-aarch64-linux-android-4.9 --arch=arm64

# $ cd toolchain-aarch64-linux-android-4.9
# $ export TOOLCHAIN=$PWD
# $ export PATH=$TOOLCHAIN/bin:$PATH
# $ export SYSROOT=$TOOLCHAIN/sysroot
# $ export ANDROID_ARCH=arm64
# $ export NDK=??

shared_libs=0
static_libs_only=1
ssl=1

SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE

include $(ACE_ROOT)/include/makeinclude/platform_android.GNU

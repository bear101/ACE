# create toolchain from Android NDK
# $ make-standalone-toolchain.sh --toolchain=aarch64-linux-android-4.9 --platform=android-21 --install-dir=toolchain-aarch64-linux-android-4.9 --arch=arm64

# $ cd toolchain-aarch64-linux-android-4.9
# $ export TOOLCHAIN=$PWD
# $ export PATH=$TOOLCHAIN/bin:$PATH
# $ export SYSROOT=$TOOLCHAIN/sysroot
# $ export ANDROID_ARCH=arm64
# $ export NDK=??

ANDROID_ARCH=arm64

shared_libs=0
static_libs_only=1
ssl=1

CPPFLAGS += -DOPENSSL_NO_SSL2=1

SSL_ROOT=/Users/bdr/libraries/android/arm64-v8a/openssl
INSTALL_PREFIX=/Users/bdr/libraries/android/arm64-v8a/ACE

CPPFLAGS += -DACE_HAS_UCONTEXT_T -D__cpu_set_t_defined -DACE_HAS_CPU_SET_T

include $(ACE_ROOT)/include/makeinclude/platform_android.GNU

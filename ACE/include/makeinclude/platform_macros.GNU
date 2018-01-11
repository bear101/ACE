
#from NDK
# $ make-standalone-toolchain.sh --toolchain=arm-linux-androideabi-4.8 --ndk-dir=/Users/bdr/libraries/android/android-ndk-r10 --platform=android-14 --install-dir=toolchain-arm-linux-androideabi-4.8

shared_libs=0
static_libs_only=1
ssl=1
c++11=1

CPPFLAGS += -DOPENSSL_NO_SSL2=1

SSL_ROOT=$(TTLIBS_ROOT)/openssl
INSTALL_PREFIX=$(TTLIBS_ROOT)/ACE

include $(ACE_ROOT)/include/makeinclude/platform_android.GNU



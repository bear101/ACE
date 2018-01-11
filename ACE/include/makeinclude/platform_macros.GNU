shared_libs=0
static_libs_only=1
ssl=1
ipv6=1

SSL_ROOT=$(SSL_ROOT)
CPPFLAGS += $(SSL_ROOT)/win32/include

include $(ACE_ROOT)/include/makeinclude/platform_win32_msvc.GNU

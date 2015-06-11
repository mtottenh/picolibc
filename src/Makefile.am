lib_LIBRARIES = libplibc.a

libplibc_a_SOURCES = io.c mem.c string.c
libplibc_a_CFLAGS = -nostdlib -I $(top_srcdir)/include 

if CPU_x86_64
libplibc_a_CFLAGS += -I $(top_srcdir)/arch/x86_64
endif

if CPU_i386
libplibc_a_CFLAGS += -I $(top_srcdir)/arch/i386
endif

if CPU_UNDEF
libplibc_a_CFLAGS += -I $(top_srcdir)/arch/generic
endif


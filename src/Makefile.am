lib_LIBRARIES = $(top_builddir)/lib/libplibc.a

__top_builddir__lib_libplibc_a_SOURCES = io.c mem.c string.c internal/syscall.c
__top_builddir__lib_libplibc_a_CFLAGS  = -nostdlib -std=c99 -Wall -Werror
__top_builddir__lib_libplibc_a_CFLAGS += -I $(top_srcdir)/include -I $(top_srcdir)/src/internal

if CPU_x86_64
__top_builddir__lib_libplibc_a_CFLAGS += -I $(top_srcdir)/arch/x86_64
endif

if CPU_i386
__top_builddir__lib_libplibc_a_CFLAGS += -I $(top_srcdir)/arch/i386
endif

if CPU_UNDEF
__top_builddir__lib_libplibc_a_CFLAGS += -I $(top_srcdir)/arch/generic
endif


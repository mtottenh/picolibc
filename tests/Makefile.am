TESTS = check_printf
noinst_PROGRAMS = $(top_builddir)/tests/check_printf
__top_builddir__tests_check_printf_SOURCES = printf.c $(top_srcdir)/src/asm/start.S
__top_builddir__tests_check_printf_CFLAGS  = -nostdlib -std=c99 
__top_builddir__tests_check_printf_CFLAGS += -I $(top_srcdir)/include
__top_builddir__tests_check_printf_LDADD = $(top_builddir)/lib/libplibc.a

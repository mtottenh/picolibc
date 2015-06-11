AC_INIT(picolibc,1.0,mtottenh@gmail.com)

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(src/io.c)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AS

PROC=""
# Set up our target architecture conditionals
AS_CASE([$host_cpu], 
        [x86_64], [PROC="x86_64"], 
        [i386], [PROC="i386"])

AM_CONDITIONAL([CPU_x86_64], [test "$PROC" = "x86_64"])
AM_CONDITIONAL([CPU_i386], [test "$PROC" = "i386"])
AM_CONDITIONAL([CPU_UNDEF], [test "x$PROC" = "x"])

AC_OUTPUT(Makefile
          src/Makefile
          tests/Makefile)

dnl Process this file with autoconf to produce a configure script.
AC_INIT([cyrus-timezones],[1.0])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE
AC_CONFIG_MACRO_DIR([m4])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
LT_INIT

dnl Checks for headers
dnl AC_FUNC_ALLOCA
dnl AC_HEADER_STDC
dnl AC_CHECK_HEADERS([inttypes.h limits.h stdlib.h string.h sys/time.h])

dnl Checks for typedefs, structures, and compiler characteristics.
dnl AC_C_CONST
dnl AC_C_INLINE
dnl AC_TYPE_SIZE_T
dnl AC_HEADER_TIME
dnl AC_STRUCT_TM

dnl Checks for functions
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
dnl AC_FUNC_VPRINTF
dnl AC_CHECK_FUNCS([gettimeofday memset strchr strdup strpbrk])

dnl Checks for required libraries
PKG_CHECK_MODULES([ICAL], [libical])
AC_SUBST([ICAL_LIBS])
AC_SUBST([ICAL_CFLAGS])
PKG_CHECK_VAR([ICAL_LIBDIR], [libical], [libdir])

PKG_CHECK_MODULES([GLIB], [glib-2.0])
AC_SUBST([GLIB_LIBS])
AC_SUBST([GLIB_CFLAGS])
PKG_CHECK_VAR([GLIB_LIBDIR], [glib-2.0], [libdir])

PKG_CHECK_MODULES([JANSSON], [jansson])
AC_SUBST([JANSSON_LIBS])
AC_SUBST([JANSSON_CFLAGS])
PKG_CHECK_VAR([JANSSON_LIBDIR], [jansson], [libdir])

AC_CONFIG_FILES([cyrus-timezones.pc:cyrus-timezones.pc.in])
AC_CONFIG_FILES([guesstz.pc:guesstz.pc.in])
AC_CONFIG_FILES([Makefile guesstz/Makefile])
AC_OUTPUT

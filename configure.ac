#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([trace-wrappers], [0.4], [Stanislav Brabec <sbrabec@suse.cz>])
AC_CONFIG_SRCDIR([dlwrap.h])
AC_CONFIG_MACRO_DIR([m4])
AM_DISABLE_STATIC
AM_INIT_AUTOMAKE([-Wall dist-bzip2])
AM_MAINTAINER_MODE

# Checks for programs.
dnl We need C compiler.
AC_PROG_CC
dnl Required by ltlibrary.am.
AM_PROG_AR

dnl We build a library, we need libtool.
LT_INIT

# Checks for libraries.
AC_CHECK_LIB([dl], [dlsym])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

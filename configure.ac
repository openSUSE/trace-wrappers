#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([trace-wrappers], [0.4.1], [Stanislav Brabec <sbrabec@suse.cz>])
AC_CONFIG_SRCDIR([wrap-getenv.c])
AC_CONFIG_MACRO_DIR([m4])
AM_DISABLE_STATIC
AM_INIT_AUTOMAKE([-Wall dist-bzip2 no-dist-gzip])
AM_MAINTAINER_MODE
AC_GNU_SOURCE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AR
LT_INIT

# Checks for libraries.
AC_CHECK_LIB([dl], [dlsym])

# Checks for header files.
AC_CHECK_HEADERS([locale.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for header files.
AC_CHECK_HEADERS([locale.h])
AC_CHECK_HEADERS([dlwrap/dlwrap.h],,[
	AC_MSG_ERROR([You need dlwrap header files.])
])

# TODO: Create output file support.
AC_DEFINE([dlwrap_file], [stderr], [For now, write everything to stderr.])
# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

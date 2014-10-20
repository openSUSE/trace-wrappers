dlwrap_HEADERS = \
	dlwrap.h \
	printf.h

dlwrapdir = $(includedir)/dlwrap

pkglib_LTLIBRARIES = \
	wrap-alloc.la \
	wrap-getenv.la \
	wrap-gettext.la

bin_SCRIPTS = \
	wrap-alloc \
	wrap-getenv \
	wrap-gettext

$(bin_SCRIPTS): Makefile.am
	for SCRIPT in $(bin_SCRIPTS) ; do \
		echo -e "#!/bin/sh\nLD_PRELOAD=$(pkglibdir)/$$SCRIPT.so \"\$$@\"" >$$SCRIPT ; \
	done

DISTCLEANFILES = $(bin_SCRIPTS)

wrap_alloc_la_LIBADD = -ldl
wrap_alloc_la_LDFLAGS = -avoid-version -module -no-undefined

wrap_getenv_la_LIBADD = -ldl
wrap_getenv_la_LDFLAGS = -avoid-version -module -no-undefined

wrap_gettext_la_LIBADD = -ldl
wrap_gettext_la_LDFLAGS = -avoid-version -module -no-undefined

ACLOCAL_AMFLAGS = -I m4

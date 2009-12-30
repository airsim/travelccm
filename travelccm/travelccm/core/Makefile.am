include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

## Source directory

MAINTAINERCLEANFILES = Makefile.in

SUBDIRS =


# Library
lib_LTLIBRARIES = libtravelccm.la

libtravelccm_la_SOURCES = $(service_h_sources) $(service_cc_sources)
libtravelccm_la_LIBADD = \
	$(top_builddir)/travelccm/basic/libbas.la \
	$(top_builddir)/travelccm/bom/libbom.la \
	$(top_builddir)/travelccm/factory/libfac.la \
	$(top_builddir)/travelccm/command/libcmd.la \
	$(top_builddir)/travelccm/service/libsvc.la
libtravelccm_la_LDFLAGS = \
	$(BOOST_DATE_TIME_LIB) $(BOOST_PROGRAM_OPTIONS_LIB) \
	-version-info $(GENERIC_LIBRARY_VERSION)

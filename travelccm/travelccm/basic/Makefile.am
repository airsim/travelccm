## basic sub-directory
include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

noinst_LTLIBRARIES= libbas.la

libbas_la_SOURCES= $(bas_h_sources) $(bas_cc_sources) 
libbas_la_CXXFLAGS = $(BOOST_CFLAGS)

# Headers to be exported/installed
#pkgincludedir = $(includedir)/travelccm/basic
#pkginclude_HEADERS = $(bas_h_sources)

# travelccm/batches sub-directory
include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

## Source directory

MAINTAINERCLEANFILES = Makefile.in


# Binaries (batches)
bin_PROGRAMS = travelccm

travelccm_SOURCES = $(batches_h_sources) $(batches_cc_sources)
travelccm_CXXFLAGS = $(BOOST_CFLAGS)
#travelccm_LDADD = 
travelccm_LDFLAGS = $(BOOST_PROGRAM_OPTIONS_LIB) \
	$(top_builddir)/travelccm/core/libtravelccm.la

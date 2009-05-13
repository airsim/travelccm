include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

## Source directory

MAINTAINERCLEANFILES = Makefile.in


# Binaries (batches)
bin_PROGRAMS = travel-ccm

travel_ccm_SOURCES = $(batches_h_sources) $(batches_cc_sources)
travel_ccm_CXXFLAGS = $(BOOST_CFLAGS)
#travel_ccm_LDADD = 
travel_ccm_LDFLAGS = $(BOOST_PROGRAM_OPTIONS_LIB) \
	$(top_builddir)/@PACKAGE@/core/lib@PACKAGE@.la

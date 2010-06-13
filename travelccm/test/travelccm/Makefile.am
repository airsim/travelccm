## test/travelccm sub-directory
include $(top_srcdir)/Makefile.common

MAINTAINERCLEANFILES = Makefile.in

##
SUBDIRS =

EXTRA_DIST =
##

check_PROGRAMS = TravelChoiceTestSuite
TESTS = $(check_PROGRAMS)
XFAIL_TESTS = #TravelChoiceTestSuite

TravelChoiceTestSuite_SOURCES = TravelChoiceTestSuite.hpp \
								 TravelChoiceTestSuite.cpp
TravelChoiceTestSuite_CXXFLAGS= $(BOOST_CFLAGS) $(CPPUNIT_CFLAGS)
TravelChoiceTestSuite_LDADD = 
TravelChoiceTestSuite_LDFLAGS = $(BOOST_LIBS) $(CPPUNIT_LIBS) \
	$(top_builddir)/extracppunit/libextracppunit.la \
	$(top_builddir)/stdair/core/libstdair.la \
	$(top_builddir)/travelccm/core/libtravelccm.la


## test sub-directory
include $(top_srcdir)/Makefile.common

MAINTAINERCLEANFILES = Makefile.in

##
SUBDIRS = com

EXTRA_DIST =
##

check_PROGRAMS = TravelChoiceTestSuite
TESTS = $(check_PROGRAMS)
XFAIL_TESTS = #IndexBuildingTestSuite

TravelChoiceTestSuite_SOURCES = TravelChoiceTestSuite.hpp TravelChoiceTestSuite.cpp
TravelChoiceTestSuite_CXXFLAGS= $(BOOST_CFLAGS) $(CPPUNIT_CFLAGS)
TravelChoiceTestSuite_LDADD = 
TravelChoiceTestSuite_LDFLAGS = $(BOOST_LIBS) $(CPPUNIT_LIBS) \
	$(top_builddir)/test/com/libcppunitcore.la \
	$(top_builddir)/@PACKAGE@/core/lib@PACKAGE@.la


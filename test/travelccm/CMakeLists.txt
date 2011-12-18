#
# TravelCCM Tests
#

##
# Specify each test suite configuration

# * TravelChoiceTestSuite Test Suite
module_test_add_suite (travelccm TravelChoiceTestSuite TravelChoiceTestSuite.cpp)


##
# Register all the test suites to be built and performed
module_test_build_all ()


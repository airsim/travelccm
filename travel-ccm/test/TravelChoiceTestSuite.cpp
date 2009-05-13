// STL
#include <iostream>
#include <string>
// CPPUNIT
#include <test/com/CppUnitCore.hpp>
// TRAVEL-CCM
#include <travel-ccm/TRAVEL_CCM_Service.hpp>
// TRAVEL-CCM Test Suite
#include <test/TravelChoiceTestSuite.hpp>

// //////////////////////////////////////////////////////////////////////
void testTravelChoiceHelper() {

  try {
    
    // Output log File
    std::string lLogFilename ("TravelChoiceTestSuite.log");
    
    // Number of random draws to be generated (best if greater than 100)
    // const int K = 100000;
    
    // Input file name
    // const std::string inputFileName ("samples/sample2.csv");
    // const bool hasInputFile = true;
    
    // Set the log parameters
    std::ofstream logOutputFile;
    // open and clean the log outputfile
    logOutputFile.open (lLogFilename.c_str());
    logOutputFile.clear();
    
    // Initialise the list of classes/buckets
    // TRAVEL_CCM::TRAVEL_CCM_Service travel_ccmService (logOutputFile);
    
  } catch (const std::exception& stde) {
    std::cerr << "Standard exception: " << stde.what() << std::endl;
    
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }
}

// //////////////////////////////////////////////////////////////////////
void TravelChoiceTestSuite::testTravelChoice() {
  CPPUNIT_ASSERT_NO_THROW (testTravelChoiceHelper(););
}

// //////////////////////////////////////////////////////////////////////
// void TravelChoiceTestSuite::errorCase () {
//  CPPUNIT_ASSERT (false);
// }

// //////////////////////////////////////////////////////////////////////
TravelChoiceTestSuite::TravelChoiceTestSuite () {
  _describeKey << "Running test on TRAVEL-CCM Optimisation function";  
}

// /////////////// M A I N /////////////////
CPPUNIT_MAIN()

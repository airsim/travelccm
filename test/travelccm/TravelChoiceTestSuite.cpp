/*!
 * \page TravelChoiceTestSuite_cpp Command-Line Test to Demonstrate How To Test the Travel CCM Project
 * \code
 */
// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <sstream>
#include <fstream>
#include <string>
// Boost Unit Test Framework (UTF)
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TravelCCMTest
#include <boost/test/unit_test.hpp>
#include <boost/version.hpp>
// StdAir
#include <stdair/basic/BasLogParams.hpp>
#include <stdair/basic/BasDBParams.hpp>
#include <stdair/basic/BasFileMgr.hpp>
#include <stdair/basic/PassengerChoiceModel.hpp>
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
#include <stdair/service/Logger.hpp>
// TravelCCM
#include <travelccm/TRAVELCCM_Service.hpp>
#include <travelccm/config/travelccm-paths.hpp>

namespace boost_utf = boost::unit_test;

// (Boost) Unit Test XML Report
std::ofstream utfReportStream ("TravelChoiceTestSuite_utfresults.xml");

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    boost_utf::unit_test_log.set_stream (utfReportStream);
#if BOOST_VERSION >= 105900
    boost_utf::unit_test_log.set_format (boost_utf::OF_XML);
#else
    boost_utf::unit_test_log.set_format (boost_utf::XML);
#endif
    boost_utf::unit_test_log.set_threshold_level (boost_utf::log_test_units);
    //boost_utf::unit_test_log.set_threshold_level (boost_utf::log_successful_tests);
  }
  /** Destructor. */
  ~UnitTestConfig() {
  }
};

// //////////////////////////////////////////////////////////////////////
/**
 * Choose a fare option among the list of travel solutions
 */
void testTravelCCMHelper (const unsigned short iTestFlag,
                          const stdair::PassengerChoiceModel::EN_PassengerChoiceModel& iPassengerChoiceModel,
                          const unsigned int iExpectedPrice) {

  // Output log File
  std::ostringstream oStr;
  oStr << "TravelChoiceTestSuite_" << iTestFlag << ".log";
  const stdair::Filename_T lLogFilename (oStr.str());
    
  // Set the log parameters
  std::ofstream logOutputFile;
  // Open and clean the log outputfile
  logOutputFile.open (lLogFilename.c_str());
  logOutputFile.clear();
  
  // Initialise the service context
  const stdair::BasLogParams lLogParams (stdair::LOG::DEBUG, logOutputFile);
  
  // Build the BOM tree
  TRAVELCCM::TRAVELCCM_Service travelccmService (lLogParams);
  travelccmService.buildSampleBom ();

  // DEBUG
  STDAIR_LOG_DEBUG ("Welcome to TravelCCM");

  // Build a list of travel solutions
  const stdair::BookingRequestStruct& lBookingRequest =
    travelccmService.buildSampleBookingRequest();

  // DEBUG
  STDAIR_LOG_DEBUG ("Booking request: " << lBookingRequest.display());

  // Build the sample BOM tree
  stdair::TravelSolutionList_T lTSList;
  travelccmService.buildSampleTravelSolutions (lTSList);

  // DEBUG: Display the list of travel solutions
  const std::string& lCSVDump = travelccmService.csvDisplay (lTSList);
  STDAIR_LOG_DEBUG (lCSVDump);
  
  // Choose a travel solution
  const stdair::TravelSolutionStruct* lTS_ptr =
    travelccmService.chooseTravelSolution (lTSList, lBookingRequest, iPassengerChoiceModel);

  // Check that a solution has been found
  BOOST_REQUIRE_MESSAGE (lTS_ptr != NULL,
                         "No travel solution can be found for "
                         << lBookingRequest.display()
                         << " within the following list of travel solutions. "
                         << lCSVDump);

  STDAIR_LOG_DEBUG (lTS_ptr->describe());

  // Retrieve the chosen fare option
  stdair::FareOptionStruct lFareOption = lTS_ptr->getChosenFareOption();

  // DEBUG
  std::ostringstream oMessageExpectedPrice;
  oMessageExpectedPrice << "The price chosen by the passenger is: "
                        << lFareOption.getFare() << " Euros. It is expected to be "
                        << iExpectedPrice << " Euros.";
  STDAIR_LOG_DEBUG (oMessageExpectedPrice.str());

  // Check that the price corresponds to the expected one
  BOOST_CHECK_EQUAL (std::floor (lFareOption.getFare() + 0.5), iExpectedPrice);

  BOOST_CHECK_MESSAGE (std::floor (lFareOption.getFare() + 0.5)
                       == iExpectedPrice, oMessageExpectedPrice.str());

  // Close the log file
  logOutputFile.close();

}

/**
 * Choose a fare option among the list of travel solutions
 */
void testAllTravelCCMHelper (const unsigned short iTestFlag) {

  // Output log File
  std::ostringstream oStr;
  oStr << "TravelChoiceTestSuite_" << iTestFlag << ".log";
  const stdair::Filename_T lLogFilename (oStr.str());
    
  // Set the log parameters
  std::ofstream logOutputFile;
  // Open and clean the log outputfile
  logOutputFile.open (lLogFilename.c_str());
  logOutputFile.clear();
  
  // Initialise the service context
  const stdair::BasLogParams lLogParams (stdair::LOG::DEBUG, logOutputFile);
  
  // Build the BOM tree
  TRAVELCCM::TRAVELCCM_Service travelccmService (lLogParams);
  travelccmService.buildSampleBom ();

  // DEBUG
  STDAIR_LOG_DEBUG ("Welcome to TravelCCM");

  // Build a list of travel solutions
  const stdair::BookingRequestStruct& lBookingRequest =
    travelccmService.buildSampleBookingRequest();

  // DEBUG
  STDAIR_LOG_DEBUG ("Booking request: " << lBookingRequest.display());

  // Build the sample BOM tree
  stdair::TravelSolutionList_T lTSList;
  travelccmService.buildSampleTravelSolutions (lTSList);

  // DEBUG: Display the list of travel solutions
  const std::string& lCSVDump = travelccmService.csvDisplay (lTSList);
  STDAIR_LOG_DEBUG (lCSVDump);
  
  // Choose a travel solution with the hard restriction method.
  const stdair::TravelSolutionStruct* lTS_HardRestriction_ptr =
    travelccmService.chooseTravelSolution 
    (lTSList, lBookingRequest, 
     stdair::PassengerChoiceModel::HARD_RESTRICTION); 
  
  STDAIR_LOG_DEBUG ("Chosen travel solution with the Hard Restriction model: "
		    + lTS_HardRestriction_ptr->describe()); 

  // Choose a travel solution with the price oriented model
  const stdair::TravelSolutionStruct* lTS_Price_Oriented_ptr =
    travelccmService.chooseTravelSolution 
    (lTSList, lBookingRequest, 
     stdair::PassengerChoiceModel::PRICE_ORIENTED); 
 
  STDAIR_LOG_DEBUG ("Chosen travel solution with the Price Oriented model: " 
		    + lTS_Price_Oriented_ptr->describe());

  // Choose a travel solution with the hybrid model
  const stdair::TravelSolutionStruct* lTS_Hybrid_ptr =
    travelccmService.chooseTravelSolution 
    (lTSList, lBookingRequest, 
     stdair::PassengerChoiceModel::HYBRID); 
 
  STDAIR_LOG_DEBUG ("Chosen travel solution with the Hybrid model: " +
		    lTS_Hybrid_ptr->describe());

  // Close the log file
  logOutputFile.close();

}


// /////////////// Main: Unit Test Suite //////////////

// Set the UTF configuration (re-direct the output to a specific file)
BOOST_GLOBAL_FIXTURE (UnitTestConfig);

// Start the test suite
BOOST_AUTO_TEST_SUITE (master_test_suite)

/**
 * Test the hard restriction model
 */
BOOST_AUTO_TEST_CASE (simple_hard_restriction_model_test) {

  /**
   * As of September 2012, the fare option chosen by the hard restriction model
   * is valued to 1000 Euros.
   */
  const unsigned int lExpectedPrice = 1000;
  
  BOOST_CHECK_NO_THROW (testTravelCCMHelper
                        (0,
                         stdair::PassengerChoiceModel::HARD_RESTRICTION,
                         lExpectedPrice));
}

/**
 * Test the price oriented model
 */
BOOST_AUTO_TEST_CASE (simple_price_oriented_model_test) {

  /**
   * As of September 2012, the fare option chosen by the price oriented model
   * is valued to 900 Euros.
   */
  const unsigned int lExpectedPrice = 900;
  
  BOOST_CHECK_NO_THROW (testTravelCCMHelper
                        (1,
                         stdair::PassengerChoiceModel::PRICE_ORIENTED,
                         lExpectedPrice));
}

/**
 * Test the hybrid model
 */
BOOST_AUTO_TEST_CASE (simple_hybrid_model_test) {

  /**
   * As of September 2012, the fare option chosen by the price oriented model
   * is valued to 920 Euros.
   */
  const unsigned int lExpectedPrice = 920;
  
  BOOST_CHECK_NO_THROW (testTravelCCMHelper
                        (2,
                         stdair::PassengerChoiceModel::HYBRID,
                         lExpectedPrice));
}

/**
 * Test all models.
 */
BOOST_AUTO_TEST_CASE (all_models_test) {

  BOOST_CHECK_NO_THROW (testAllTravelCCMHelper(3));
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()

/*!
 * \endcode
 */

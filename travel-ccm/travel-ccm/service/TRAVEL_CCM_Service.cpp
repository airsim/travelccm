// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iomanip>
#include <sstream>
#include <iostream>
// TRAVEL-CCM
#include <travel-ccm/basic/BasConst_TRAVEL_CCM_Service.hpp>
#include <travel-ccm/factory/FacTRAVEL_CCMServiceContext.hpp>
#include <travel-ccm/command/Simulator.hpp>
#include <travel-ccm/service/TRAVEL_CCM_ServiceContext.hpp>
#include <travel-ccm/service/Logger.hpp>
#include <travel-ccm/TRAVEL_CCM_Service.hpp>

namespace TRAVEL_CCM {

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service () {
    // Initialise the context
    TRAVEL_CCM_ServiceContext& lTRAVEL_CCM_ServiceContext = 
      FacTRAVEL_CCMServiceContext::instance().create ();
    _travel_ccmServiceContext = &lTRAVEL_CCM_ServiceContext;
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service (const TRAVEL_CCM_Service& iService) :
    _travel_ccmServiceContext (iService._travel_ccmServiceContext) {
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service (std::ostream& ioLogStream) {
    // Initialise the context
    init (ioLogStream);
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::~TRAVEL_CCM_Service () {
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::init (std::ostream& ioLogStream) {
    // Set the log file
    logInit (LOG::DEBUG, ioLogStream);

    // Initialise the context
    TRAVEL_CCM_ServiceContext& lTRAVEL_CCM_ServiceContext = 
      FacTRAVEL_CCMServiceContext::instance().create ();
    _travel_ccmServiceContext = &lTRAVEL_CCM_ServiceContext;
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::logInit (const LOG::EN_LogLevel iLogLevel,
                                    std::ostream& ioLogOutputFile) {
    Logger::instance().setLogParameters (iLogLevel, ioLogOutputFile);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::addTravelSolution(std::string dAirport,
                                             std::string aAirport,
                                             Date_T depDate,
                    Duration_T depTime, Duration_T arTime, Duration_T dur,
                    bool Ref, std::string airline, std::string cabin,
                    int flightNum, double fare, int lagsNum,  bool SNS,
                    bool change) {
    assert(_travel_ccmServiceContext != NULL);
    _travel_ccmServiceContext->addTravelSolution(dAirport, aAirport, depDate,
                                                 depTime, arTime, dur, Ref,
                                                 airline, cabin, flightNum,
                                                 fare, lagsNum, SNS, change);
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::addRestriction(std::string restrictionType) {
    _travel_ccmServiceContext->addRestriction(restrictionType);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::addRestriction(std::string restrictionType,
                                          std::string namePreference) {
    _travel_ccmServiceContext->addRestriction(restrictionType, namePreference);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::simulate()  {
    // add travel solutions to the travelsolution holder
    assert(_travel_ccmServiceContext != NULL);
    addTravelSolution("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                      Duration_T(14,00,00), Duration_T(02,00,00), false,
                      "AF", "ECO", 404, 200, 0, false, false);
    addTravelSolution("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                      Duration_T(14,00,00), Duration_T(02,00,00), true, "AF",
                      "ECO", 404, 200, 0, false, false);
    addTravelSolution("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                      Duration_T(14,00,00), Duration_T(02,00,00), false, "BA",
                      "ECO", 404, 200, 0, true, false);
    addTravelSolution("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                      Duration_T(14,00,00), Duration_T(02,00,00), true, "BA",
                      "ECO", 404, 200, 0, true, false);

    // add restrictions to the restriction holder
    addRestriction("refundability");
    addRestriction("preferredAirline", "AF");
    
    // Retrive the travel solution holder in the service context.
    TravelSolutionHolder& travelSolutionHolder =
                 _travel_ccmServiceContext->getTravelSolutionHolder();

    // Retrive the restriction holder in the service context.
    RestrictionHolder& restrictionHolder =
      _travel_ccmServiceContext->getRestrictionHolder();

    // Retrive the restriction holder in the passenger object in the
    // service context.
    /* we stop using the passenger class for the moment
       Passenger& passenger = _travel_ccmServiceContext->getPassenger();
    */

    // initialize the different pointers at the beginning of the different lists
    restrictionHolder.begin();
    travelSolutionHolder.begin();

    TRAVEL_CCM_LOG_DEBUG ("TravelSolutionHolder: " << travelSolutionHolder);
    TRAVEL_CCM_LOG_DEBUG ("RestrictionHolder: " << restrictionHolder);

    // Call the underlying Use Case (command)
    Simulator::simulate(restrictionHolder, travelSolutionHolder);

    /* we will need the different restrictions and their order so the first
       argument of the function orderedPreference will probably change
    */
    TRAVEL_CCM_LOG_DEBUG ("TravelSolutionHolder: " << travelSolutionHolder);
  }

}

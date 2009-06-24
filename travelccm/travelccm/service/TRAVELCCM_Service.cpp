// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iomanip>
#include <sstream>
#include <iostream>
// TRAVELCCM
#include <travelccm/basic/BasConst_TRAVELCCM_Service.hpp>
#include <travelccm/factory/FacTRAVELCCMServiceContext.hpp>
#include <travelccm/command/Simulator.hpp>
#include <travelccm/service/TRAVELCCM_ServiceContext.hpp>
#include <travelccm/service/Logger.hpp>
#include <travelccm/TRAVELCCM_Service.hpp>

namespace TRAVELCCM {

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_Service::TRAVELCCM_Service () {
    // Initialise the context
    TRAVELCCM_ServiceContext& lTRAVELCCM_ServiceContext = 
      FacTRAVELCCMServiceContext::instance().create ();
    _travelccmServiceContext = &lTRAVELCCM_ServiceContext;
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_Service::TRAVELCCM_Service (const TRAVELCCM_Service& iService) :
    _travelccmServiceContext (iService._travelccmServiceContext) {
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_Service::TRAVELCCM_Service (std::ostream& ioLogStream) {
    // Initialise the context
    init (ioLogStream);
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_Service::~TRAVELCCM_Service () {
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::init (std::ostream& ioLogStream) {
    // Set the log file
    logInit (LOG::DEBUG, ioLogStream);

    // Initialise the context
    TRAVELCCM_ServiceContext& lTRAVELCCM_ServiceContext = 
      FacTRAVELCCMServiceContext::instance().create ();
    _travelccmServiceContext = &lTRAVELCCM_ServiceContext;
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::logInit (const LOG::EN_LogLevel iLogLevel,
                                    std::ostream& ioLogOutputFile) {
    Logger::instance().setLogParameters (iLogLevel, ioLogOutputFile);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::
  addTravelSolution  (const std::string& iDepartureAirport,
                      const std::string& iArrivalAirport,
                      const Date_T& iDepartureDate,
                      const Duration_T& iDepartureTime,
                      const Duration_T& iArrivalTime,
                      const Duration_T& iDuration,
                      const bool iRefundability,
                      const std::string& iAirlineCode,
                      const std::string& iCabinCode,
                      const int iFlightNumber, double iFare,
                      int iStopsNumber,  bool iSNS, bool iChangeability,
                      const std::string& id) {
    assert (_travelccmServiceContext != NULL);

    _travelccmServiceContext->addTravelSolution (iDepartureAirport,
                                                 iArrivalAirport, iDepartureDate,
                                                 iDepartureTime, iArrivalTime,
                                                 iDuration, iRefundability,
                                                 iAirlineCode, iCabinCode,
                                                 iFlightNumber,
                                                 iFare, iStopsNumber, iSNS,
                                                 iChangeability, id);
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::addRestriction (const std::string& iRestrictionType) {
    assert (_travelccmServiceContext != NULL);
    _travelccmServiceContext->addRestriction (iRestrictionType);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::addRestriction (const std::string& iRestrictionType,
                                          const std::string& iNamePreference) {
    assert (_travelccmServiceContext != NULL);
    _travelccmServiceContext->addRestriction (iRestrictionType, iNamePreference);
  }

  // //////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& TRAVELCCM_Service::getChoosenTravelSolutions() {

    // Retrieve the travel solution holder in the service context.
    TravelSolutionHolder& travelSolutionHolder =
      _travelccmServiceContext->getTravelSolutionHolder();
    // Retrieve the restriction holder in the service context.
    RestrictionHolder& restrictionHolder =
      _travelccmServiceContext->getRestrictionHolder();
    
    // Initialise the different pointers at the beginning of the different lists
    restrictionHolder.begin();
    travelSolutionHolder.begin();

    // launch the algorithm of preferred choices
    Simulator::simulate (restrictionHolder, travelSolutionHolder);
    
    return travelSolutionHolder;
  }

  // //////////////////////////////////////////////////////////////////////
  const TravelSolution& TRAVELCCM_Service::
  getBestTravelSolution (TravelSolutionHolder& ioTravelSolutionHolder) {
    ioTravelSolutionHolder.begin();
    const TravelSolution* oBestTravelSolution_ptr =
      &ioTravelSolutionHolder.getCurrentTravelSolution();
    while (ioTravelSolutionHolder.hasNotReachedEnd()) {
      const TravelSolution& lCurrentTravelSolution =
        ioTravelSolutionHolder.getCurrentTravelSolution();
      bool hasToChangeOfTS =
        lCurrentTravelSolution.isCheaper (*oBestTravelSolution_ptr);
      if (hasToChangeOfTS) {
        oBestTravelSolution_ptr = &lCurrentTravelSolution ;
      }
      ioTravelSolutionHolder.iterate();
    }
    return *oBestTravelSolution_ptr;
  }

  // //////////////////////////////////////////////////////////////////////
  std::string TRAVELCCM_Service::getBestTravelSolutionId() {
    TravelSolutionHolder& lTravelSolutionHolder = getChoosenTravelSolutions();
    const TravelSolution& lBestTravelSolution =
      getBestTravelSolution(lTravelSolutionHolder);
    std::string id = lBestTravelSolution.getId();
    return id;
  }
    
  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_Service::simulate()  {
    // add travel solutions to the travelsolution holder
    assert(_travelccmServiceContext != NULL);

    // AF404, NCE-LHR, 01-JUN-09 12:00 -> 14:00 (02:00), Eco
    addTravelSolution ("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                       Duration_T(14,00,00), Duration_T(02,00,00), false,
                       "AF", "ECO", 404, 200, 0, false, false, "T1");
    
    // AF404, NCE-LHR, 01-JUN-09 12:00 -> 14:00 (02:00), Eco
    addTravelSolution ("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                       Duration_T(14,00,00), Duration_T(02,00,00), true, "AF",
                       "ECO", 404, 200, 0, false, false, "T2");
    
    // BA404, NCE-LHR, 01-JUN-09 12:00 -> 14:00 (02:00), Eco
    addTravelSolution ("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                       Duration_T(14,00,00), Duration_T(02,00,00), false, "BA",
                       "ECO", 404, 200, 0, true, false, "T3");
    
    // BA404, NCE-LHR, 01-JUN-09 12:00 -> 14:00 (02:00), Eco
    addTravelSolution ("NCE","LHR", Date_T(2009,06,1), Duration_T(12,00,00),
                       Duration_T(14,00,00), Duration_T(02,00,00), true, "BA",
                       "ECO", 404, 200, 0, true, false, "T4");

    /* Add restrictions to the restriction holder
       the earlier we add the restriction, the more important
    */
    addRestriction ("refundability");
    addRestriction ("preferredAirline", "AF");
    
    // Retrieve the travel solution holder in the service context.
    TravelSolutionHolder& travelSolutionHolder =
      _travelccmServiceContext->getTravelSolutionHolder();

    // Retrieve the restriction holder in the service context.
    RestrictionHolder& restrictionHolder =
      _travelccmServiceContext->getRestrictionHolder();

    // Retrieve the restriction holder in the passenger object in the
    // service context.
    /* We stop using the passenger class for the moment
       Passenger& passenger = _travelccmServiceContext->getPassenger();
    */

    // Initialise the different pointers at the beginning of the different lists
    restrictionHolder.begin();
    travelSolutionHolder.begin();

    TRAVELCCM_LOG_DEBUG ("TravelSolutionHolder: " << travelSolutionHolder);
    TRAVELCCM_LOG_DEBUG ("RestrictionHolder: " << restrictionHolder);

    // Call the underlying Use Case (command)
    Simulator::simulate (restrictionHolder, travelSolutionHolder);

    /* We will need the different restrictions and their order so the first
       argument of the function orderedPreference will probably change
    */
    TRAVELCCM_LOG_DEBUG ("TravelSolutionHolder: " << travelSolutionHolder);
  }

}

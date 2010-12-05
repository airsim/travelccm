 // //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVELCCM
#include <travelccm/basic/BasConst_TRAVELCCM_Service.hpp>
#include <travelccm/bom/TravelSolution.hpp>
#include <travelccm/bom/TravelSolutionHolder.hpp>
#include <travelccm/bom/Restriction.hpp>
#include <travelccm/bom/RestrictionHolder.hpp>
#include <travelccm/bom/Passenger.hpp>
#include <travelccm/bom/CCM.hpp>
#include <travelccm/service/TRAVELCCM_ServiceContext.hpp>
#include <travelccm/service/Logger.hpp>
// FACTORY
#include <travelccm/factory/FacTravelSolution.hpp>
#include <travelccm/factory/FacTravelSolutionHolder.hpp>
#include <travelccm/factory/FacRestriction.hpp>
#include <travelccm/factory/FacRestrictionHolder.hpp>
#include <travelccm/factory/FacPassenger.hpp>
#include <travelccm/factory/FacRequest.hpp>
#include <travelccm/factory/FacDepartureTimePreferencePattern.hpp>
#include <travelccm/factory/FacSupervisor.hpp>
// COMMAND
#include <travelccm/command/FileMgr.hpp>


namespace TRAVELCCM {
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext () {
    init();
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&) {
    init ();
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::~TRAVELCCM_ServiceContext() {
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::init () {
    // set the travel solution holder
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::createPassenger(std::string passengerType) {
    _passenger = &FacPassenger::instance().create(passengerType);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::intializePassenger() {
    // set the restriction holder of the passenger
    RestrictionHolder& lRestrictionHolder =
      FacRestrictionHolder::instance().create();
    FacPassenger::instance().linkPassengerWithRestrictionHolder(*_passenger, lRestrictionHolder);
    
    // set the departure time preference pattern of the passenger
    const std::string& passengerType = _passenger->getPassengerType();
    DepartureTimePreferencePattern& lDepartureTimePreferencePattern =
      FacDepartureTimePreferencePattern::instance().create(passengerType);
    FacPassenger::instance().linkPassengerWithDepartureTimePreferencePattern(*_passenger, lDepartureTimePreferencePattern);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addTravelSolution (const std::string& iDepartureAirport,
                     const std::string& iArrivalAirport,
                     const Date_T& iDepartureDate,
                     const Duration_T& iDepartureTime,
                     const Duration_T& iArrivalTime,
                     const Duration_T& iDuration,
                     const bool iRefundability,
                     const std::string& iAirlineCode,
                     const std::string& iCabinCode,
                     const int iFlightNumber, const double iFare,
                     int iStopsNumber, bool iSNS, bool iChangeability,
                     const std::string& id) {
    TravelSolution& aTravelSolution =
      FacTravelSolution::instance().create(iDepartureAirport, iArrivalAirport,
                                           iDepartureDate, iDepartureTime,
                                           iArrivalTime, iDuration,
                                           iRefundability, iAirlineCode,
                                           iCabinCode, iFlightNumber, iFare,
                                           iStopsNumber, iSNS, iChangeability,
                                           id);
    assert (_travelSolutionHolder != NULL);
    FacTravelSolution::instance().addTravelSolution (*_travelSolutionHolder,
                                                     aTravelSolution);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addRestriction (const std::string& iRestrictionType) {
    Restriction& aRestriction =
      FacRestriction::instance().create(iRestrictionType);
    _passenger->addRestriction(aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addRestriction (const std::string& iRestrictionType,
                  const std::string& iNamePreference) {
    Restriction& aRestriction =
      FacRestriction::instance().create(iRestrictionType, iNamePreference);
    _passenger->addRestriction(aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addRestriction (const std::string& iRestrictionType,
                  const DateTime_T iDepartureTime) {
    Restriction& aRestriction =
      FacRestriction::instance().create(iRestrictionType, iDepartureTime);
    _passenger->addRestriction(aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addAndLinkRequest (bool refundability, bool changeability,
                     bool saturdayNightStay, std::string preferredAirline,
                     std::string preferredCabin, DateTime_T departureTime) {
    Request& aRequest =
      FacRequest::instance().create(refundability, changeability,
                                    saturdayNightStay, preferredAirline,
                                    preferredCabin, departureTime);
    FacPassenger::instance().linkPassengerWithRequest(*_passenger, aRequest);
  }

  // //////////////////////////////////////////////////////////////////////
  RestrictionHolder& TRAVELCCM_ServiceContext::getRestrictionHolder() const {
    return _passenger->getPassengerRestrictions();
  }
  
  // //////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& TRAVELCCM_ServiceContext::
                               getTravelSolutionHolder() const {
    return *_travelSolutionHolder;
  }

  // //////////////////////////////////////////////////////////////////////
  Passenger& TRAVELCCM_ServiceContext::getPassenger() const {
    assert(_passenger != NULL);
    return *_passenger;
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  readFromInputFile (const std::string& iInputFileName) {
    assert (_travelSolutionHolder != NULL);
    FileMgr::readAndProcessTravelSolutionInputFile (iInputFileName,
                                                    *_travelSolutionHolder);
  }

  // //////////////////////////////////////////////////////////////////////
  const TravelSolution* TRAVELCCM_ServiceContext::
  getBestAndCheapestTravelSolutionByMatchingIndicator () {
    // passenger type, request and int
    assert (_passenger != NULL);
    assert (_travelSolutionHolder != NULL);

    const Request& iRequest = _passenger->getPassengerRequest();
    const std::string iPassengerType = _passenger->getPassengerType();

    // filtrate to keep only the travel solution with the highest matching
    // indicator.
    CCM::getBestTravelSolutionByMatchingIndicator(iPassengerType, iRequest,
                                                  _travelSolutionHolder);

    if (_travelSolutionHolder->isVoid())
      return NULL;
    else {
      const TravelSolution* cheapestTravelSolution =
        _travelSolutionHolder->getCheapestTravelSolution();
      return cheapestTravelSolution;
    }
  }
  
  // /////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::addAndOrderRestrictionsFromRequest() {
    /* the order when adding the restrictions is crucial since it reflects
       the importance of the characteristics, compared to the others; more
       precisely the first characteristic added is the most important for the
       passenger and the last one the less important.
       For a business passenger, we have: departureTime >> saturday night stay >>
       refundability >> preferred airline >> preferred cabin >> changeability
       For a leisure passenger, we have: changeability >> departure time >>
       preferred airline >> saturday night stay >> refundability >>
       preferred cabin  */

    assert (_passenger != NULL);
    Request& request = _passenger->getPassengerRequest();

    std::string passengerType = _passenger->getPassengerType();
    
    // retrieve the characteristics of the fare in the Request class
    const bool refundability = request.getRefundability();
    const bool changeability = request.getChangeability();
    const bool saturdayNightStay = request.getSaturdayNightStay();
    const std::string preferredAirline = request.getPreferredAirline();
    const std::string preferredCabin = request.getPreferredCabin();
    const DateTime_T departureTime = request.getDepartureTime();
    if (passengerType == "B") {
      // there is always a departure time request so we always add a time
      // restriction
      addRestriction("timePreference", departureTime);
      if (saturdayNightStay) {
        addRestriction("saturdayStay");
      }
      if (refundability) {
        addRestriction("refundability");
      }
      if (preferredAirline != "NONE") {
        addRestriction("preferredAirline", preferredAirline);
      }
      if (preferredCabin != "NONE") {
        addRestriction("preferredCabin", preferredCabin);
      }
      if (changeability) {
        addRestriction("changeability");
      }
      
    } else if (passengerType == "L") {
      if (changeability) {
        addRestriction("changeability");
      }
      addRestriction("timePreference", departureTime);
      if (preferredAirline != "NONE") {
        addRestriction("preferredAirline", preferredAirline);
      }
      if (saturdayNightStay) {
        addRestriction("saturdayStay");
      }
      if (refundability) {
        addRestriction("refundability");
      }
      if (preferredCabin != "NONE") {
        addRestriction("preferredCabin", preferredCabin);
      }
    }
  }
  
}

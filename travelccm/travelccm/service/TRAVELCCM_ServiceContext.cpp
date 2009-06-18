// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVELCCM
#include <travelccm/basic/BasConst_TRAVELCCM_Service.hpp>
#include <travelccm/factory/FacSupervisor.hpp>
#include <travelccm/service/TRAVELCCM_ServiceContext.hpp>
#include <travelccm/bom/Request.hpp>
#include <travelccm/bom/TravelSolution.hpp>
#include <travelccm/bom/TravelSolutionHolder.hpp>
#include <travelccm/bom/Restriction.hpp>
#include <travelccm/bom/RestrictionHolder.hpp>
#include <travelccm/factory/FacTravelSolution.hpp>
#include <travelccm/factory/FacTravelSolutionHolder.hpp>
#include <travelccm/factory/FacRestriction.hpp>
#include <travelccm/factory/FacRestrictionHolder.hpp>
#include <travelccm/factory/FacRequest.hpp>
#include <travelccm/factory/FacPassenger.hpp>
#include <travelccm/command/FileMgr.hpp>


namespace TRAVELCCM {
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext () {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    _restrictionHolder = &FacRestrictionHolder::instance().create();
    init ();
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&) {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    _restrictionHolder = &FacRestrictionHolder::instance().create();
    init ();
    }

  // //////////////////////////////////////////////////////////////////////
  /* TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext (Request& req,
                                                        std::string passType) {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    init(req,passType);
    } */

  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::~TRAVELCCM_ServiceContext() {
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::init () {
  }

  // //////////////////////////////////////////////////////////////////////
  /* void TRAVELCCM_ServiceContext::init (Request& req, std::string passType) {
    _passenger = &FacPassenger::instance().create(req, passType);
    } */

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
    assert (_restrictionHolder != NULL);
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                               aRestriction);
  }

   // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  addRestriction (const std::string& iRestrictionType,
                  const std::string& iNamePreference) {
    Restriction& aRestriction =
      FacRestriction::instance().create(iRestrictionType, iNamePreference);
    assert (_restrictionHolder != NULL);
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                                     aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  RestrictionHolder& TRAVELCCM_ServiceContext::
                               getRestrictionHolder() const {
    return *_restrictionHolder;
  }
  
  // //////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& TRAVELCCM_ServiceContext::
                               getTravelSolutionHolder() const {
    return *_travelSolutionHolder;
  }

  // //////////////////////////////////////////////////////////////////////
  /*Passenger& TRAVELCCM_ServiceContext::getPassenger() const {
    return *_passenger;
    } */

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  readFromInputFile (const std::string& iInputFileName) {
    assert (_travelSolutionHolder != NULL);
    FileMgr::readAndProcessTravelSolutionInputFile (iInputFileName,
                                                    *_travelSolutionHolder);
  }
}

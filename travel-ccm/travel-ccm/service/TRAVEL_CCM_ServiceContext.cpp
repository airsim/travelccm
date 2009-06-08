// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL-CCM
#include <travel-ccm/basic/BasConst_TRAVEL_CCM_Service.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/TRAVEL_CCM_ServiceContext.hpp>
#include <travel-ccm/bom/Request.hpp>
#include <travel-ccm/bom/TravelSolution.hpp>
#include <travel-ccm/bom/TravelSolutionHolder.hpp>
#include <travel-ccm/bom/Restriction.hpp>
#include <travel-ccm/bom/RestrictionHolder.hpp>
#include <travel-ccm/factory/FacTravelSolution.hpp>
#include <travel-ccm/factory/FacTravelSolutionHolder.hpp>
#include <travel-ccm/factory/FacRestriction.hpp>
#include <travel-ccm/factory/FacRestrictionHolder.hpp>
#include <travel-ccm/factory/FacRequest.hpp>
#include <travel-ccm/factory/FacPassenger.hpp>
#include <travel-ccm/command/FileMgr.hpp>


namespace TRAVEL_CCM {
  
  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_ServiceContext::TRAVEL_CCM_ServiceContext () {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    _restrictionHolder = &FacRestrictionHolder::instance().create();
    init ();
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_ServiceContext::TRAVEL_CCM_ServiceContext (const TRAVEL_CCM_ServiceContext&) {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    _restrictionHolder = &FacRestrictionHolder::instance().create();
    init ();
    }

  // //////////////////////////////////////////////////////////////////////
  /* TRAVEL_CCM_ServiceContext::TRAVEL_CCM_ServiceContext (Request& req,
                                                        std::string passType) {
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    init(req,passType);
    } */

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_ServiceContext::~TRAVEL_CCM_ServiceContext() {
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_ServiceContext::init () {
  }

  // //////////////////////////////////////////////////////////////////////
  /* void TRAVEL_CCM_ServiceContext::init (Request& req, std::string passType) {
    _passenger = &FacPassenger::instance().create(req, passType);
    } */

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_ServiceContext::
  addTravelSolution (std::string dAirport, std::string aAirport,
                     Date_T depDate,
                     Duration_T depTime, Duration_T arTime, Duration_T dur,
                     bool Ref, std::string airline, std::string cabin,
                     int flightNum, double fare, int lagsNum, bool SNS,
                     bool change) {
    TravelSolution& aTravelSolution =
      FacTravelSolution::instance().create(dAirport, aAirport, depDate,
                                           depTime, arTime, dur, Ref, airline,
                                           cabin, flightNum, fare, lagsNum,
                                           SNS, change);
    assert (_travelSolutionHolder != NULL);
    FacTravelSolution::instance().addTravelSolution (*_travelSolutionHolder,
                                                     aTravelSolution);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_ServiceContext::addRestriction (std::string restrictionType) {
    Restriction& aRestriction =
      FacRestriction::instance().create(restrictionType);
    assert (_restrictionHolder != NULL);
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                                     aRestriction);
  }

   // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_ServiceContext::addRestriction (std::string restrictionType,
                                                  std::string namePreference) {
    Restriction& aRestriction =
      FacRestriction::instance().create(restrictionType, namePreference);
    assert (_restrictionHolder != NULL);
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                                     aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  RestrictionHolder& TRAVEL_CCM_ServiceContext::
                               getRestrictionHolder() const {
    return *_restrictionHolder;
  }
  
  // //////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& TRAVEL_CCM_ServiceContext::
                               getTravelSolutionHolder() const {
    return *_travelSolutionHolder;
  }

  // //////////////////////////////////////////////////////////////////////
  /*Passenger& TRAVEL_CCM_ServiceContext::getPassenger() const {
    return *_passenger;
    } */

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_ServiceContext::
  readFromInputFile (const std::string& iInputFileName) {
    assert (_travelSolutionHolder != NULL);
    FileMgr::readAndProcessTravelSolutionInputFile (iInputFileName,
                                                    *_travelSolutionHolder);
  }
}

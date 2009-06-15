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
    init ();
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::
  TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&) {
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
    _travelSolutionHolder = &FacTravelSolutionHolder::instance().create();
    _restrictionHolder = &FacRestrictionHolder::instance().create();
  }

  // //////////////////////////////////////////////////////////////////////
  /* void TRAVELCCM_ServiceContext::init (Request& req, std::string passType) {
    _passenger = &FacPassenger::instance().create(req, passType);
    }
  */

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
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
  void TRAVELCCM_ServiceContext::addRestriction (std::string restrictionType) {
    Restriction& aRestriction =
      FacRestriction::instance().create (restrictionType);
    assert (_restrictionHolder != NULL);
    
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                               aRestriction);
  }

   // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::addRestriction (std::string restrictionType,
                                                  std::string namePreference) {
    Restriction& aRestriction =
      FacRestriction::instance().create(restrictionType, namePreference);
    assert (_restrictionHolder != NULL);
    
    FacRestriction::instance().addRestriction (*_restrictionHolder,
                                               aRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  RestrictionHolder& TRAVELCCM_ServiceContext::
  getRestrictionHolder() const {
    assert (_restrictionHolder != NULL);
    return *_restrictionHolder;
  }
  
  // //////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& TRAVELCCM_ServiceContext::
  getTravelSolutionHolder() const {
    assert (_travelSolutionHolder != NULL);
    return *_travelSolutionHolder;
  }

  // //////////////////////////////////////////////////////////////////////
  /*Passenger& TRAVELCCM_ServiceContext::getPassenger() const {
    return *_passenger;
    }
  */

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::
  readFromInputFile (const std::string& iInputFileName) {
    assert (_travelSolutionHolder != NULL);
    FileMgr::readAndProcessTravelSolutionInputFile (iInputFileName,
                                                    *_travelSolutionHolder);
  }
  
}

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacAirline.hpp>
#include <travel-ccm/bom/Airline.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacAirline* FacAirline::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacAirline::~FacAirline () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacAirline& FacAirline::instance () {

    if (_instance == NULL) {
      _instance = new FacAirline();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  Airline& FacAirline::create () {
    Airline* aAirline_ptr = NULL;

    aAirline_ptr = new Airline ();
    assert (aAirline_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aAirline_ptr);

    return *aAirline_ptr;
  }

}


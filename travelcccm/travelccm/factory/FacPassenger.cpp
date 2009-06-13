// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVELCCM 
#include <travelccm/factory/FacPassenger.hpp>
#include <travelccm/bom/Passenger.hpp>
#include <travelccm/factory/FacSupervisor.hpp>
#include <travelccm/service/Logger.hpp>

namespace TRAVELCCM {

  FacPassenger* FacPassenger::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacPassenger::~FacPassenger () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacPassenger& FacPassenger::instance () {

    if (_instance == NULL) {
      _instance = new FacPassenger();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  Passenger& FacPassenger::create () {
    Passenger* aPassenger_ptr = NULL;

    aPassenger_ptr = new Passenger ();
    assert (aPassenger_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aPassenger_ptr);

    return *aPassenger_ptr;
  }

  // ////////////////////////////////////////////////////////////////////
  Passenger& FacPassenger::create (Request& req, std::string passType) {
    Passenger* aPassenger_ptr = NULL;

    aPassenger_ptr = new Passenger (req, passType);
    assert (aPassenger_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aPassenger_ptr);

    return *aPassenger_ptr;
  }

  // ////////////////////////////////////////////////////////////////////
  void FacPassenger::
  linkPassengerWithRestrictionHolder (Passenger& ioPassenger,
                                      RestrictionHolder& ioRestrictionHolder) {
    ioPassenger._passengerRestrictions = &ioRestrictionHolder;
  }

}


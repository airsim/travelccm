// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacTime.hpp>
#include <travel-ccm/bom/Time.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacTime* FacTime::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacTime::~FacTime () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacTime& FacTime::instance () {

    if (_instance == NULL) {
      _instance = new FacTime();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  Time& FacTime::create () {
    Time* aTime_ptr = NULL;

    aTime_ptr = new Time ();
    assert (aTime_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aTime_ptr);

    return *aTime_ptr;
  }

}


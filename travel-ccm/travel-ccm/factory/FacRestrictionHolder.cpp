// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/RestrictionHolder.hpp>
#include <travel-ccm/factory/FacRestrictionHolder.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacRestrictionHolder* FacRestrictionHolder::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacRestrictionHolder::~FacRestrictionHolder () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacRestrictionHolder& FacRestrictionHolder::instance () {

    if (_instance == NULL) {
      _instance = new FacRestrictionHolder();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  RestrictionHolder& FacRestrictionHolder::create () {
    RestrictionHolder* aRestrictionHolder_ptr = NULL;

    aRestrictionHolder_ptr = new RestrictionHolder ();
    assert (aRestrictionHolder_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aRestrictionHolder_ptr);

    return *aRestrictionHolder_ptr;
  }

}


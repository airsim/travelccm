// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacCCM.hpp>
#include <travel-ccm/bom/CCM.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacCCM* FacCCM::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacCCM::~FacCCM () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacCCM& FacCCM::instance () {

    if (_instance == NULL) {
      _instance = new FacCCM();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  CCM& FacCCM::create () {
    CCM* aCCM_ptr = NULL;

    aCCM_ptr = new CCM ();
    assert (aCCM_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aCCM_ptr);

    return *aCCM_ptr;
  }

}


// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/TravelSolutionHolder.hpp>
#include <travel-ccm/factory/FacTravelSolutionHolder.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacTravelSolutionHolder* FacTravelSolutionHolder::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacTravelSolutionHolder::~FacTravelSolutionHolder () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacTravelSolutionHolder& FacTravelSolutionHolder::instance () {

    if (_instance == NULL) {
      _instance = new FacTravelSolutionHolder();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  TravelSolutionHolder& FacTravelSolutionHolder::create () {
    TravelSolutionHolder* aTravelSolutionHolder_ptr = NULL;

    aTravelSolutionHolder_ptr = new TravelSolutionHolder ();
    assert (aTravelSolutionHolder_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aTravelSolutionHolder_ptr);

    return *aTravelSolutionHolder_ptr;
  }

}


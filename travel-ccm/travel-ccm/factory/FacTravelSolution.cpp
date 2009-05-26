// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacTravelSolution.hpp>
#include <travel-ccm/bom/TravelSolution.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacTravelSolution* FacTravelSolution::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacTravelSolution::~FacTravelSolution () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacTravelSolution& FacTravelSolution::instance () {

    if (_instance == NULL) {
      _instance = new FacTravelSolution();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  TravelSolution& FacTravelSolution::create () {
    TravelSolution* aTravelSolution_ptr = NULL;

    aTravelSolution_ptr = new TravelSolution ();
    assert (aTravelSolution_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aTravelSolution_ptr);

    return *aTravelSolution_ptr;
  }

  // ////////////////////////////////////////////////////////////////////
  TravelSolution& FacTravelSolution::create (std::string dAirport,
               std::string aAirport, Time depTime, Time arTime, Time dur,
               bool Ref, std::string airline,  std::string cabin,
               int flightNum, double fare, int lagsNum, bool SNS, bool change) {
    TravelSolution* aTravelSolution_ptr = NULL;

    aTravelSolution_ptr = new TravelSolution (std::string dAirport,
                  std::string aAirport, Time depTime, Time arTime, Time dur,
                  bool Ref, std::string airline, std::string cabin,
                  int flightNum, double fare, int lagsNum, bool SNS, bool change);
    assert (aTravelSolution_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aTravelSolution_ptr);

    return *aTravelSolution_ptr;
  }
  

}


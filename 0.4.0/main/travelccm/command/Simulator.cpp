// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
#include <string>
// TRAVELCCM
#include <travelccm/command/Simulator.hpp>
#include <travelccm/service/Logger.hpp>

namespace TRAVELCCM {

  // //////////////////////////////////////////////////////////////////////
  bool Simulator::simulate(Passenger& ioPassenger,
                           TravelSolutionHolder& ioTravelSolutionHolder) {
    
    int numTravelSolIn = ioTravelSolutionHolder.numberOfTravelSolutions();

    // print the number of travel solutions before the customer choice
    TRAVELCCM_LOG_DEBUG ("Initially there are " << numTravelSolIn
                         << " travel solutions");

    // run the algorithm of passenger choice
    CCM::orderedPreferences (ioTravelSolutionHolder, ioPassenger);
    
    // print the travel solutions among which the customer will choose
    int numTravelSolOut = ioTravelSolutionHolder.numberOfTravelSolutions();

    TRAVELCCM_LOG_DEBUG ("Finally there are " << numTravelSolOut
                         << " travel solutions");
    
    TRAVELCCM_LOG_DEBUG ("Simulation ended properly!");

    return (numTravelSolOut == 0);
  }
  
}

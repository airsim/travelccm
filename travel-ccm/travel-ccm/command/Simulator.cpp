// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
#include <string>
// TRAVEL-CCM
#include <travel-ccm/command/Simulator.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  // //////////////////////////////////////////////////////////////////////
  void Simulator::simulate(RestrictionHolder& ioRestrictionHolder,
                           TravelSolutionHolder& ioTravelSolutionHolder) {
    /* no passenger field anymore 
    RestrictionHolder& restrictions = ioPassenger.getPassengerRestrictions();
    */

    int numTravelSolIn = ioTravelSolutionHolder.numberOfTravelSolutions();
    // print the number of travel solutions before the customer choice
    TRAVEL_CCM_LOG_DEBUG ("Initially there are " << numTravelSolIn
                          << " travel solutions");

    // run the algorithm of passenger choice
    CCM::orderedPreferences (ioTravelSolutionHolder, ioRestrictionHolder);
    
    // print the travel solutions among which the customer will choose
    int numTravelSolOut= ioTravelSolutionHolder.numberOfTravelSolutions();
    TRAVEL_CCM_LOG_DEBUG ( "Finally there are " << numTravelSolOut
                           << " travel solutions");
    //TRAVEL_CCM_LOG_DEBUG ( ioTravelSolutionHolder.toString() );
    TRAVEL_CCM_LOG_DEBUG ("Simulation ended properly!");
  }
  
}

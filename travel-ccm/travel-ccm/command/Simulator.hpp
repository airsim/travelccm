#ifndef __TRAVEL_CCM_COM_CMD_SIMULATOR_HPP
#define __TRAVEL_CCM_COM_CMD_SIMULATOR_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL-CCM Common
#include <travel-ccm/bom/TravelSolutionHolder.hpp>
#include <travel-ccm/bom/RestrictionHolder.hpp>
#include <travel-ccm/command/CmdAbstract.hpp>
#include <travel-ccm/bom/CCM.hpp>


namespace TRAVEL_CCM {

  /** Class implementing a small simulation, which uses the Customer-Choice
      Model (CCM). */
  class Simulator : public CmdAbstract {
    
  public:

    // ////////// Business Methods /////////
    /** Perform a small simulation, which uses the Customer Choice Model.*/
    static void simulate(RestrictionHolder&, TravelSolutionHolder&);

    
  private:
    
  };

}
#endif // __TRAVEL_CCM_COM_CMD_SIMULATOR_HPP

#ifndef __TRAVEL_CCM_CMD_FILEMGR_HPP
#define __TRAVEL_CCM_CMD_FILEMGR_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
#include <string>

namespace TRAVEL_CCM {

  class TravelSolutionHolder;
  
  /** Class filling the TravelSolutionHolder structure (representing
      a list of classes/travelSolutions) from a given input file. */
  class FileMgr {
  public:
    /** Read the input values from a CSV file. */
    static void
    readAndProcessTravelSolutionInputFile (const std::string& iInputFileName,
                                           TravelSolutionHolder&);
    
  };
}
#endif // __TRAVEL_CCM_CMD_FILEMGR_HPP

#ifndef __RMOL_TRAVELSOLUTIONLIST_HPP
#define __RMOL_TRAVELSOLUTIONLIST_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <list>

namespace TRAVEL_CCM {

  /** Forward declarations. */
  class TravelSolution;

  /** Define a vector (ordered map) of N TravelSlutions/classes. */
  typedef std::list<TravelSolution*> TravelSolutionList_T;
  
}
#endif // __RMOL_TRAVELSOLUTIONLIST_HPP

#ifndef __RMOL_RESTRICTIONLIST_HPP
#define __RMOL_RESTRICTIONLIST_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <list>

namespace TRAVEL_CCM {

  /** Forward declarations. */
  class Restriction;

  /** Define a vector (ordered list) of N Restrictions/classes. */
  typedef std::list<Restriction*> RestrictionList_T;
  
}
#endif // __RMOL_RESTRICTIONLIST_HPP

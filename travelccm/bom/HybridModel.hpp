#ifndef __TRAVELCCM_BOM_HYBRIDMODEL_HPP
#define __TRAVELCCM_BOM_HYBRIDMODEL_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// StdAir
#include <stdair/stdair_service_types.hpp>
#include <stdair/bom/TravelSolutionTypes.hpp>

/// Forward declarations
namespace stdair {
  struct BookingRequestStruct;
}

namespace TRAVELCCM {
  
  /**
   * Class implementing the customer choice of cheapest solution.
   */
  class HybridModel {
  public:    
    /**
     * Choose the cheapest travel solution and the fare option
     * within the given list of travel solutions.
     * 
     * We define 3 kinds of customers :
     * 
     *    - the customer does not accept restrictions (change fees and 
     *      non refundable). The fare option must satisfy the hard restriction.
     *
     *    - the customer accepts one restriction. Fare options which do not 
     *      satisfy this restriction have a penalty and fare options which
     *      satisfy the other restriction have a bonus.
     *
     *    - the customer accepts all restrictions. The fare option is 
     *      the cheapest.
     *
     * The returned pointer will be NULL if no travel solution is
     * chosen (e.g. Willingness-To-Pay too low).
     */
    static const stdair::TravelSolutionStruct*
    chooseTravelSolution (stdair::TravelSolutionList_T&,
                          const stdair::BookingRequestStruct&);
  };
}
#endif // __TRAVELCCM_BOM_HYBRIDMODEL_HPP

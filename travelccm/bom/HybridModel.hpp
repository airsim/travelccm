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
   * Class implementing the customer choice of cheapest solution 
   * within disutility.
   */
  class HybridModel {
  public:    
    /**
     * Choose the cheapest travel solution and the fare option
     * within the given list of travel solutions.
     * 
     * Fare options which do not satisfy the restrictions of the customer 
     * have a disutility for each unsatisfied restriction.
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

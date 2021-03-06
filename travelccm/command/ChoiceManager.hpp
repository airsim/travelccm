#ifndef __TRAVELCCM_CMD_CHOICEMANAGER_HPP
#define __TRAVELCCM_CMD_CHOICEMANAGER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// StdAir
#include <stdair/stdair_service_types.hpp>
#include <stdair/bom/TravelSolutionTypes.hpp>
#include <stdair/basic/PassengerChoiceModel.hpp>

/// Forward declarations
namespace stdair {
  struct BookingRequestStruct;
}

namespace TRAVELCCM {
  
  /**
   * Class managing the customer choice model/algorithm.
   */
  class ChoiceManager {
  public:    
    /**
     * Choose the travel solution and the fare option within the given
     * list of travel solutions.
     *
     * The returned pointer will be NULL if no travel solution is
     * chosen (e.g. Willingness-To-Pay too low).
     */
    static const stdair::TravelSolutionStruct*
    chooseTravelSolution (stdair::TravelSolutionList_T&,
                          const stdair::BookingRequestStruct&,
                          const stdair::PassengerChoiceModel::EN_PassengerChoiceModel&);
  };
}
#endif // __TRAVELCCM_CMD_CHOICEMANAGER_HPP

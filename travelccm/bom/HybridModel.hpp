#ifndef __TRAVELCCM_BOM_HYBRIDMODEL_HPP
#define __TRAVELCCM_BOM_HYBRIDMODEL_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TravelCCM
#include <travelccm/bom/CustomerChoiceModel.hpp>

namespace TRAVELCCM {
  
  /**
   * Class implementing the customer choice of cheapest solution 
   * within disutility.
   */
  class HybridModel : public CustomerChoiceModel {
    
  public: 
    /**  
     * Choose a travel solution and a fare option within the given list of 
     * travel solutions.
     * 
     * Fare options which do not satisfy the restrictions of the customer 
     * have a disutility for each unsatisfied restriction.
     * 
     * The returned pointer will be NULL if no travel solution is
     * chosen (e.g. Willingness-To-Pay too low).
     */   
    const stdair::TravelSolutionStruct*
    chooseTravelSolution (stdair::TravelSolutionList_T&,
                          const stdair::BookingRequestStruct&) const;
    
  public:
    /**
     * Default Constructor.
     */ 
    HybridModel ();

  public:
    /**
     * Destructor.
     */
    ~HybridModel ();

  private:
    /** 
     * Static instance of itself.
     */
    static const HybridModel _hybridModel;
  };
}
#endif // __TRAVELCCM_BOM_HYBRIDMODEL_HPP

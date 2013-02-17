#ifndef __TRAVELCCM_BOM_PRICEORIENTEDMODEL_HPP
#define __TRAVELCCM_BOM_PRICEORIENTEDMODEL_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TravelCCM
#include <travelccm/bom/CustomerChoiceModel.hpp>

namespace TRAVELCCM {
  
  /**
   * Class implementing the customer choice of cheapest solution.
   */
  class PriceOrientedModel : public CustomerChoiceModel {  

  public:   
    /**
     * Choose the cheapest travel solution and the fare option
     * within the given list of travel solutions.
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
    PriceOrientedModel ();

  public:
    /**
     * Destructor.
     */
    ~PriceOrientedModel ();

  private:
    /** 
     * Static instance of itself.
     */
    static const PriceOrientedModel _priceOrientedModel;
  };
}
#endif // __TRAVELCCM_BOM_PRICEORIENTEDMODEL_HPP

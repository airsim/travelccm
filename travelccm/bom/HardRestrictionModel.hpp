#ifndef __TRAVELCCM_BOM_HARDRESTRICTIONMODEL_HPP
#define __TRAVELCCM_BOM_HARDRESTRICTIONMODEL_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TravelCCM
#include <travelccm/bom/CustomerChoiceModel.hpp>

namespace TRAVELCCM {
  
  /**
   * Class implementing the hard restriction model.
   */
  class HardRestrictionModel : public CustomerChoiceModel { 

  public:
    /**
     * Choose a travel solution and a fare option within the given list of 
     * travel solutions.
     *     
     * The fare option must satisfy the hard restriction/constrain such as
     * change fees and non refundable.
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
    HardRestrictionModel ();

  public:
    /**
     * Destructor.
     */
    ~HardRestrictionModel ();

  private:
    /** 
     * Static instance of itself.
     */
    static const HardRestrictionModel _hardRestrictionModel;
  };
}
#endif // __TRAVELCCM_BOM_HARDRESTRICTIONMODEL_HPP

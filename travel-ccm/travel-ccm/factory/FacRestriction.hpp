#ifndef __TRAVEL_CCM_FAC_FACRESTRICTION_HPP
#define __TRAVEL_CCM_FAC_FACRESTRICTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class Restriction;
  
  /** Factory for Restriction objects. */
  class FacRestriction : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacRestriction& */
    static FacRestriction& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacRestriction::instance() */
    virtual ~FacRestriction();

    /** Create a new Restriction object.
        <br>This new object is added to the list of instantiated objects.
        @return Restriction& The newly created object. */
    Restriction& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacRestriction () {}

  private:
    /** The unique instance.*/
    static FacRestriction* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACRESTRICTION_HPP


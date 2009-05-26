#ifndef __TRAVEL_CCM_FAC_RESTRICTIONHOLDER_HPP
#define __TRAVEL_CCM_FAC_RESTRICTIONHOLDER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class RestrictionHolder;
  
  /** Factory for RestrictionHolder objects. */
  class FacRestrictionHolder : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacRestrictionHolder& */
    static FacRestrictionHolder& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacRestrictionHolder::instance() */
    virtual ~FacRestrictionHolder();

    /** Create a new RestrictionHolder object.
        <br>This new object is added to the list of instantiated objects.
        @return RestrictionHolder& The newly created object. */
    RestrictionHolder& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacRestrictionHolder () {}

  private:
    /** The unique instance.*/
    static FacRestrictionHolder* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_RESTRICTIONHOLDER_HPP


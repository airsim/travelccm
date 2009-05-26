#ifndef __TRAVEL_CCM_FAC_FACCCM_HPP
#define __TRAVEL_CCM_FAC_FACCCM_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class CCM;
  
  /** Factory for CCM objects. */
  class FacCCM : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacCCM& */
    static FacCCM& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacCCM::instance() */
    virtual ~FacCCM();

    /** Create a new CCM object.
        <br>This new object is added to the list of instantiated objects.
        @return CCM& The newly created object. */
    CCM& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacCCM () {}

  private:
    /** The unique instance.*/
    static FacCCM* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACCCM_HPP


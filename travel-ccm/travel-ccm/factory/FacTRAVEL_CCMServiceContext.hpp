#ifndef __TRAVEL_CCM_FAC_FACTRAVEL_CCMSERVICECONTEXT_HPP
#define __TRAVEL_CCM_FAC_FACTRAVEL_CCMSERVICECONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL-CCM
#include <travel-ccm/TRAVEL_CCM_Types.hpp>
#include <travel-ccm/factory/FacServiceAbstract.hpp>

namespace TRAVEL_CCM {

  /** Forward declarations. */
  class TRAVEL_CCM_ServiceContext;

  /** Factory for Bucket. */
  class FacTRAVEL_CCMServiceContext : public FacServiceAbstract {
  public:

    /** Provide the unique instance.
        <br> The singleton is instantiated when first used
        @return FacServiceContext& */
    static FacTRAVEL_CCMServiceContext& instance();

    /** Destructor.
        <br> The Destruction put the _instance to NULL
        in order to be clean for the next FacServiceContext::instance() */
    virtual ~FacTRAVEL_CCMServiceContext();

    /** Create a new ServiceContext object.
        <br>This new object is added to the list of instantiated objects.
        @return ServiceContext& The newly created object. */
    TRAVEL_CCM_ServiceContext& create ();

    
  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacTRAVEL_CCMServiceContext () {}

  private:
    /** The unique instance.*/
    static FacTRAVEL_CCMServiceContext* _instance;

  };
}
#endif // __TRAVEL_CCM_FAC_FACTRAVEL_CCMSERVICECONTEXT_HPP

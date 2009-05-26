#ifndef __TRAVEL_CCM_FAC_FACREQUEST_HPP
#define __TRAVEL_CCM_FAC_FACREQUEST_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class Request;
  
  /** Factory for Request objects. */
  class FacRequest : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacRequest& */
    static FacRequest& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacRequest::instance() */
    virtual ~FacRequest();

    /** Create a new Request object.
        <br>This new object is added to the list of instantiated objects.
        @return Request& The newly created object. */
    Request& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacRequest () {}

  private:
    /** The unique instance.*/
    static FacRequest* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACREQUEST_HPP


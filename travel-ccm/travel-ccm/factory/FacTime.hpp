#ifndef __TRAVEL_CCM_FAC_FACTIME_HPP
#define __TRAVEL_CCM_FAC_FACTIME_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class Time;
  
  /** Factory for Time objects. */
  class FacTime : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacTime& */
    static FacTime& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacTime::instance() */
    virtual ~FacTime();

    /** Create a new Time object.
        <br>This new object is added to the list of instantiated objects.
        @return Time& The newly created object. */
    Time& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacTime () {}

  private:
    /** The unique instance.*/
    static FacTime* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACTIME_HPP


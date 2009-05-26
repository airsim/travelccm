#ifndef __TRAVEL_CCM_FAC_FACAIRLINE_HPP
#define __TRAVEL_CCM_FAC_FACAIRLINE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class Airline;
  
  /** Factory for Airline objects. */
  class FacAirline : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacAirline& */
    static FacAirline& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacAirline::instance() */
    virtual ~FacAirline();

    /** Create a new Airline object.
        <br>This new object is added to the list of instantiated objects.
        @return Airline& The newly created object. */
    Airline& create ();

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacAirline () {}

  private:
    /** The unique instance.*/
    static FacAirline* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACAIRLINE_HPP


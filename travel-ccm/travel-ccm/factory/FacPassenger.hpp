#ifndef __TRAVEL_CCM_FAC_FACPASSENGER_HPP
#define __TRAVEL_CCM_FAC_FACPASSENGER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
#include <travel-ccm/factory/FacRequest.hpp>


namespace TRAVEL_CCM {
  // Forward declarations.
  class Passenger;
  class RestrictionHolder;
  
  /** Factory for Passenger objects. */
  class FacPassenger : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacPassenger& */
    static FacPassenger& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacPassenger::instance() */
    virtual ~FacPassenger();

    /** Create a new Passenger object.
        <br>This new object is added to the list of instantiated objects.
        @return Passenger& The newly created object. */
    Passenger& create ();
    Passenger& create (Request&, std::string);

    /** Link the passenger with his restriction holder. */
    void linkPassengerWithRestrictionHolder (Passenger&, RestrictionHolder&);

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacPassenger () {}

  private:
    /** The unique instance.*/
    static FacPassenger* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACPASSENGER_HPP


#ifndef __TRAVEL_CCM_BOM_PASSENGER_HPP
#define __TRAVEL_CCM_BOM_PASSENGER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVEL_CCM 
#include <travel-ccm/bom/BomAbstract.hpp>
//#include <travel-ccm/bom/RestrictionHolder.hpp>

namespace TRAVEL_CCM {
  //forward declaration
  class Request; 

  /** Object description here. */
  class Passenger : public BomAbstract {
    friend class FacPassenger;
  public:

    // /////////// Display support methods /////////
    /** Dump a Business Object into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a Business Object from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream& ioIn);

    /////////////////////// Getters ////////////////
    /** Get the serialised version of the Business Object. */
    std::string toString() const;
    
    /** Get a string describing the whole key (differentiating two objects
        at any level). */
    const std::string describeKey() const;

    /** Get a string describing the short key (differentiating two objects
        at the same level). */
    const std::string describeShortKey() const;

    /** Get the type of the passenger  */
    const std::string getPassengerType() const;

    /** to get the oredered list of restrictions of the passenger,
        regarding his type */
    RestrictionHolder& getPassengerRestrictions () ;

    //////////////////// Setters ///////////////////
    /** Add a restriction to the restriction holder. */
    void addRestriction (const Restriction&);

  private:
    /** A passenger is caracterized by both its type and booking request when
        simulated */
    Request* _request;
    std::string _passengerType;
    RestrictionHolder* _passengerRestrictions;
    
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    Passenger ();
    Passenger (Request&, std::string);
    Passenger (const Passenger&);

    /** Destructor. */
    ~Passenger();

  };

}
#endif  //__TRAVEL_CCM_BOM_PASSENGER_HPP


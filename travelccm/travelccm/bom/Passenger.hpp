#ifndef __TRAVELCCM_BOM_PASSENGER_HPP
#define __TRAVELCCM_BOM_PASSENGER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// StdAir
#include <stdair/STDAIR_Types.hpp>
#include <stdair/basic/PassengerType.hpp>
// TravelCCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/bom/BomAbstract.hpp>

namespace TRAVELCCM {
  //forward declaration
  class Restriction;
  class RestrictionHolder;
  class Request;
  class DepartureTimePreferencePattern;

  /** this class gathers the information on the passenger who do the booking
      request. It stores the required information to know the customer's choice
      of a travel solution. */
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

    /** Intialize the pointer at the beginning of the retriction holder */
    void begin();

    /** Get the type of the passenger  */
    const stdair::PassengerType& getPassengerType() const;

    /** to get the ordered list of restrictions of the passenger,
        regarding his type */
    RestrictionHolder& getPassengerRestrictions () ;
    
    /** to get the request done by a passenger */
    Request& getPassengerRequest () ;

    /** Get the two points in the map of DepartureTimePreferencePattern which
        are just under the desired departure time of the passenger (in order to
        use a linear regression) */
    const DurationPair_T getLowerPair(DateTime_T departureTime) const;

    /** Get the two points in the map of DepartureTimePreferencePattern which
        are just above the desired departure time of the passenger (in order to
        use a linear regression) */
    const DurationPair_T getUpperPair(DateTime_T departureTime) const;

    /** Get the lower time duration associated to the passenger */
    const Duration_T getLowerBound(DateTime_T departureTime) const;

    /** Get the upper time duration associated to the passenger */
    const Duration_T getUpperBound(DateTime_T departureTime) const;

    /** To get the departure window of the passenger, that is the time interval
        in which he is ready to leave */
    const DateTimePair_T getDepartureWindow () const;

    // functions unsed to lighten the operations on the duration times
    /** retrieve the middle duration time regarding the formula:
        (1 - ratio) * 1stDT + ratio * 2ndDT */
    static const Duration_T computeMiddleDuration (long, long, double);

    /** Add a restriction to the restriction holder. */
    void addRestriction (const Restriction&);


  private:
    /** A passenger is caracterised by both its type and its request
        when simulated; from those characteristics we will build his/her
        departureTimePreferencePattern and his/her restriction list. */
    stdair::PassengerType _passengerType;
    Request* _request;
    DepartureTimePreferencePattern* _departureTimePreferencePattern;
    RestrictionHolder* _passengerRestrictions;
    
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    Passenger ();
    Passenger (const Passenger&);
    Passenger (const stdair::PassengerType&);

    /** Destructor. */
    ~Passenger();

  };

}
#endif  //__TRAVELCCM_BOM_PASSENGER_HPP


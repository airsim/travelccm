#ifndef __TRAVEL_CCM_BOM_TRAVELSOLUTION_HPP
#define __TRAVEL_CCM_BOM_TRAVELSOLUTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVEL_CCM 
#include <travel-ccm/bom/BomAbstract.hpp>
#include <travel-ccm/bom/Time.hpp>

namespace TRAVEL_CCM {

  /** Object description here. */
  class TravelSolution : public BomAbstract {
    friend class FacTravelSolution;
  public:

    // /////////// Display support methods /////////
    /** Dump a Business Object into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a Business Object from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream& ioIn);

   /** Get the serialised version of the Business Object. */
    std::string toString() const;
    
    /** Get a string describing the whole key (differentiating two objects
        at any level). */
    const std::string describeKey() const;

    /** Get a string describing the short key (differentiating two objects
        at the same level). */
    const std::string describeShortKey() const;

    /** all the get methods for the different fields */
    const std::string  getDepartureAirport() const;
    const std::string  getArrivalAirport() const;
    const Time getDepartureTime() const;
    const Time getArrivalTime() const;
    const Time getDuration() const;
    const bool getRefundable() const;
    const std::string getAirlineName() const;
    const std::string getCabin() const;
    const int  getFlightNumber() const;
    const double getFare() const;
    const int  getNumberOfLags() const;
    const bool getSaturdayNightStay() const;
    const bool getChangeable() const;

  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    TravelSolution ();
    TravelSolution (const TravelSolution&);
    TravelSolution (std::string dAirport, std::string aAirport, Time depTime,
                    Time arTime, Time dur, bool Ref, std::string airline,
                    std::string cabin, int flightNum, double fare, int lagsNum,
                    bool SNS, bool change);

    /** Destructor. */
    virtual ~TravelSolution();

  private:
    /** all the characteristics of a flight required to implement a customer
        choice model, that is its leg, its schedule, its refundability,
        the airline, the cabin, the fare, the lags, saturday night stay,
        the change fee... */
    std::string _departureAirport;
    std::string _arrivalAirport;
    Time _departureTime;
    Time _arrivalTime;
    Time _duration;
    bool _refundable;
    std::string _airlineName;
    std::string _cabinName;
    int _flightNumber;
    double _fare;
    int _numberOfLags;
    bool _saturdayNightStay;
    bool _changeable;
    
  };

}
#endif // __TRAVEL_CCM_BOM_TRAVELSOLUTION_HPP


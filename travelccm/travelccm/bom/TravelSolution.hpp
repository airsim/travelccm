#ifndef __TRAVELCCM_BOM_TRAVELSOLUTION_HPP
#define __TRAVELCCM_BOM_TRAVELSOLUTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// TRAVELCCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/bom/BomAbstract.hpp>
#include <travelccm/bom/Restriction.hpp>

namespace TRAVELCCM {

  /** This class represents a travel solution, more precisely the fields
    of a travel solution mandatory so that to implement a customer choice
    model.
    An example is NCE-LHR; 01-JUN-2009; 12:00 - 14:00 (02:00); refundable;
    AF404; ECO; 200.0E; 0 stop; saturday night stay (mandatory); changeable;
  */
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
    const Date_T  getDepartureDate() const;
    const Duration_T getDepartureTime() const;
    const Duration_T getArrivalTime() const;
    const Duration_T getDuration() const;
    const bool getRefundable() const;
    const std::string getAirlineName() const;
    const std::string getCabin() const;
    const int  getFlightNumber() const;
    const double getFare() const;
    const int  getNumberOfLags() const;
    const bool getSaturdayNightStay() const;
    const bool getChangeable() const;
    const std::string getId() const;


    /* returns if the restriction put in arguent meets the current
       travel solution */
    bool restrictionMeetsTravelSolution (const Restriction&) const;

  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    TravelSolution ();
    TravelSolution (const TravelSolution&);
    TravelSolution (const std::string& iDepartureAirport,
                    const std::string& iArrivalAirport,
                    const Date_T& iDepartureDate,
                    const Duration_T& iDepartureTime,
                    const Duration_T& iArrivalTime,
                    const Duration_T& iDuration,
                    const bool iRefundability,
                    const std::string& iAirlineCode,
                    const std::string& iCabinCode,
                    const int& iFlightNumber,
                    const double& iFare, int& iStopsNumber,
                    bool iSNS, bool iChangeability, const std::string& id);

    /** Destructor. */
    virtual ~TravelSolution();

  private:
    /** all the characteristics of a flight required to implement a customer
        choice model, that is its leg, its schedule, its refundability,
        the airline, the cabin, the fare, the lags, saturday night stay,
        the change fee... */
    std::string _departureAirport;
    std::string _arrivalAirport;
    boost::gregorian::date _departureDate;
    Duration_T _departureTime;
    Duration_T _arrivalTime;
    Duration_T _duration;
    bool _refundable;
    std::string _airlineName;
    std::string _cabinName;
    int _flightNumber;
    double _fare;
    int _numberOfLags;
    bool _saturdayNightStay;
    bool _changeable;
    std::string id;
    
  };

}
#endif // __TRAVELCCM_BOM_TRAVELSOLUTION_HPP


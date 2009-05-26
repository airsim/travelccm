// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/TravelSolution.hpp>

namespace TRAVEL_CCM {

  // ////////////////////////////////////////////////////////////////////
  TravelSolution::TravelSolution (std::string dAirport, std::string aAirport,
                                  Time depTime, Time arTime, Time dur,
                                  bool Ref, std::string airline,
                                  std::string cabin,
                                  int flightNum, double fare, int lagsNum,
                                  bool SNS, bool change){

     _departureAirport = dAirport;
     _arrivalAirport = aAirport;
     _departureTime = DepTime;
     _arrivalTime = arTime;
     _duration = dur;
     _refundable = Ref;
     _airlineName = airline;
     _cabinName = cabin;
     _flightNumber = flightNum;
     _fare = fare;
     _numberOfLags = lagsNum;
     _saturdayNightStay = SNS;
     _changeable = change;
    

    }

  // ////////////////////////////////////////////////////////////////////
  TravelSolution::~TravelSolution () {
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolution::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolution::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string TravelSolution::toString() const {
    std::string oString;

    return oString;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

   // //////////////////////////////////////////////////////////////////////
  const std::string  TravelSolution::getDepartureAirport() const {
    assert (_departureAirport != NULL);
    return _departureAirpot;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string  TravelSolution::getArrivalAirport() const {
    assert (_arrivalAirport != NULL);
    return _arrivalAirpot;
  }

  // //////////////////////////////////////////////////////////////////////
  const Time  TravelSolution::getDepartureTime() const {
    assert (_departureTime != NULL);
    return _departureTime;
  }

  // //////////////////////////////////////////////////////////////////////
  const Time  TravelSolution::getArrivalTime() const {
    assert (_arrivalTime != NULL);
    return _arrivalTime;
  }

  // //////////////////////////////////////////////////////////////////////
  const Time  TravelSolution::getDuration() const {
    assert (_duration != NULL);
    return _duration;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool  TravelSolution::getRefundable() const {
    assert (_refundable != NULL);
    return _refundable;
  } 

  // //////////////////////////////////////////////////////////////////////
  const std::string  TravelSolution::getAirlineName() const {
    assert (_airlineName != NULL);
    return _airlineName;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::getCabin() const {
    return _cabinName;
  }

  // //////////////////////////////////////////////////////////////////////
  const int  TravelSolution::getFlightNumber() const {
    assert (_flightNumber != NULL);
    return _flightNumber;
  }

  // //////////////////////////////////////////////////////////////////////
  const double  TravelSolution::getFare() const {
    assert (_fare != NULL);
    return _fare;
  }
  
  // //////////////////////////////////////////////////////////////////////
  const int  TravelSolution::getNumberOfLags() const {
    assert (_numberOfLags != NULL);
    return _numberOfLags;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool TravelSolution::getSaturdayNightStay() const {
    assert (_saturdayNightStay != NULL);
    return _saturdayNightStay;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool TravelSolution::getChangeable() const {
    assert (_changeable != NULL);
    return _changeable;
  }

    
}


// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
// TRAVELCCM 
#include <travelccm/bom/Restriction.hpp>
#include <travelccm/bom/TravelSolution.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  TravelSolution::TravelSolution (std::string& dAirport, std::string& aAirport,
                                  Date_T depDate,
                                  Duration_T& depTime, Duration_T& arTime, 
                                  Duration_T& dur, bool Ref,
                                  std::string& airline, std::string& cabin,
                                  int& flightNum, double& fare, int& lagsNum,
                                  bool SNS, bool change)
    : _departureAirport (dAirport), _arrivalAirport (aAirport),
      _departureDate (depDate), _departureTime (depTime), 
      _arrivalTime (arTime), _duration (dur), _refundable (Ref),
      _airlineName (airline), _cabinName (cabin), _flightNumber (flightNum),
      _fare (fare), _numberOfLags (lagsNum), _saturdayNightStay (SNS),
      _changeable (change) {
    }

  // /////////////////////////////////////////////////////////////////////
  TravelSolution::TravelSolution () {
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
    std::ostringstream oString;
    oString << "travel solution: (" << _departureAirport << ", "
            << _arrivalAirport << ") ; departure date: "
            << boost::gregorian::to_simple_string(_departureDate) << "; "
            << _numberOfLags << " stop(s); "
            << "flight " << _airlineName << _flightNumber << "; "
            << "departure time: " << _departureTime << ", arrival time: "
            << _arrivalTime << ", duration: " << _duration << "; " << "cabin: "
            << _cabinName << "; ";

    if (_refundable) {
     oString << "refundable fare; ";
    } else {
     oString << "nonrefundable fare; ";
    }
    
    if (_changeable) {
      oString << "changeable fare; ";
    } else {
      oString << "nonchangeable fare; ";
    }
    
    if (_saturdayNightStay) {
      oString << "Saturday Night Stay mandatory; ";
    } else {
      oString << "Saturday Night Stay non mandatory; ";
    }
    
    oString << "price: " << _fare <<  std::endl;
    
    return oString.str();
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
  const std::string TravelSolution::getDepartureAirport() const {
    return _departureAirport;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::getArrivalAirport() const {
    return _arrivalAirport;
  }

  // //////////////////////////////////////////////////////////////////////
  const Date_T TravelSolution::getDepartureDate() const {
    return _departureDate;
  }
  
  // //////////////////////////////////////////////////////////////////////
  const Duration_T TravelSolution::getDepartureTime() const {
    return _departureTime;
  }

  // //////////////////////////////////////////////////////////////////////
  const Duration_T TravelSolution::getArrivalTime() const {
    return _arrivalTime;
  }

  // //////////////////////////////////////////////////////////////////////
  const Duration_T TravelSolution::getDuration() const {
    return _duration;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool TravelSolution::getRefundable() const {
    return _refundable;
  } 

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::getAirlineName() const {
    return _airlineName;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolution::getCabin() const {
    return _cabinName;
  }

  // //////////////////////////////////////////////////////////////////////
  const int  TravelSolution::getFlightNumber() const {
    return _flightNumber;
  }

  // //////////////////////////////////////////////////////////////////////
  const double  TravelSolution::getFare() const {
    return _fare;
  }
  
  // //////////////////////////////////////////////////////////////////////
  const int  TravelSolution::getNumberOfLags() const {
    return _numberOfLags;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool TravelSolution::getSaturdayNightStay() const {
    return _saturdayNightStay;
  }

  // //////////////////////////////////////////////////////////////////////
  const bool TravelSolution::getChangeable() const {
    return _changeable;
  }

  // /////////////////////////////////////////////////////////////////////
  bool TravelSolution::restrictionMeetsTravelSolution (Restriction& res) const {
    bool oRestrictionMatchesTravelSolution = true;
    
    /** Need to consider all the different kinds of restriction in a
        separate way
    */
    if (res.getRestrictionType() == "refundability") {
      return getRefundable();
    }

    if (res.getRestrictionType() == "preferredAirline") {
      // Be careful on how you write the airline (airline code or no?)
      if (getAirlineName() != res.getPreferredAirline() ) {
        oRestrictionMatchesTravelSolution = false;
      }

      return oRestrictionMatchesTravelSolution;
    }

    if (res.getRestrictionType() == "preferredCabin") {
      /* Today we look for the perfect match. A better solution would be
         to allow thee overclassing */
      if (getCabin() != res.getPreferredCabin() ) {
        oRestrictionMatchesTravelSolution = false;
      }

      return oRestrictionMatchesTravelSolution;
    }
    
    /** The function returns true by default in order not to loose any
        correct travel solution */
    return oRestrictionMatchesTravelSolution;
  }
    
}


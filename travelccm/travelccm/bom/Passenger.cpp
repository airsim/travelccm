// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
// TRAVELCCM 
#include <travelccm/bom/Passenger.hpp>
#include <travelccm/bom/Request.hpp>
#include <travelccm/bom/DepartureTimePreferencePattern.hpp>
#include <travelccm/bom/RestrictionHolder.hpp>
#include <travelccm/bom/Restriction.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  Passenger::Passenger () {
    _passengerType = "NONE";
    _passengerRestrictions = NULL;
    _request = NULL;
    _departureTimePreferencePattern = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  Passenger::Passenger (std::string passType) {
    _passengerType = passType;
    /* For the moment, only 2 different types of passengers are implemented;
       business and leisure.
       But we can imagine as many types as possible to reflect the different
       buyer profiles*/
    /* We create a list of restrictions void, and we add the different elements
       of the list when building the different objects, in service or command
    */ 
    _passengerRestrictions = NULL;
    _request = NULL;
    _departureTimePreferencePattern = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  Passenger::~Passenger () {
  }

  // //////////////////////////////////////////////////////////////////////
  void Passenger::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void Passenger::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string Passenger::toString() const {
    std::ostringstream oString;
    oString << "passenger of type: " << _passengerType << ";";
    if (_request != NULL) {
      oString << "passenger's request: " << _request->toString() << ";";
    }
    if (_passengerRestrictions != NULL) {
      oString << "passenger's restrictions: "
              << _passengerRestrictions->toString() << ";";
    }
    if (_departureTimePreferencePattern != NULL) {
      oString << "passenger's departure time preference pattern: "
              << _departureTimePreferencePattern->toString() << ";";
    }
    return oString.str();
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string Passenger::describeKey() const {
    std::string oKey;
    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string Passenger::describeShortKey() const {
    std::string oKey;
    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  void Passenger::begin() {
    _passengerRestrictions->begin();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string  Passenger::getPassengerType() const {
    return _passengerType;
  }

  // /////////////////////////////////////////////////////////////////////
  const DateTimePair_T Passenger::getDepartureWindow() const {
    assert (_request != NULL);
    DateTime_T departureTime = _request->getDepartureTime();
    Duration_T lowerBound = getLowerBound();
    Duration_T upperBound = getUpperBound();
    DateTime_T lowerBoundDateTime = departureTime - lowerBound;
    DateTime_T upperBoundDateTime = departureTime + upperBound;
    DateTimePair_T oDateTimePair(lowerBoundDateTime, upperBoundDateTime);
    return oDateTimePair;
  }

  // /////////////////////////////////////////////////////////////////////
  const Duration_T& Passenger::getLowerBound() const {
    // retrieve the lower time duration, that is the 
    const DurationPair_T& lowerPair = getLowerPair();
    const Duration_T lowerDurationTime = lowerPair.first;
    // retrieve the upper time duration
    const DurationPair_T& upperPair = getUpperPair();
    const Duration_T upperDurationTime = upperPair.first;
    // retrieve the time of the day when the passenger wants to leave
    assert (_request != NULL);
    const DateTime_T departureTime = _request->getDepartureTime();
    const Duration_T timeOfDay = departureTime.time_of_day();
    // calculus of the lower bound of the departure window
    // we use a linear regression to determine the lower boudn of the departure
    // window.
    // we put all the time durations in seconds to determine the ratio:
    long lowestHourInSeconds = 3600 * timeOfDay.hours();
    long uppestHourInSeconds = 3600 * (timeOfDay.hours() + 1); // +1h
    long timeOfDayInSeconds = timeOfDay.total_seconds();
    double ratio = (timeOfDayInSeconds - lowestHourInSeconds) /
      (uppestHourInSeconds - lowestHourInSeconds);
    const Duration_T& oDurationTime =
      computeMiddleDuration(lowestHourInSeconds, uppestHourInSeconds, ratio);
    return oDurationTime;
  }

  // /////////////////////////////////////////////////////////////////////
  const Duration_T& Passenger::getUpperBound() const {
    // retrieve the lower time duration, that is the 
    const DurationPair_T& lowerPair = getLowerPair();
    const Duration_T lowerDurationTime = lowerPair.second;
    // retrieve the upper time duration
    const DurationPair_T& upperPair = getUpperPair();
    const Duration_T upperDurationTime = upperPair.second;
    // retrieve the time of the day when the passenger wants to leave
    assert (_request != NULL);
    const DateTime_T departureTime = _request->getDepartureTime();
    const Duration_T timeOfDay = departureTime.time_of_day();
    // calculus of the upper bound of the departure window
    // we use a linear regression to determine the upper boudn of the departure
    // window.
    // we put all the time durations in seconds to determine the ratio:
    long lowestHourInSeconds = 3600 * timeOfDay.hours();
    long uppestHourInSeconds = 3600 * (timeOfDay.hours() + 1); // +1h
    long timeOfDayInSeconds = timeOfDay.total_seconds();
    double ratio = (timeOfDayInSeconds - lowestHourInSeconds) /
      (uppestHourInSeconds - lowestHourInSeconds);
    const Duration_T& oDurationTime =
      computeMiddleDuration(lowestHourInSeconds, uppestHourInSeconds, ratio);
    return oDurationTime;
  }

  // //////////////////////////////////////////////////////////////////////
  const Duration_T& Passenger::
  computeMiddleDuration (long firstDurationInSeconds,
                         long secondDurationInSeconds, double ratio) {
    double finalResultInSeconds = (1 - ratio) * firstDurationInSeconds +
      ratio * secondDurationInSeconds;
    const Duration_T& oDurationTime =
      boost::posix_time::seconds((int)finalResultInSeconds);
    return oDurationTime;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const DurationPair_T& Passenger::getLowerPair() const {
    assert (_departureTimePreferencePattern != NULL);
    // get the passenger's date-time of departure
    const DateTime_T departureTime = _request->getDepartureTime();
    // get the lower and upper bounds of the window
    const Duration_T timeOfDay = departureTime.time_of_day();
    const long nbOfHours = timeOfDay.hours();
    /* from the number of hours, we retrieve the lower bound
       in the map in DepartureTimePreferencePattern */
    const Duration_T lowerBound (nbOfHours, 0, 0);
    const DurationPair_T& lowerPair =
      _departureTimePreferencePattern->getDurationPair(lowerBound);
    return lowerPair;
  }

  // //////////////////////////////////////////////////////////////////////
  const DurationPair_T& Passenger::getUpperPair() const {
    assert (_departureTimePreferencePattern != NULL);
    // get the passenger's date-time of departure
    const DateTime_T departureTime = _request->getDepartureTime();
    // get the lower and upper bounds of the window
    const Duration_T timeOfDay = departureTime.time_of_day();
    const long nbOfHours = timeOfDay.hours();
    /* from the number of hours, we retrieve the upper bound
       in the map in DepartureTimePreferencePattern */
    const Duration_T upperBound (nbOfHours+1, 0, 0);
    const DurationPair_T& upperPair =
      _departureTimePreferencePattern->getDurationPair(upperBound);
    return upperPair;
  }

  // /////////////////////////////////////////////////////////////////////
  RestrictionHolder& Passenger::getPassengerRestrictions() {
    /* the preferrence order, that is the PreferenceList, depends
       on the passenger type;
       See the constructor where the list of restrictions are attributed
       to each type of passenger
    */
    return *_passengerRestrictions;
  }

  // /////////////////////////////////////////////////////////////////////
  Request& Passenger::getPassengerRequest() {
    return *_request;
  }

  ///////////////////////////////////////////////////////////////////////
  void Passenger::addRestriction (const Restriction& iRestriction) {
    assert (_passengerRestrictions != NULL);
    _passengerRestrictions->addRestriction (iRestriction);
  }
  
}


// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <sstream>
#include <iostream>
#include <stdexcept>
// BOOST
#include <boost/date_time/posix_time/posix_time.hpp>
// TRAVELCCM
#include <travelccm/basic/BasConst_TimePattern.hpp>
#include <travelccm/bom/DepartureTimePreferencePattern.hpp>

namespace TRAVELCCM {

  // //////////////////////////////////////////////////////////////////////
  DepartureTimePreferencePattern:: DepartureTimePreferencePattern
  (const PatternId_T& iDepartureTimePreferencePatternId)
    :_departureTimePreferencePatternId (iDepartureTimePreferencePatternId) {
    if (_departureTimePreferencePatternId == "B" ) {
      /*_departureTimePreferencePattern.
        insert(std::pair(time_duration td(0,0,0),
                         std::pair(time_duration td(1,0,0),
                         time_duration td(1,0,0))));*/
      Duration_T lowerBound(1,0,0);
      Duration_T upperBound(1,0,0);
      DurationPair_T p(lowerBound, upperBound);
      boost::posix_time::time_duration timeOfDay(0,0,0);
      std::pair<Duration_T,DurationPair_T> patternElement(timeOfDay,p);
      _departureTimePreferencePattern.insert(patternElement);
    }
    else if (_departureTimePreferencePatternId == "L") {
      // _departureTimePreferencePattern = ;
    }
  }

  // //////////////////////////////////////////////////////////////////////
  DepartureTimePreferencePattern::~DepartureTimePreferencePattern () {
  }
  
  // //////////////////////////////////////////////////////////////////////
  void DepartureTimePreferencePattern::toStream (std::ostream& ioOut) const {
  }
  
  // //////////////////////////////////////////////////////////////////////
  void DepartureTimePreferencePattern::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string DepartureTimePreferencePattern::toString() const {
    std::string oString;
    
    return oString;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string DepartureTimePreferencePattern::describeShortKey() const {
    std::string oKey;

    return oKey;
  }
  
  // //////////////////////////////////////////////////////////////////////
  const std::string DepartureTimePreferencePattern::describeKey() const {
    // Store current formatting flags of std::cout
    std::ios::fmtflags oldFlags = std::cout.flags();

    std::ostringstream ostr;

    ostr << _departureTimePreferencePatternId << " ";
      
    // Reset formatting flags of std::cout
    std::cout.flags (oldFlags);

    return ostr.str();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string DepartureTimePreferencePattern::display() const {

    // Store current formatting flags of std::cout
    std::ios::fmtflags oldFlags = std::cout.flags();

    std::ostringstream ostr;

    ostr << "Departure Time Preference ID: " << describeKey() << ": ";
    /*
    for (DepartureTimePreferencePattern_T::const_iterator
           itTimePreference = _departureTimePreference.begin();
         itTimePreference != _departureTimePreference.end();
         itTimePreference++) {
      const Duration_T& lTimeOfDay = itTimePreference->first;
      const DurationPair_T& lDurationPair = itTimePreference->second;
      const Duration_T& lLowerBound = lDurationPair.first;
      const Duration_T& lUpperBound = lDurationPair.second;
       
      ostr << boost::posix_time::time_duration::to_simple_string (lTimeOfDay)
           << " "
           << lCancellationRate << "% "
           << lNoShowRate <<  "%; ";       
    }
    */
    ostr << std::endl;

    // Reset formatting flags of std::cout
    std::cout.flags (oldFlags);

    return ostr.str();
  }

}

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/Time.hpp>

namespace TRAVEL_CCM {
  
  // ////////////////////////////////////////////////////////////////////
  Time::Time (int h, int m) {
    _hour = h;
    _min = m;
  }

  // ////////////////////////////////////////////////////////////////////
  Time::~Time () {
  }

  // //////////////////////////////////////////////////////////////////////
  void Time::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void Time::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string Time::toString() const {
    std::string oString;

    return oString;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string Time::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string Time::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

}


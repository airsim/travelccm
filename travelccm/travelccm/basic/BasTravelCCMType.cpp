// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
// TravelCCM
#include <travelccm/basic/BasTravelCCMType.hpp>

namespace TRAVELCCM {

  // //////////////////////////////////////////////////////////////////////
  const std::string BasTravelCCMType::CCMTypes[BasTravelCCMType::LAST_VALUE] =
    {"Pref-based", "Logit"};
    
  // //////////////////////////////////////////////////////////////////////
  BasTravelCCMType::BasTravelCCMType () : _type (PREF_BASED) {
    assert (false);
  }
  
  // //////////////////////////////////////////////////////////////////////
  BasTravelCCMType::BasTravelCCMType (const BasTravelCCMType& iCCMType)
  : _type (iCCMType._type) {
  }
  
  // //////////////////////////////////////////////////////////////////////
  BasTravelCCMType::BasTravelCCMType (const EN_CCMType& iCCMType)
    : _type (iCCMType) {
  }
  
  // //////////////////////////////////////////////////////////////////////
  BasTravelCCMType::~BasTravelCCMType () {
  }
  
  // //////////////////////////////////////////////////////////////////////
  void BasTravelCCMType::toStream (std::ostream& ioOut) const {
    ioOut << toString();
  }

  // //////////////////////////////////////////////////////////////////////
  void BasTravelCCMType::fromStream (std::istream&) {
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string BasTravelCCMType::describe() const {
    return toString();
  }
  
  // //////////////////////////////////////////////////////////////////////
  std::string BasTravelCCMType::toShortString() const {
    std::ostringstream oStr;
    oStr << CCMTypes[_type];
    return oStr.str();
  }
    
  // //////////////////////////////////////////////////////////////////////
  std::string BasTravelCCMType::toString() const {
    std::ostringstream oStr;
    oStr << CCMTypes[_type];
    return oStr.str();
  }
    
}
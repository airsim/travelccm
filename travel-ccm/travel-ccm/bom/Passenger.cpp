// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/Passenger.hpp>

namespace TRAVEL_CCM {
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
    std::string oString;

    return oString;
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
  const std::string  Passenger::getPassengerType() const {
    return _passengerType;
  }

  // /////////////////////////////////////////////////////////////////////
  /*const RestrictionList Passenger::getPassengerRestriction() const {
      the preferrence order, that is the PreferenceList, depends
        on the passenger type 
    if (getPassengerType() == "B1"){
      return NULL;
        }
    else if (getPassengerType() == "B2"){
      return NULL;
        }
    else if (getPassengerType() == "E1"){
      return NULL;
        }
    else if (getPassengerType() == "E2"){
      return NULL;
        }
    else
    the moment, only 4 different types of pasenger are implemented.
        We could imagine as many different types of passengers as we need
        to reflect the different segments 
  }*/
    
  
}


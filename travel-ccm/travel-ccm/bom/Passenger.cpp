// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/Passenger.hpp>

namespace TRAVEL_CCM {

  // ////////////////////////////////////////////////////////////////////
  Passenger::Passenger () {
    _request = NULL;
    _passengerType = "NONE";
    _passengerRestrictions = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  Passenger::Passenger (Request& req, std::string passType) {
    _request = &req;
    _passengerType = passType;
    /* For the moment, only 4 different types of passengers are implemented.
       We could imagine as many different types of passengers as we need
       to reflect the different */
    /* We create a list of restrictions void, and we add the different elements
       of the list when building the different objects, in service or command
    */ 
    _passengerRestrictions = NULL;
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
  RestrictionHolder& Passenger::getPassengerRestrictions() {
    /* the preferrence order, that is the PreferenceList, depends
       on the passenger type;
       See the constructor where the list of restrictions are attributed
       to each type of passenger
    */
    return *_passengerRestrictions;
  }

  ///////////////////////////////////////////////////////////////////////
  void Passenger::addRestriction (const Restriction& iRestriction) {
    _passengerRestrictions->addRestriction (iRestriction);
  }
  
}


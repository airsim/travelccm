// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/Restriction.hpp>

namespace TRAVEL_CCM {

  // /////////////////////////////////////////////////////////////////////
  Restriction:: Restriction(std::string restrictionType){
    _restrictionType = restrictionType;
  }

  
  // ////////////////////////////////////////////////////////////////////
  Restriction::~Restriction () {
  }

  // //////////////////////////////////////////////////////////////////////
  void Restriction::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void Restriction::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string Restriction::toString() const {
    std::string oString;

    return oString;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string Restriction::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string Restriction::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

  // /////////////////////////////////////////////////////////////////////
  const std::string Restriction::getRestrictionType() const{
    return _restrictionType;
  }

  // /////////////////////////////////////////////////////////////////////
  const std::string Restriction::getPreferredAirline() const{
    return _preferredAirline;
  }

  // /////////////////////////////////////////////////////////////////////
  const std::string Restriction::getPreferredCabin() const{
    return _preferredCabin;
  }
  
  // /////////////////////////////////////////////////////////////////////
  bool Restriction::travelSolutionMeetRestriction(TravelSolution& TS){
    /** need to consider all the different kind of restrictions in a
        separate way
    */
    if (getRestrictionType() == "refundability")
      {
      if (TS.getRefundable())
        return true;
      else
        return false;
      }
    else if (getRestrictionType() == "preferredAirline")
      {
        // be careful on how you write the airline (airline code or no?)
        if (TS.getAirlineName() == getPreferredAirline() )
          return true;
        else
          return false;
      }
    else if (getRestrictionType() == "preferredCabin")
      {
        /* today we look for the perfect match. A better solution would be
           to allow thee overclassing */
        if (TS.getCabin() == getPreferredCabin() )
          return true;
        else
          return false;
      }
    /** the function return true by default in order not to loose any
        correct travel solution */
    else return true;
  }


}


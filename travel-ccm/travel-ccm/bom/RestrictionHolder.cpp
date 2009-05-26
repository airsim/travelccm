// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM
#include <travel-ccm/bom/TravelSolution.hpp>
#include <travel-ccm/bom/RestrictionHolder.hpp>

namespace TRAVEL_CCM {
  // ////////////////////////////////////////////////////////////////////
  RestrictionHolder::~RestrictionHolder () {
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string RestrictionHolder::toString() const {
    std::string oString;

    return oString;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string RestrictionHolder::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string RestrictionHolder::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

   // //////////////////////////////////////////////////////////////////////
  Restriction& RestrictionHolder::getCurrentRestriction () const {
    Restriction* resultRestriction_ptr = *_itCurrentRestriction;
    assert (resultRestriction_ptr != NULL);
    
    return (*resultRestriction_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  Restriction& RestrictionHolder::getNextRestriction () const {
    Restriction* resultRestriction_ptr = *_itNextRestriction;
    assert (resultRestriction_ptr != NULL);
    
    return (*resultRestriction_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  Restriction& RestrictionHolder::getTaggedRestriction () const {
    Restriction* resultRestriction_ptr = *_itTaggedRestriction;
    assert (resultRestriction_ptr != NULL);
    
    return (*resultRestriction_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::begin () {
    _itCurrentRestriction = _restrictionList.begin();
    _itNextRestriction = _restrictionList.begin();
    if (_itNextRestriction != _restrictionList.end()) {
      _itNextRestriction++;
    }
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::tag () {
      _itTaggedRestriction = _itCurrentRestriction;
  }

  // //////////////////////////////////////////////////////////////////////
  bool RestrictionHolder::hasNotReachedEnd () const {
    bool result = (_itCurrentRestriction != _restrictionList.end());
    return result;
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::iterate () {
    if (_itCurrentRestriction != _restrictionList.end()) {
      _itCurrentRestriction++;
    }
    if (_itNextRestriction != _restrictionList.end()) {
      _itNextRestriction++;
    }
  }

  // //////////////////////////////////////////////////////////////////////
  bool RestrictionHolder::travelSolutionMeetRestrictionList(TravelSolution& TS){
    /** call a function in the Restriction class which returns if a travel
        solution meets a single restriction */
    Restriction& currentRestriction = getCurrentRestriction();
    Restriction& nextRestriction = getNextRestriction();
    bool curResOK = currentRestriction.travelSolutionMeetRestriction(TS);
    /* if we are at the end of the list, that is the current element is NULL
        we return true because all the restrictions have been matched*/
    if (!hasNotReachedEnd())
      return true;
    /* else, we are not at the end; if the travel solution does not
       match the first restriction */
    else if (!curResOK)
        return false;
    /* if it does, we need to know if the next ones do too */
    else {
      iterate();
      return travelSolutionMeetRestrictionList(TS);
    }
    /* recursive function
       Have to check if it works well !!!!
    */
  }
  
}

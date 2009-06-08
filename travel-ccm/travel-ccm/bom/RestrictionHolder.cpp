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
  RestrictionHolder::RestrictionHolder () {
  }
  
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
    RestrictionList_T::const_iterator it = _restrictionList.begin();
    while (it != _restrictionList.end() ){
      Restriction* res_ptr = *it;
      assert(res_ptr != NULL);
      oString += res_ptr->toString();
      it++;
    }
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

  ///////////////////////////////////////////////////////////////////////
  void RestrictionHolder::addRestriction (Restriction& iRestriction) {
    _restrictionList.push_back (&iRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::begin () {
    _itCurrentRestriction = _restrictionList.begin();
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
  }

  // //////////////////////////////////////////////////////////////////////
  void RestrictionHolder::eraseCurrentRestriction () {
    /* ok even if the list is at the end */
    assert (_itCurrentRestriction != _restrictionList.end());
    _itCurrentRestriction = _restrictionList.erase (_itCurrentRestriction);
  }

  // //////////////////////////////////////////////////////////////////////
  /* bool RestrictionHolder::travelSolutionMeetRestrictionList(TravelSolution& TS){
     * if we are at the end of the list, that is the current element is NULL
        we return true because all the restrictions have been matched
     *
    if (!hasNotReachedEnd()){
      begin();
      return true;
    }
    else {
    ** call a function in the Restriction class which returns if a travel
        solution meets a single restriction *
      const Restriction& currentRestriction = getCurrentRestriction();
      bool curResOK = currentRestriction.travelSolutionMeetRestriction(TS);
      //assert(!curResOK);
      * else, we are not at the end; if the travel solution does not
         match the first restriction *
      if (!curResOK){
        //assert(1==0);
        return false;}
      * if it does, we need to know if the next ones do too *
      else {
        iterate();
        return travelSolutionMeetRestrictionList(TS);
      }
    }
    }*/
  
}

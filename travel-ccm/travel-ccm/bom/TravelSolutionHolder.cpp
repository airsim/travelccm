// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
// TRAVEL_CCM
#include <travel-ccm/bom/TravelSolutionHolder.hpp>

namespace TRAVEL_CCM {

  // ////////////////////////////////////////////////////////////////////
  TravelSolutionHolder::TravelSolutionHolder () {
    
  }
  
  // ////////////////////////////////////////////////////////////////////
  TravelSolutionHolder::~TravelSolutionHolder () {
    _travelSolutionList.clear ();
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string TravelSolutionHolder::toString() const {
    std::string oString;
    TravelSolutionList_T::const_iterator it = _travelSolutionList.begin();
    while (it != _travelSolutionList.end() ){
      TravelSolution* TS_ptr = *it;
      assert(TS_ptr != NULL);
      oString += TS_ptr->toString();
      it++;
    }
    return oString;
  }

  int TravelSolutionHolder::numberOfTravelSolutions() {
    return _travelSolutionList.size();
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolutionHolder::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TravelSolutionHolder::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

   // //////////////////////////////////////////////////////////////////////
  TravelSolution& TravelSolutionHolder::getCurrentTravelSolution () const {
    TravelSolution* resultTravelSolution_ptr = *_itCurrentTravelSolution;
    assert (resultTravelSolution_ptr != NULL);
    
    return (*resultTravelSolution_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::begin () {
    _itCurrentTravelSolution = _travelSolutionList.begin();
  }

  // //////////////////////////////////////////////////////////////////////
  bool TravelSolutionHolder::hasNotReachedEnd () const {
    bool result = (_itCurrentTravelSolution != _travelSolutionList.end());
    return result;
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::iterate () {
    if (_itCurrentTravelSolution != _travelSolutionList.end()) {
      _itCurrentTravelSolution++;
    }
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::addTravelSolution (TravelSolution& TS) {
    _travelSolutionList.push_back(&TS);
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::eraseCurrentTravelSolution () {
    /* ok even if the list is at the end */
    assert (_itCurrentTravelSolution != _travelSolutionList.end());
    _itCurrentTravelSolution = _travelSolutionList.erase (_itCurrentTravelSolution);
  }
  
  // //////////////////////////////////////////////////////////////////////
  bool TravelSolutionHolder::restrictionMeetsTSList(Restriction& restriction) {
     /* if we are at the end of the list, we return true because all
        the travel solutions have been matched
     */
    if (!hasNotReachedEnd()){
      begin();
      return true;
    }
    else {
    /** call a function in the TravelSolution class which returns if a
        restriction meets a single travel solution */
      const TravelSolution& currentTravelSolution = getCurrentTravelSolution();
      bool curTSOK =
        currentTravelSolution.restrictionMeetsTravelSolution(restriction);
      /* else, we are not at the end; if the restriction does not
         match the first travel solution */
      if (!curTSOK){
        return false;}
      /* if it does, we need to know if the next ones do too */
      else {
        iterate();
        return restrictionMeetsTSList(restriction);
      }
    }
  }

}


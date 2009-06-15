// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iostream>
#include <iomanip>
// TRAVELCCM
#include <travelccm/bom/Restriction.hpp>
#include <travelccm/bom/TravelSolution.hpp>
#include <travelccm/bom/TravelSolutionHolder.hpp>
#include <travelccm/service/Logger.hpp>

namespace TRAVELCCM {

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

  // ////////////////////////////////////////////////////////////////////////
  int TravelSolutionHolder::numberOfTravelSolutions() {
    return _travelSolutionList.size();
  }

  // ////////////////////////////////////////////////////////////////////////
  bool TravelSolutionHolder::isVoid() {
    return (numberOfTravelSolutions() == 0);
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
    // TODO: that code should be moved into the Factory layer
    _travelSolutionList.push_back (&TS);
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::
  addTravelSolutionList (TravelSolutionList_T& addList) {
    _travelSolutionList.merge (addList);
  }

  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::eraseCurrentTravelSolution () {
    /* Ok even if the list is at the end */
    assert (_itCurrentTravelSolution != _travelSolutionList.end());
    _itCurrentTravelSolution =
      _travelSolutionList.erase (_itCurrentTravelSolution);
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TravelSolutionHolder::
  restrictionMeetsTSList (Restriction& restriction,
                          TravelSolutionList_T& removedElements) {
    /* If we are at the end of the list, we return the removedElements list
       because all the travel solutions have been matched */
    if (hasNotReachedEnd() == false) {
      return;
      
    } else {
      /** Call a function in the TravelSolution class which returns if a
          restriction meets a single travel solution */
      TravelSolution& currentTravelSolution = getCurrentTravelSolution();
      bool curTSOK =
        currentTravelSolution.restrictionMeetsTravelSolution (restriction);
      
      if (!curTSOK) {
        // We add this travel solution to the temp list
        removedElements.push_back(&currentTravelSolution);
        
        // TRAVELCCM_LOG_DEBUG (currentTravelSolution.toString());
        // We erase this travel solution from the current holder
        eraseCurrentTravelSolution();
        
      } else {
        /* If the travel solution matches the restriction, we do not alter the
           temporary list, and test the next elements */
        iterate();
      }
      
      restrictionMeetsTSList(restriction, removedElements);
    }
  }

}


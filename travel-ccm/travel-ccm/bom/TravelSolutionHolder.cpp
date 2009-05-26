// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM
#include <travel-ccm/bom/TravelSolution.hpp>
#include <travel-ccm/bom/TravelSolutionHolder.hpp>

namespace TRAVEL_CCM {
  // ////////////////////////////////////////////////////////////////////
  TravelSolutionHolder::~TravelSolutionHolder () {
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

    return oString;
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
  void TravelSolutionHolder::eraseCurrentTravelSolution () {
    /* ok even if the list is at the end */
    assert (_itCurrentTravelSolution != _travelSolutionList.end());
    _travelSolutionList.erase (_itCurrentTravelSolution);
  }
  
  // //////////////////////////////////////////////////////////////////////
 void TravelSolutionHolder::filtrateTravelSolutionList(Restriction R){
   //modify _travelSolutionList
    //need to implement the Restriction classs methods first
 }

}


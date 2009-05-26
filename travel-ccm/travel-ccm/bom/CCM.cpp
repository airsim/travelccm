// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/bom/CCM.hpp>

namespace TRAVEL_CCM {
  // ////////////////////////////////////////////////////////////////////
  CCM::~CCM () {
  }

  // //////////////////////////////////////////////////////////////////////
  void CCM::toStream (std::ostream& ioOut) const {
  }

  // //////////////////////////////////////////////////////////////////////
  void CCM::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string CCM::toString() const {
    std::string oString;

    return oString;
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string CCM::describeKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string CCM::describeShortKey() const {
    std::string oKey;

    return oKey;
  }

  // //////////////////////////////////////////////////////////////////////
  void CCM::orderedPreferences (TravelSolutionHolder& ioTSHolder,
                                RestrictionHolder& ioRestrictionList){
    /** for each travel solution, test if it meets the different restrictions;
        if it does, we keep it in the list, else we delete it
    */
    ioTSHolder.begin();
    while (ioTSHolder.hasNotReachedEnd()) { 
      TravelSolution& lCurrentTravelSolution = 
        ioTSHolder.getCurrentTravelSolution ();
      bool travelSolOK = ioRestrictionList.
        travelSolutionMeetRestrictionList (lCurrentTravelSolution);
      if (!travelSolOK){
        /** erase this element */
        ioTSHolder.eraseCurrentTravelSolution();
      } else {
        ioTSHolder.iterate();
      }
    }
  }
  
}


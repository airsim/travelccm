// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <list>
// TRAVEL_CCM 
#include <travel-ccm/bom/CCM.hpp>
#include <travel-ccm/service/Logger.hpp>

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
                                RestrictionHolder& ioResHolder){
    /** for each travel solution, test if it meets the different restrictions;
        if it does, we keep it in the list, else we delete it
    */
    TravelSolutionList_T temporaryHolder;
    // we check if each restriction meets the list of travel solutions
    while (ioResHolder.hasNotReachedEnd()) {
      Restriction& lCurrentRestriction =
        ioResHolder.getCurrentRestriction ();
      bool resOK = ioTSHolder.
        restrictionMeetsTSList (lCurrentRestriction);
      if (!resOK){
        /** erase this element */
        ioTSHolder.eraseCurrentTravelSolution();
      } else {
        ioResHolder.iterate();
      }
    }
  }
  
}


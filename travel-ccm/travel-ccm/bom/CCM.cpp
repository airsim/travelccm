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
    /** the temporary travel solution list allows us to keep in memory the
        travel solutions we erase from the ioTSHolder, in order to readd them
        in case of the list become void
    */
    ioResHolder.begin();
    // we check if each restriction meets the list of travel solutions
    while (ioResHolder.hasNotReachedEnd()) {
      Restriction& lCurrentRestriction =
        ioResHolder.getCurrentRestriction ();
      // we put the pointer at the beginning of the travel solutions list
      ioTSHolder.begin();
      // we retrive the erased travel solutions due to the restriction
      TravelSolutionList_T erasedElements;
      ioTSHolder.restrictionMeetsTSList(lCurrentRestriction, erasedElements);
      // if no travel solution remains
      if (ioTSHolder.isVoid()) {
        // we print the restriction which will not be respected
        TRAVEL_CCM_LOG_DEBUG ("restriction not respected: "
                              << lCurrentRestriction.toString() << ";");
        /* we put the just erased travel solutions in the travel solution
        holder again */
        ioTSHolder.addTravelSolutionList(erasedElements);
      }
      // then we do not need those saved travel solutions anymore
      erasedElements.clear();
      /* the pointer of the list is put at the beginning for the
         next restriction(s) */
      ioResHolder.iterate();
    }
  }
  
}


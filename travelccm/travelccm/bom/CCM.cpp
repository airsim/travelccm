// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <list>
// TRAVELCCM 
#include <travelccm/bom/Restriction.hpp>
#include <travelccm/bom/RestrictionHolder.hpp>
#include <travelccm/bom/TravelSolutionHolder.hpp>
#include <travelccm/bom/CCM.hpp>
#include <travelccm/service/Logger.hpp>

namespace TRAVELCCM {
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
    /** For each travel solution, test if it meets the different restrictions;
        if it does, we keep it in the list, else we delete it
    */
    /** The temporary travel solution list allows us to keep in memory the
        travel solutions we erase from the ioTSHolder, in order to readd them
        in case of the list become void
    */
    ioResHolder.begin();
    
    // We check if each restriction meets the list of travel solutions
    while (ioResHolder.hasNotReachedEnd()) {
      Restriction& lCurrentRestriction = ioResHolder.getCurrentRestriction ();
      
      // We put the pointer at the beginning of the travel solutions list
      ioTSHolder.begin();
      
      // We retrive the erased travel solutions due to the restriction
      TravelSolutionList_T erasedElements;
      ioTSHolder.restrictionMeetsTSList (lCurrentRestriction, erasedElements);
      
      // If no travel solution remains
      if (ioTSHolder.isVoid() == true) {
        // We print the restriction which will not be respected
        TRAVELCCM_LOG_DEBUG ("Restriction not respected: "
                             << lCurrentRestriction.toString() << ";");
        
        /* We put the just erased travel solutions in the travel solution
        holder again */
        ioTSHolder.addTravelSolutionList(erasedElements);
      }
      
      // Then we do not need those saved travel solutions anymore
      erasedElements.clear();
      
      /* The pointer of the list is put at the beginning for the
         next restriction(s) */
      ioResHolder.iterate();
    }
  }
  
}


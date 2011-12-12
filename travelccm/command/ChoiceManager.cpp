// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
// StdAir
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
// TravelCCM
#include <travelccm/bom/HardRestrictionModel.hpp>
#include <travelccm/command/ChoiceManager.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  const stdair::TravelSolutionStruct* ChoiceManager::
  chooseTravelSolution (stdair::TravelSolutionList_T& ioTravelSolutionList,
                        const stdair::BookingRequestStruct& iBookingRequest) {
    // Return the cheapest solution which satisfies the hard restrictions
    // such as change fees and non refundable.
    const stdair::TravelSolutionStruct* oTravelSolution_ptr = 
      HardRestrictionModel::chooseTravelSolution (ioTravelSolutionList,
                                                iBookingRequest);
    return oTravelSolution_ptr;
  }

}

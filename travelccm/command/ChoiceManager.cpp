// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
// StdAir
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
// TravelCCM
#include <travelccm/bom/HybridModel.hpp>
#include <travelccm/bom/HardRestrictionModel.hpp>
#include <travelccm/bom/PriceOrientedModel.hpp>
#include <travelccm/command/ChoiceManager.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  const stdair::TravelSolutionStruct* ChoiceManager::
  chooseTravelSolution (stdair::TravelSolutionList_T& ioTravelSolutionList,
                        const stdair::BookingRequestStruct& iBookingRequest,
                        const stdair::PassengerChoiceModel::EN_PassengerChoiceModel& iPassengerChoiceModel) {

    const stdair::TravelSolutionStruct* oTravelSolution_ptr = NULL;

    switch (iPassengerChoiceModel) {
    case stdair::PassengerChoiceModel::HYBRID:

      // Return the cheapest solution which minimises the fare plus the
      // disutility for each unsatisfied restriction.
      oTravelSolution_ptr = 
       HybridModel::chooseTravelSolution (ioTravelSolutionList,
                                          iBookingRequest);
      break;
      
    case stdair::PassengerChoiceModel::HARD_RESTRICTION:

      // Return the cheapest solution which satisfies the hard restrictions
      // such as change fees and non refundable.
      oTravelSolution_ptr = 
        HardRestrictionModel::chooseTravelSolution (ioTravelSolutionList,
                                                    iBookingRequest);
      break;
    case stdair::PassengerChoiceModel::PRICE_ORIENTED:
      
      // Return the cheapest solution
      oTravelSolution_ptr = 
        PriceOrientedModel::chooseTravelSolution (ioTravelSolutionList,
                                                  iBookingRequest);
      break;
    default:
      assert(false);
      break;
    }
    return oTravelSolution_ptr;
  }

}

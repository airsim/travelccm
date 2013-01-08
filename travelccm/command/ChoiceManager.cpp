// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
// StdAir
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
// TravelCCM
#include <travelccm/bom/CustomerChoiceModel.hpp>
#include <travelccm/command/ChoiceManager.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  const stdair::TravelSolutionStruct* ChoiceManager::
  chooseTravelSolution (stdair::TravelSolutionList_T& ioTravelSolutionList,
                        const stdair::BookingRequestStruct& iBookingRequest,
                        const stdair::PassengerChoiceModel::EN_PassengerChoiceModel& iPassengerChoiceModel) { 

    const CustomerChoiceModel* lCustomerChoiceModel = 
      CustomerChoiceModel::create (iPassengerChoiceModel);
  
    // Return the adequate travel solution according to the chosen passenger 
    // choice model
    const stdair::TravelSolutionStruct* oTravelSolution_ptr = 
      lCustomerChoiceModel->chooseTravelSolution (ioTravelSolutionList,
						  iBookingRequest);

    return oTravelSolution_ptr;
  }

}

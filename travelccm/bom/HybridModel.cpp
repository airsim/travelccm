// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
// StdAir
#include <stdair/bom/BomKeyManager.hpp>
#include <stdair/bom/BookingClassKey.hpp>
#include <stdair/bom/BookingRequestStruct.hpp>
#include <stdair/bom/TravelSolutionStruct.hpp>
#include <stdair/bom/FareOptionStruct.hpp>
#include <stdair/service/Logger.hpp>
// TravelCCM
#include <travelccm/bom/HybridModel.hpp>

namespace TRAVELCCM {

  // ////////////////////////////////////////////////////////////////////
  const stdair::TravelSolutionStruct* HybridModel::
  chooseTravelSolution (stdair::TravelSolutionList_T& ioTSList,
                        const stdair::BookingRequestStruct& iBookingRequest) {
    stdair::TravelSolutionStruct* oChosenTS_ptr = NULL;

    // Retrieve the number of passengers
    const stdair::NbOfSeats_T& lPartySize = iBookingRequest.getPartySize();

    // Retrieve the Willingness-to-Pay (WTP) of the customer
    const stdair::WTP_T& lWTP = iBookingRequest.getWTP();

    // Retrieve the restrictions of the customer
    // Retrieve the Change Fees of the customer
    const stdair::ChangeFees_T& lCustomerChangeFees = iBookingRequest.getChangeFees();
  
    //Retrieve the Non Refundable of the customer
    const stdair::NonRefundable_T& lCustomerNonRefundable = 
                                            iBookingRequest.getNonRefundable();

    // Check if it is a price-oriented customer, a product-oriented customer or 
    // an hybrid customer
    bool lIsPriceOriented = false;
    bool lIsProductOriented = false;
    
    if (lCustomerChangeFees == true && lCustomerNonRefundable == true) {
      lIsPriceOriented = true;
    } else if (lCustomerChangeFees == false && lCustomerNonRefundable == false) {
      lIsProductOriented = true;
    }
    
    //TODO move this constraints in const file
    //TODO create a type for penalty (or two)
    const stdair::Fare_T lDisutilityForChangeFees = 0.15 ;
    const stdair::Fare_T lDisutilityForNonRefundable = 0.15;

    
    // Browse the travel solution list and choose the cheapest one
    stdair::Fare_T lLowestFare = std::numeric_limits<stdair::Fare_T>::max();
    for (stdair::TravelSolutionList_T::iterator itTS = ioTSList.begin();
         itTS != ioTSList.end(); ++itTS) {
      stdair::TravelSolutionStruct& lTS = *itTS;

      // Browse the fare options
      const stdair::FareOptionList_T& lFOList = lTS.getFareOptionList();
      for (stdair::FareOptionList_T::const_iterator itFO = lFOList.begin();
           itFO != lFOList.end(); ++itFO) {
        const stdair::FareOptionStruct& lFO = *itFO;
        const stdair::Fare_T& lFOFare = lFO.getFare();

        // Check if the hybrid restrictions are satisfied
        bool lHybridRestrictionsSatisfied = false;
        stdair::Fare_T lHybridDisutility = 0;
        
        if (lIsPriceOriented == true) {
          lHybridRestrictionsSatisfied = true;
        } else if (lIsProductOriented == true) {
          lHybridRestrictionsSatisfied = not (lFO.getChangeFees() 
                                              || lFO.getNonRefundable());
        } else {
          if (lFO.getChangeFees() != lCustomerChangeFees) {
            if (lCustomerChangeFees == false) {
              lHybridDisutility += 3 * lDisutilityForChangeFees * lFOFare;
            } else {
              lHybridDisutility -= lDisutilityForChangeFees * lFOFare;
            }
          }
          if (lFO.getNonRefundable() != lCustomerNonRefundable) {
            if (lCustomerNonRefundable == false) {
              lHybridDisutility += 3 * lDisutilityForNonRefundable * lFOFare;
            } else {
              lHybridDisutility -= lDisutilityForNonRefundable * lFOFare;
            }
          }
          lHybridRestrictionsSatisfied = true;
        }
    
        if (lHybridRestrictionsSatisfied == true) {
          // Choose the current fare option and the current solution
          // if the current fare with penalities is lower than the current 
          // lowest fare.
          
          const stdair::Availability_T& lFOAvl = lFO.getAvailability();

          if (lFOFare + lHybridDisutility < lLowestFare 
              && lFOFare + lHybridDisutility <= lWTP && lFOFare <= lWTP
              && lFOAvl >= lPartySize) {

            // DEBUG
            
              STDAIR_LOG_DEBUG ("The travel solution (TS) '" << lTS
              << "' is chosen because its fare with disutility (" 
              << lFOFare + lHybridDisutility
              << ") is lower than the lowest fare (" << lLowestFare
              << ") and because its fare ("<< lFOFare
              << ") is lower than the WTP (" << lWTP
              << "), and because the party size (" << lPartySize
              << ") is lower than the availability (" << lFOAvl
              << ")");
            

            lLowestFare = lFOFare + lHybridDisutility;
            oChosenTS_ptr = &lTS;
            oChosenTS_ptr->setChosenFareOption (lFO);

          } else {
            // DEBUG
            
              STDAIR_LOG_DEBUG ("The travel solution (TS) '" << lTS
              << "' is not chosen because either its fare with disutility ("
              << lFOFare + lHybridDisutility << ") is greater than the " 
              << "lowest fare (" << lLowestFare << ") or than the WTP (" 
              << lWTP << "), or because its fare (" << lFOFare << ") " 
              << "is greater than the WTP (" << lWTP
              << "), or because the party size (" << lPartySize
              << ") is greater than the availability (" << lFOAvl
              << ")");
            
          }
        }
      }
    }
    
    return oChosenTS_ptr;
  }

}

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
#include <map>
// StdAir
#include <stdair/service/Logger.hpp>
// TravelCCM
#include <travelccm/bom/CustomerChoiceModel.hpp>
#include <travelccm/TRAVELCCM_Types.hpp>

namespace TRAVELCCM {
  
  // ////////////////////////////////////////////////////////////////////
  CustomerChoiceModel::CustomerChoiceModel () {
  }
  
  // ////////////////////////////////////////////////////////////////////
  CustomerChoiceModel::CustomerChoiceModel 
  (const stdair::PassengerChoiceModel::EN_PassengerChoiceModel& iPassengerChoiceModel) {
    CustomerChoiceModelMap_T& lCustomerChoiceModelMap = getMap();  
    const bool hasInsertionBeenSuccessful = 
      lCustomerChoiceModelMap.insert (CustomerChoiceModelMap_T::value_type
				      (iPassengerChoiceModel, this)).second;
    assert (hasInsertionBeenSuccessful == true);
  }  

  // ////////////////////////////////////////////////////////////////////
  CustomerChoiceModel::~CustomerChoiceModel() {
  }
 
  // ////////////////////////////////////////////////////////////////////
  const CustomerChoiceModel* CustomerChoiceModel::create 
  (const stdair::PassengerChoiceModel::EN_PassengerChoiceModel& iPassengerChoiceModel) { 

    const CustomerChoiceModel* lCustomerChoiceModel_ptr = NULL;

    // Try to retrieve the object corresponding to the enum type in the 
    // dedicated map.  
    const CustomerChoiceModelMap_T& lCustomerChoiceModelMap = getMap();  
    CustomerChoiceModelMap_T::const_iterator itModel = 
      lCustomerChoiceModelMap.find (iPassengerChoiceModel);

    // If no object is retrieved, then the algorithm corresponding to the given
    // enum type has not been implemented yet.
    if (itModel == lCustomerChoiceModelMap.end()) {  
      std::ostringstream oMessage;
      oMessage << "The passenger choice model '"
	       << stdair::PassengerChoiceModel::getLabel(iPassengerChoiceModel)
               << "' has not been implemented yet." << std::endl;
      STDAIR_LOG_ERROR(oMessage.str());
      throw CustomerChoiceException(oMessage.str());
    } else {
      lCustomerChoiceModel_ptr = itModel->second;
    } 
    assert (lCustomerChoiceModel_ptr != NULL);
    return lCustomerChoiceModel_ptr;
  }

}

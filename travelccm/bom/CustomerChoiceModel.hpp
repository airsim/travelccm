#ifndef __TRAVELCCM_BOM_CUSTOMERCHOICEMODEL_HPP
#define __TRAVELCCM_BOM_CUSTOMERCHOICEMODEL_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// StdAir
#include <stdair/stdair_service_types.hpp>
#include <stdair/bom/TravelSolutionTypes.hpp>
#include <stdair/basic/PassengerChoiceModel.hpp>

/// Forward declarations
namespace stdair {
  struct BookingRequestStruct;
}

namespace TRAVELCCM {
  
  /**
   * Class implementing the customer choice.
   */
  class CustomerChoiceModel {    

  private:
    // ////////// Type definitions ////////////
    typedef std::map<stdair::PassengerChoiceModel::EN_PassengerChoiceModel, 
		     CustomerChoiceModel*> CustomerChoiceModelMap_T;
    
  private:
    /**
     * Map linking the passenger choice model object with the corresponding 
     * enum value.
     */
    static CustomerChoiceModelMap_T& getMap () {
      static CustomerChoiceModelMap_T _choiceModelMap;
      return _choiceModelMap;
    }

  public: 
    /**
     * Choose a travel solution within the given list of travel solutions.
     */
    virtual const stdair::TravelSolutionStruct*
    chooseTravelSolution (stdair::TravelSolutionList_T&,
                          const stdair::BookingRequestStruct&) const = 0; 


    /**
     * Return the Customer Choice Model object described by the given enum type.
     */
    static const CustomerChoiceModel* 
    create (const stdair::PassengerChoiceModel::EN_PassengerChoiceModel&);   

  public: 
    /**
     * Destructor.
     */
    virtual ~CustomerChoiceModel();

  protected:   
    /**
     * Default Constructor.
     */
    CustomerChoiceModel ();

    /**
     * Main Constructor.
     */
    CustomerChoiceModel 
    (const stdair::PassengerChoiceModel::EN_PassengerChoiceModel&);

  };
}
#endif // __TRAVELCCM_BOM_CUSTOMERCHOICEMODEL_HPP

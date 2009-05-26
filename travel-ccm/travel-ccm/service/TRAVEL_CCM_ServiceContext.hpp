#ifndef __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP
#define __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVEL-CCM
#include <travel-ccm/TRAVEL_CCM_Types.hpp>
#include <travel-ccm/service/ServiceAbstract.hpp>

namespace TRAVEL_CCM {
  // Forward declarations.
  class Passenger;
  class TravelSolutionHolder; 

  /** Inner class holding the context for the TRAVEL_CCM Service object. */
  class TRAVEL_CCM_ServiceContext : public ServiceAbstract {
    /** The TRAVEL_CCM_Service class should be the sole class to get access to
        ServiceContext content: general users do not want to bother
        with a context interface. */
    friend class TRAVEL_CCM_Service;
    friend class FacTRAVEL_CCMServiceContext;

  private:
    /** Constructors. */
    TRAVEL_CCM_ServiceContext ();
    TRAVEL_CCM_ServiceContext (const TRAVEL_CCM_ServiceContext&);
    void init ();
    /** Initialise the StudyStatManager. */
    void initStudyStatManager ();
    /** Destructor. */
    ~TRAVEL_CCM_ServiceContext();


  private:
    // /////// Attributes ///////
    Passenger* passenger;
    TravelSolutionHolder* travelSolutionHolder;
  };

}
#endif // __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP

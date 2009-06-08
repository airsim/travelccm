#ifndef __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP
#define __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// TRAVEL-CCM
#include <travel-ccm/TRAVEL_CCM_Types.hpp>
#include <travel-ccm/service/ServiceAbstract.hpp>
#include <travel-ccm/TRAVEL_CCM_Types.hpp>
#include <travel-ccm/bom/Request.hpp>

namespace TRAVEL_CCM {
  // Forward declarations.
  class Passenger;
  class RestrictionHolder;
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
    // passenger filed unuse makes this function useless
    // TRAVEL_CCM_ServiceContext (Request&, std::string);
    TRAVEL_CCM_ServiceContext (const TRAVEL_CCM_ServiceContext&);
    void init ();
    // passenger filed unuse makes this function useless
    // void init (Request&, std::string);
    /** Initialise the StudyStatManager. */
    void initStudyStatManager ();
    /** Destructor. */
    ~TRAVEL_CCM_ServiceContext();

    /** Set the TravelSolutionHolder */
    void setTravelSolutionHolder (
                     TravelSolutionHolder* ioTravelSolutionHolderPtr){
      _travelSolutionHolder = ioTravelSolutionHolderPtr;
    }

    /** Add a travel solution to the TravelSolutionHolder */
    void addTravelSolution (std::string dAirport, std::string aAirport,
                            Date_T depDate,
                            Duration_T depTime, Duration_T arTime,
                            Duration_T dur, bool Ref, std::string airline,
                            std::string cabin, int flightNum, double fare,
                            int lagsNum,  bool SNS, bool change);
    
    /** Add a restriction to the restriction holder */
    void addRestriction (std::string restrictionType);
    void addRestriction (std::string restrictionType,
                         std::string namePreference);

    /** Read the input data from a file */
    void readFromInputFile (const std::string& iInputFileName);


  private:
    // /////// Attributes ///////
    /* use of the field passenger later
       Passenger* _passenger;
    */
    RestrictionHolder* _restrictionHolder;
    TravelSolutionHolder* _travelSolutionHolder;

  public:
    TravelSolutionHolder& getTravelSolutionHolder() const;
    //Passenger& getPassenger () const ;
    RestrictionHolder& getRestrictionHolder() const;
    
  };

}
#endif // __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_CONTEXT_HPP

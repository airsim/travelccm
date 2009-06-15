#ifndef __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP
#define __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVELCCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/service/ServiceAbstract.hpp>

namespace TRAVELCCM {
  // Forward declarations
  class Passenger;
  class RestrictionHolder;
  class TravelSolutionHolder;

  /** Inner class holding the context for the TRAVELCCM Service object. */
  class TRAVELCCM_ServiceContext : public ServiceAbstract {
    /** The TRAVELCCM_Service class should be the sole class to get access to
        ServiceContext content: general users do not want to bother
        with a context interface. */
    friend class TRAVELCCM_Service;
    friend class FacTRAVELCCMServiceContext;
  public:
    TravelSolutionHolder& getTravelSolutionHolder() const;
    //Passenger& getPassenger () const ;
    RestrictionHolder& getRestrictionHolder() const;
    
  private:
    /** Constructors. */
    TRAVELCCM_ServiceContext ();
    // passenger filed unuse makes this function useless
    // TRAVELCCM_ServiceContext (Request&, std::string);
    TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&);
    void init ();
    // passenger filed unuse makes this function useless
    // void init (Request&, std::string);
    /** Initialise the StudyStatManager. */
    void initStudyStatManager ();
    /** Destructor. */
    ~TRAVELCCM_ServiceContext();

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

  };

}
#endif // __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP

#ifndef __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP
#define __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// TRAVELCCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/service/ServiceAbstract.hpp>
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/bom/Request.hpp>

namespace TRAVELCCM {
  // Forward declarations.
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

  private:
    /** Constructors. */
    TRAVELCCM_ServiceContext ();
    TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&);
    void init ();
    
    /** Initialise the StudyStatManager. */
    void initStudyStatManager ();
    /** Destructor. */
    ~TRAVELCCM_ServiceContext();

    /** To create the passenger */
    void createPassenger(std::string);

    /** To intialize the different field of the passenger. To be called after
        the creation of the passenger inevitably.  */
    void intializePassenger();

    /** Set the TravelSolutionHolder */
    void setTravelSolutionHolder (
                     TravelSolutionHolder* ioTravelSolutionHolderPtr){
      _travelSolutionHolder = ioTravelSolutionHolderPtr;
    }

    /** Add a travel solution to the TravelSolutionHolder */
    void addTravelSolution (const std::string& iDepartureAirport,
                            const std::string& iArrivalAirport,
                            const Date_T& iDepartureDate,
                            const Duration_T& iDepartureTime,
                            const Duration_T& iArrivalTime,
                            const Duration_T& iDuration,
                            const bool iRefubdability,
                            const std::string& iAirlineCode,
                            const std::string& iCabinCode,
                            const int FlightNumber, double iFare,
                            int iStopsNumber,  bool iSNS, bool iChangeability,
                            const std::string& id);
    
    /** Add a restriction to the restriction holder in the passenger field */
    void addRestriction (const std::string& iRestrictionType);
    void addRestriction (const std::string& iRestrictionType,
                         const std::string& iNamePreference);

    /** Add a request and link it to the passenger. */
    void addAndLinkRequest (bool refundability, bool changeability,
                            bool saturdayNightStay, std::string preferredAirline,
                            std::string preferredCabin, DateTime_T departureTime);
    
    /** Read the input data from a file */
    void readFromInputFile (const std::string& iInputFileName);

    /** Add in the right order the restrictions regarding the characteristics
        of the fares desired by the passenger, found in the request field */
    void addAndOrderRestrictionsFromRequest();

  private:
    // /////// Attributes ///////
    Passenger* _passenger;
    TravelSolutionHolder* _travelSolutionHolder;

  public:
    TravelSolutionHolder& getTravelSolutionHolder() const;
    Passenger& getPassenger () const ;
    // return the restriction holder in the passenger class
    RestrictionHolder& getRestrictionHolder() const;
    
  };

}
#endif // __TRAVELCCM_SVC_TRAVELCCM_SERVICE_CONTEXT_HPP

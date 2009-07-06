#ifndef __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP
#define __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// TRAVELCCM
#include <travelccm/TRAVELCCM_Types.hpp>

namespace TRAVELCCM {

  /** Forward declaration. */
  class TRAVELCCM_ServiceContext;
  class TravelSolutionHolder;
  class TravelSolution;

  /** Interface for the TRAVELCCM Services. */
  class TRAVELCCM_Service {
  public:
    /** Constructor. */
    TRAVELCCM_Service (std::ostream& ioLogStream);
    /** Destructor. */
    ~TRAVELCCM_Service();

    /** create a passenger in the context thanks to his type. */
    void createPassenger(std::string);
    /** Initialize the different fields of a passenger after creating it. */
    void initializePassenger();

    /** add a travel solution to the context */
    void addTravelSolution (const std::string& iDepartureAirport,
                            const std::string& iArrivalAirport,
                            const Date_T& iDepartureDate,
                            const Duration_T& iDepartureTime,
                            const Duration_T& iArrivalTime,
                            const Duration_T& iDuration,
                            const bool iRefundability,
                            const std::string& iAirlineCode,
                            const std::string& iCabinCode,
                            const int iFlightNumber, double iFare,
                            int iStopsNumber,  bool iSNS, bool iChangeability,
                            const std::string& id);

    /** Add a restriction to the context. */
    void addRestriction (const std::string& iRestrictionType);

    /** Add a restriction to the context. */
    void addRestriction (const std::string& iRestrictionType,
                         const std::string& iNamePreference);

    /** Add a request to the context. */
    void addRequest (bool, bool, bool, std::string, std::string, DateTime_T);

    /* Add the restrictions to the passenger, in the right order, from his
       request */
    void addRestrictionsFromRequest ();
    
    /** returns the holder of travel solutions after the algorithm of
        preferred choices */
    TravelSolutionHolder& getChoosenTravelSolutions();
    
    /** returns the cheapest travel solution amongs those retained by the
        customer, that is the one he will buy */
    const TravelSolution*  getBestTravelSolution(TravelSolutionHolder&);

    /** returns the key of the cheapest travel solution */
    std::string getBestTravelSolutionId();

    /** Perform a small simulation, which uses the Customer Choice Model.*/
    void simulate();

  private:
    /** Default Constructors. */
    TRAVELCCM_Service ();
    TRAVELCCM_Service (const TRAVELCCM_Service&);

    /** Initialise. */
    void init (std::ostream& ioLogStream);
    
    /** Initialise the log. */
    void logInit (const LOG::EN_LogLevel iLogLevel, std::ostream& ioLogStream);

    /** Finaliser. */
    void finalise ();

  private:
    // ////////// Service Context //////////
    /** Service Context. */
    TRAVELCCM_ServiceContext* _travelccmServiceContext;
  };
}
#endif // __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP

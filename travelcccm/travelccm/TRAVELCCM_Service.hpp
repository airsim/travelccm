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

  /** Interface for the TRAVELCCM Services. */
  class TRAVELCCM_Service {
  public:
    /** Constructor. */
    TRAVELCCM_Service (std::ostream& ioLogStream);
    /** Destructor. */
    ~TRAVELCCM_Service();

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
                            int iStopsNumber,  bool iSNS, bool iChangeability);

    /** Add a restriction to the context. */
    void addRestriction (const std::string& iRestrictionType);

    /** Add a restriction to the context. */
    void addRestriction (const std::string& iRestrictionType,
                         const std::string& iNamePreference);

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

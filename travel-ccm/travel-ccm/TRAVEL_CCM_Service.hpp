#ifndef __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_HPP
#define __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// TRAVEL-CCM
#include <travel-ccm/TRAVEL_CCM_Types.hpp>

namespace TRAVEL_CCM {

  /** Forward declaration. */
  class TRAVEL_CCM_ServiceContext;

  /** Interface for the TRAVEL_CCM Services. */
  class TRAVEL_CCM_Service {
  public:
    /** Constructor. */
    TRAVEL_CCM_Service (std::ostream& ioLogStream);
    /** Destructor. */
    ~TRAVEL_CCM_Service();

    /** add a travel solution to the context */
    void addTravelSolution(std::string dAirport, std::string aAirport,
                           Date_T depDate,
                           Duration_T depTime, Duration_T arTime,
                           Duration_T dur, bool Ref, std::string airline,
                           std::string cabin, int flightNum, double fare,
                           int lagsNum,  bool SNS, bool change);

    /** add a restriction to the context */
    void addRestriction(std::string restrictionType);
    void addRestriction(std::string restrictionType, std::string namePreference);

    /** Perform a small simulation, which uses the Customer Choice Model.*/
    void simulate();

  private:
    /** Default Constructors. */
    TRAVEL_CCM_Service ();
    TRAVEL_CCM_Service (const TRAVEL_CCM_Service&);

    /** Initialize. */
    void init (std::ostream& ioLogStream);
    
    /** Initialize the log. */
    void logInit (const LOG::EN_LogLevel iLogLevel, std::ostream& ioLogStream);

    /** Finaliser. */
    void finalise ();

  private:
    // ////////// Service Context //////////
    /** Service Context. */
    TRAVEL_CCM_ServiceContext* _travel_ccmServiceContext;
  };
}
#endif // __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_HPP

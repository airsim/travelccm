#ifndef __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_HPP
#define __TRAVEL_CCM_SVC_TRAVEL_CCM_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
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

  private:
    /** Default Constructors. */
    TRAVEL_CCM_Service ();
    TRAVEL_CCM_Service (const TRAVEL_CCM_Service&);

    /** Initialise. */
    void init (std::ostream& ioLogStream);
    
    /** Initilise the log. */
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

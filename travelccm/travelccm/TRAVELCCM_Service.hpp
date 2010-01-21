#ifndef __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP
#define __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// StdAir
#include <stdair/STDAIR_Types.hpp>
#include <stdair/basic/BasLogParams.hpp>
// TravelCCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/basic/BasTravelCCMType.hpp>

namespace TRAVELCCM {

  /** Forward declaration. */
  class TRAVELCCM_ServiceContext;
  class TravelSolutionHolder;
  class TravelSolution;

  /** Interface for the TRAVELCCM Services. */
  class TRAVELCCM_Service {
  public:
    // ////////// Constructors and destructors //////////
    /** Constructor.
        <br>The init() method is called; see the corresponding documentation
        for more details.
        <br>Moreover, a reference on an output stream is given, so
        that log outputs can be directed onto that stream.       
        @param const stdair::BasLogParams& Parameters for the output log stream.
        @param const BasTravelCCMType& Type of the customer-choice
               model type (e.g., Preference-based or Logit). */
    TRAVELCCM_Service (const stdair::BasLogParams&, const BasTravelCCMType&);
    
    /** Constructor.
        <br>The init() method is called; see the corresponding documentation
        for more details.
        <br>Moreover, as no reference on any output stream is given,
        it is assumed that the StdAir log service has already been
        initialised with the proper log output stream by some other
        methods in the calling chain (for instance, when the TRAVELCCM_Service
        is itself being initialised by another library service such as
        DSIM_Service).
        @param const BasTravelCCMType& Type of the customer-choice
               model type (e.g., Preference-based or Logit). */
    TRAVELCCM_Service (const BasTravelCCMType&);
    
    /** Destructor. */
    ~TRAVELCCM_Service();

    
  public:
    // ////////// Use Cases //////////
    /** Create a passenger in the context for the given type. */
    void createPassenger (const std::string&);
    
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
    
    /** Return the holder of travel solutions after the algorithm of
        preferred choices */
    TravelSolutionHolder& getChoosenTravelSolutions();

    // TODO: revise the choice process since the travel solution returned is
    // not necessarily the cheapest one. Idem for the following function.
    /** Return the cheapest travel solution amongs those retained by the
        customer, that is the one he will buy */
    const TravelSolution* getBestTravelSolution (TravelSolutionHolder&);

    /** Return one of the cheapest travel solutions which has the best matching
        indicator */
    const TravelSolution* getBestTravelSolutionByMatchingIndicator ();
    
    /** Return the key of the cheapest travel solution */
    std::string getBestTravelSolutionId();

    /** Perform a small simulation, which uses the Customer Choice Model.*/
    bool simulate();

    
  private:
    // /////// Construction and Destruction helper methods ///////
    /** Default Constructors. */
    TRAVELCCM_Service ();
    TRAVELCCM_Service (const TRAVELCCM_Service&);

    /** Initialise the log. */
    void logInit (const stdair::BasLogParams&);

    /** Initialise.
        @param const BasTravelCCMType& Type of the customer-choice
               model type (e.g., Preference-based or Logit). */
    void init (const BasTravelCCMType&);
    
    /** Finaliser. */
    void finalise ();

  private:
    // ////////// Service Context //////////
    /** Service Context. */
    TRAVELCCM_ServiceContext* _travelccmServiceContext;
  };
}
#endif // __TRAVELCCM_SVC_TRAVELCCM_SERVICE_HPP

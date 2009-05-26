#ifndef __TRAVEL_CCM_FAC_FACTRAVELSOLUTION_HPP
#define __TRAVEL_CCM_FAC_FACTRAVELSOLUTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/factory/FacBomAbstract.hpp>
namespace TRAVEL_CCM {
  // Forward declarations.
  class TravelSolution;
  
  /** Factory for TravelSolution objects. */
  class FacTravelSolution : public FacBomAbstract {
  public:
    /** Provide the unique instance.
        <br>The singleton is instantiated when first used
        @return FacTravelSolution& */
    static FacTravelSolution& instance();

    /** Destructor.
        <br>The Destruction put the _instance to NULL
        in order to be clean for the next FacTravelSolution::instance() */
    virtual ~FacTravelSolution();

    /** Create a new TravelSolution object.
        <br>This new object is added to the list of instantiated objects.
        @return TravelSolution& The newly created object. */
    TravelSolution& create ();
    TravelSolution& create (std::string dAirport, std::string aAirport,
                            Time depTime, Time arTime, Time dur, bool Ref,
                            std::string airline,  std::string cabin,
                            int flightNum, double fare, int lagsNum,
                            bool SNS, bool change);

  protected:
    /** Default Constructor.
        <br>This constructor is protected in order to ensure the singleton
        pattern.*/
    FacTravelSolution () {}

  private:
    /** The unique instance.*/
    static FacTravelSolution* _instance;
  };

}
#endif // __TRAVEL_CCM_FAC_FACTRAVELSOLUTION_HPP


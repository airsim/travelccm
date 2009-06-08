#ifndef __TRAVEL_CCM_BOM_TRAVELSOLUTIONHOLDER_HPP
#define __TRAVEL_CCM_BOM_TRAVELSOLUTIONHOLDER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/bom/BomAbstract.hpp>
#include <travel-ccm/bom/TravelSolutionList.hpp>
#include <travel-ccm/bom/Restriction.hpp>
#include <travel-ccm/bom/TravelSolution.hpp>

namespace TRAVEL_CCM {

  /** Object description here. */
  class TravelSolutionHolder : public BomAbstract {
    friend class FacTravelSolutionHolder;

  public:
    
    // /////////// Display support methods /////////
    /** Dump a Business Object into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a Business Object from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream& ioIn);

   /** Get the serialised version of the Business Object. */
    std::string toString() const;

    /** Get the number of travel solutions in the list */
    int numberOfTravelSolutions();
    
    /** Get a string describing the whole key (differentiating two objects
        at any level). */
    const std::string describeKey() const;

    /** Get a string describing the short key (differentiating two objects
        at the same level). */
    const std::string describeShortKey() const;

  private:
    /** the list of (N) travel solutions for a given request */
    TravelSolutionList_T _travelSolutionList;

    /** Iterator for the current restriction/class */
    TravelSolutionList_T::iterator _itCurrentTravelSolution;


  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    TravelSolutionHolder ();
    TravelSolutionHolder (const TravelSolutionHolder&);

    /** Destructor. */
    virtual ~TravelSolutionHolder();

  public:
    TravelSolution& getCurrentTravelSolution () const;

    void begin ();
    bool hasNotReachedEnd () const;
    void iterate ();
    void eraseCurrentTravelSolution ();
    void addTravelSolution (TravelSolution&) ;

    /** given a list of travel solutionsm the function returns if the
        restriction in argument meets the different travel solutions
    */
    bool restrictionMeetsTSList(Restriction&);

  };

}
#endif // __TRAVEL_CCM_BOM_TRAVELSOLUTIONHOLDER_HPP


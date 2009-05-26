#ifndef __TRAVEL_CCM_BOM_RESTRICTIONHOLDER_HPP
#define __TRAVEL_CCM_BOM_RESTRICTIONHOLDER_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/bom/BomAbstract.hpp>
#include <travel-ccm/bom/RestrictionList.hpp>
#include <travel-ccm/bom/Restriction.hpp>

namespace TRAVEL_CCM {

  /** Object description here. */
  class RestrictionHolder : public BomAbstract {
    friend class FacRestrictionHolder;
    friend class TravelSolution;

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
    
    /** Get a string describing the whole key (differentiating two objects
        at any level). */
    const std::string describeKey() const;

    /** Get a string describing the short key (differentiating two objects
        at the same level). */
    const std::string describeShortKey() const;

  private:
    /** the list of (N) restrictions for a given passenger */
    RestrictionList_T _restrictionList;

    /** Iterator for the current restriction/class */
    RestrictionList_T::iterator _itCurrentRestriction;
    RestrictionList_T::iterator _itNextRestriction;
    RestrictionList_T::iterator _itTaggedRestriction;
    


  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    RestrictionHolder ();
    RestrictionHolder (const RestrictionHolder&);

    /** Destructor. */
    virtual ~RestrictionHolder();

  public:
    Restriction& getCurrentRestriction () const;
    Restriction& getNextRestriction () const;
    Restriction& getTaggedRestriction () const;

    void begin ();
    void tag ();
    bool hasNotReachedEnd () const;
    void iterate ();

    
     /** given a list of restriction, the function returns if the
         travel solution in argument meets the different restrictions
      */
    bool travelSolutionMeetRestrictionList(TravelSolution& TS);

  };

}
#endif // __TRAVEL_CCM_BOM_RESTRICTIONHOLDER_HPP


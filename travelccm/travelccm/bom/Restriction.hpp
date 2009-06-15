#ifndef __TRAVELCCM_BOM_RESTRICTION_HPP
#define __TRAVELCCM_BOM_RESTRICTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVELCCM 
#include <travelccm/bom/BomAbstract.hpp>

namespace TRAVELCCM {

  /** Class representing a fare restriction.
      <br>Typically, examples of fare restrictions are:
      <ul>
      <li>Refundability</li>
      <li>Changeability</li>
      <li>Minimum Stay (e.g., 3 days)</li>
      <li>Saturday Night Stay</li>
      <li>etc.</li>
      </ul>
  */
  class Restriction : public BomAbstract {
    friend class FacRestriction;
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

    /** Get the type of the restriction */
    const std::string getRestrictionType() const;

    /** Get the type of the restriction */
    const std::string getPreferredAirline() const;

    /** Get the type of the restriction */
    const std::string getPreferredCabin() const;
    
    /* return if the travel solution put in argument meets the current
       restriction */
    // obsolete method
    //bool travelSolutionMeetRestriction (TravelSolution&) const;

  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    Restriction ();
    Restriction (const Restriction&);

    /** Real constructors */
    /** Used for the construction of dual restrictions. */
    Restriction (std::string restrictionType);
    /** Used for the construction of "complex" restrictions. */
    Restriction (std::string restrictionType, std::string namePreference);

    /** Destructor. */
    virtual ~Restriction();

  private:
    /* The type of the restriction gives the aspect of the ticket which
       counts for the customer.
       Extensively they are: refundability, preferredAirline, preferredCabin
       (for the moment, we will add other later)
    */
    std::string _restrictionType;
    // field used only if the restriction is of type preferredAirline
    std::string _preferredAirline;
    // field used only if the restriction is of type preferredCabin
    std::string _preferredCabin;
    

  };

}
#endif // __TRAVELCCM_BOM_RESTRICTION_HPP


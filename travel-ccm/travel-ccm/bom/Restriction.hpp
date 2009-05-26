#ifndef __TRAVEL_CCM_BOM_RESTRICTION_HPP
#define __TRAVEL_CCM_BOM_RESTRICTION_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// TRAVEL_CCM 
#include <travel-ccm/bom/TravelSolution.hpp>
#include <travel-ccm/bom/BomAbstract.hpp>

namespace TRAVEL_CCM {

  /** Object description here. */
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
    bool travelSolutionMeetRestriction(TravelSolution& T);


  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    Restriction ();
    Restriction (const Restriction&);

    /** real constructors */
    // used for the construction of refundability restriction
    Restriction(std::string restrictionType);

    /** Destructor. */
    virtual ~Restriction();

  private:
    /* the type of the restriction gives the aspect of the ticket which
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
#endif // __TRAVEL_CCM_BOM_RESTRICTION_HPP


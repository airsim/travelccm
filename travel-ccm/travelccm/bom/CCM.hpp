#ifndef __TRAVELCCM_BOM_CCM_HPP
#define __TRAVELCCM_BOM_CCM_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVELCCM 
#include <travelccm/bom/BomAbstract.hpp>
#include <travelccm/bom/RestrictionHolder.hpp>
#include <travelccm/bom/TravelSolutionHolder.hpp>
#include <travelccm/bom/TravelSolutionList.hpp>

namespace TRAVELCCM {

  /** Object description here. */
  class CCM : public BomAbstract {
    friend class FacCCM;
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
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    CCM ();
    CCM (const CCM&);

    /** Destructor. */
    virtual ~CCM();
    

  public:
    /** where the algorithms of customer choice are implemented
        we could imagine other algorithms later */
    static void orderedPreferences (TravelSolutionHolder&, RestrictionHolder&);

  };

}
#endif // __TRAVELCCM_BOM_CCM_HPP


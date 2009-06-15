#ifndef __TRAVELCCM_BOM_REQUEST_HPP
#define __TRAVELCCM_BOM_REQUEST_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVELCCM 
#include <travelccm/bom/BomAbstract.hpp>

namespace TRAVELCCM {

  /** Object description here. */
  class Request : public BomAbstract {
    friend class FacRequest;
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

    /** Get the travel solutions which meet the request */
    /*TravelSolutionHolder getTravelSolutions();*/

  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    /** Default constructors. */
    Request ();
    Request (const Request&);

    /** Destructor. */
    virtual ~Request();

  };

}
#endif // __TRAVELCCM_BOM_REQUEST_HPP


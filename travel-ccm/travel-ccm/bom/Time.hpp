#ifndef __TRAVEL_CCM_BOM_TIME_HPP
#define __TRAVEL_CCM_BOM_TIME_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// TRAVEL_CCM 
#include <travel-ccm/bom/BomAbstract.hpp>

namespace TRAVEL_CCM {

  /** Object description here. */
  class Time : public BomAbstract {
    friend class FacTime;
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
    Time ();
    Time (const Time&);
    Time (int h, int m);

  private:
    /** the time of the day is given under the form 12h30 */
    int _hour;
    int _min;

    /** Destructor. */
    virtual ~Time();

  };

}
#endif // __TRAVEL_CCM_BOM_TIME_HPP


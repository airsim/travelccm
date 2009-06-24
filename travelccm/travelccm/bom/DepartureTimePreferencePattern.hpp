#ifndef __TRAVELCCM_BOM_DEPARTURETIMEPREFERENCEPATTERN_HPP
#define __TRAVELCCM_BOM_DEPARTURETIMEPREFERENCEPATTERN_HPP

// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
#include <map>
// TRAVEL CCM
#include <travelccm/TRAVELCCM_Types.hpp>
#include <travelccm/bom/BomAbstract.hpp>

namespace TRAVELCCM {
    
  /** Class storing departure time preference pattern. */
  class DepartureTimePreferencePattern : public BomAbstract {
    friend class FacDepartureTimePreferencePattern;

  public:
    // /////////// Getters //////////////
    // ///////// Display //////////
    /** Dump a Business Object into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a Business Object from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream& ioIn);

   /** Get the serialised version of the Business Object. */
    std::string toString() const;

    /** Get a string describing the short key (differentiating two objects
        at the same level). */
    const std::string describeShortKey() const;

    /** Get a string describing the key. */
    const std::string describeKey() const;

    /** Display the full DepartureTimePreferencePattern context. */
    const std::string display() const;

    // ////////// Business methods /////////
  private:
    /** Constructors are private so as to force the usage of the Factory
        layer. */
    DepartureTimePreferencePattern (const PatternId_T&); 

    /** Destructor. */
    virtual ~DepartureTimePreferencePattern();

    /** Get the identity of the pattern. */
    const PatternId_T& getDepartureTimePreferenceId() const {
      return _departureTimePreferencePatternId;
    }

  private:
    /** Identifier of the cancellation rate curve. */
    PatternId_T _departureTimePreferencePatternId;

    /** List of the discretized points of the cancellation rate curve 
        Date to Departure are on the X-axis and percentage pair of expected
        cancellation and no-show are on the Y-axis. */
    DepartureTimePreferencePattern_T _departureTimePreferencePattern;
  };
    
}
#endif // __TRAVELCCM_BOM_DEPARTURETIMEPREFERENCEPATTERN_HPP
#ifndef __STDAIR_BAS_BASTRAVELCCMTYPE_HPP
#define __STDAIR_BAS_BASTRAVELCCMTYPE_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <string>
// StdAir
#include <stdair/basic/StructAbstract.hpp>

namespace TRAVELCCM {

  /** Structure defining the customer-choice model type. */
  struct BasTravelCCMType : public stdair::StructAbstract {
    friend class TRAVELCCM_ServiceContext;
  public:    
    typedef enum {
      PREF_BASED = 0,
      LOGIT,
      LAST_VALUE
    } EN_CCMType;

    static const std::string CCMTypes[LAST_VALUE];

    
  public:
    // ///////// Getters ////////
    /** Get the log level. */
    const EN_CCMType& getType() const {
      return _type;
    }
    
    
    // ///////// Setters //////////
    // No setters

    
  public:
    // ///////// Display methods ////////
    /** Dump a structure into an output stream.
        @param ostream& the output stream. */
    void toStream (std::ostream& ioOut) const;

    /** Read a structure from an input stream.
        @param istream& the input stream. */
    void fromStream (std::istream&);

    /** Display of the structure. */
    const std::string describe() const;
    
    /** Get a short display of the type. */
    std::string toShortString() const;
    
    /** Get the serialised version of the type. */
    std::string toString() const;

    
  public:
    /** Main Constructor. */
    BasTravelCCMType (const EN_CCMType& iCCMType);

    /** Destructor. */
    ~BasTravelCCMType();

  private:
    /** Default Constructor. */
    BasTravelCCMType ();
    /** Default copy constructor. */
    BasTravelCCMType (const BasTravelCCMType&);
    
    
  private:
    // /////// Attributes /////////
    /** Customer-choice model type (e.g., Preferenced-based, Logit). */
    EN_CCMType _type;
  };
  
}
#endif // __STDAIR_BAS_BASTRAVELCCMTYPE_HPP

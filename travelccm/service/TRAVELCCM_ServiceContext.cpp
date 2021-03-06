 // //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <sstream>
// TravelCCM Basic
#include <travelccm/service/TRAVELCCM_ServiceContext.hpp>

namespace TRAVELCCM {
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::TRAVELCCM_ServiceContext()
    : _ownStdairService (false) {
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::
  TRAVELCCM_ServiceContext (const TRAVELCCM_ServiceContext&) {
    assert (false);
  }
  
  // //////////////////////////////////////////////////////////////////////
  TRAVELCCM_ServiceContext::~TRAVELCCM_ServiceContext() {
  }
  
  // //////////////////////////////////////////////////////////////////////
  const std::string TRAVELCCM_ServiceContext::shortDisplay() const {
    std::ostringstream oStr;
    oStr << "TRAVELCCM_ServiceContext -- Owns StdAir service: "
         << _ownStdairService;
    return oStr.str();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TRAVELCCM_ServiceContext::display() const {
    std::ostringstream oStr;
    oStr << shortDisplay();
    return oStr.str();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string TRAVELCCM_ServiceContext::describe() const {
    return shortDisplay();
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVELCCM_ServiceContext::reset() {

    // The shared_ptr<>::reset() method drops the refcount by one.
    // If the count result is dropping to zero, the resource pointed to
    // by the shared_ptr<> will be freed.
    
    // Reset the stdair shared pointer
    _stdairService.reset();
  }

}

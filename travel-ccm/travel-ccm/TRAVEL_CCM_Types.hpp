#ifndef __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP
#define __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <vector>
#include <list>

namespace TRAVEL_CCM {

   // ///////// Exceptions ///////////
  class RootException : public std::exception {
  };

  class FileNotFoundException : public RootException {
  };
  
  class NonInitialisedServiceException : public RootException {
  };

  class MemoryAllocationException : public RootException {
  };

  class ObjectNotFoundException : public RootException {
  };

  class DocumentNotFoundException : public RootException {
  };


  // /////////////// Log /////////////
  /** Level of logs. */
  namespace LOG {
    typedef enum {
      CRITICAL = 0,
      ERROR,
      NOTIFICATION,
      WARNING,
      DEBUG,
      VERBOSE,
      LAST_VALUE
    } EN_LogLevel;
  }

  // //////// Type definitions /////////
  
}
#endif // __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP

#ifndef __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP
#define __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <vector>
#include <list>
// Boost (Extended STL)
#include <boost/date_time/gregorian/gregorian.hpp>
// Boost
#include <boost/date_time/posix_time/posix_time.hpp>

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
  /** Define the Duration (e.g., elapsed in-flight time). */
  typedef boost::posix_time::time_duration Duration_T;

  /** Define the Date (e.g., flight-date departure date). */
  typedef boost::gregorian::date Date_T;
    
}
#endif // __TRAVEL_CCM_TRAVEL_CCM_TYPES_HPP

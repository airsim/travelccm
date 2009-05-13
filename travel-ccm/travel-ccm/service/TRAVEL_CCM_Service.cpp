// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// STL
#include <iomanip>
#include <sstream>
#include <iostream>
// TRAVEL-CCM
#include <travel-ccm/basic/BasConst_TRAVEL_CCM_Service.hpp>
#include <travel-ccm/factory/FacTRAVEL_CCMServiceContext.hpp>
#include <travel-ccm/command/Simulator.hpp>
#include <travel-ccm/service/TRAVEL_CCM_ServiceContext.hpp>
#include <travel-ccm/service/Logger.hpp>
#include <travel-ccm/TRAVEL_CCM_Service.hpp>

namespace TRAVEL_CCM {

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service () :
    _travel_ccmServiceContext (NULL) {
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service (const TRAVEL_CCM_Service& iService) :
    _travel_ccmServiceContext (iService._travel_ccmServiceContext) {
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::TRAVEL_CCM_Service (std::ostream& ioLogStream) {
    // Initialise the context
    init (ioLogStream);
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_Service::~TRAVEL_CCM_Service () {
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::init (std::ostream& ioLogStream) {
    // Set the log file
    logInit (LOG::DEBUG, ioLogStream);

    // Initialise the context
    TRAVEL_CCM_ServiceContext& lTRAVEL_CCM_ServiceContext = 
      FacTRAVEL_CCMServiceContext::instance().create ();
    _travel_ccmServiceContext = &lTRAVEL_CCM_ServiceContext;
  }
  
  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::logInit (const LOG::EN_LogLevel iLogLevel,
                                    std::ostream& ioLogOutputFile) {
    Logger::instance().setLogParameters (iLogLevel, ioLogOutputFile);
  }

  // //////////////////////////////////////////////////////////////////////
  void TRAVEL_CCM_Service::simulate() const {
    // Call the underlying Use Case (command)
    Simulator::simulate();
  }

}

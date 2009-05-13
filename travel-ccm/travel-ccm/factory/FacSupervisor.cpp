// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL-CCM
#include <travel-ccm/factory/FacBomAbstract.hpp>
#include <travel-ccm/factory/FacServiceAbstract.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacSupervisor* FacSupervisor::_instance = NULL;

  // //////////////////////////////////////////////////////////////////////
  FacSupervisor& FacSupervisor::instance() {
    if (_instance == NULL) {
      _instance = new FacSupervisor();
    }

    return *_instance;
  }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::registerBomFactory (FacBomAbstract* ioFacAbstract_ptr) {
    _bomPool.push_back (ioFacAbstract_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::
  registerServiceFactory (FacServiceAbstract* ioFacServiceAbstract_ptr) {
    _svcPool.push_back (ioFacServiceAbstract_ptr);
  }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::registerLoggerService (Logger* ioLogger_ptr) {
    _logger = ioLogger_ptr;
  }

  // //////////////////////////////////////////////////////////////////////
  FacSupervisor::~FacSupervisor() {
    cleanBomLayer();
    cleanServiceLayer();
    cleanLoggerService();
 }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::cleanBomLayer() {
    for (BomFactoryPool_T::const_iterator itFactory = _bomPool.begin();
         itFactory != _bomPool.end(); itFactory++) {
      const FacBomAbstract* currentFactory_ptr = *itFactory;
      assert (currentFactory_ptr != NULL);

      delete (currentFactory_ptr); currentFactory_ptr = NULL;
    }

    // Empty the pool of Bom Factories
    _bomPool.clear();
  }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::cleanServiceLayer() {
    for (ServiceFactoryPool_T::const_iterator itFactory = _svcPool.begin();
         itFactory != _svcPool.end(); itFactory++) {
      const FacServiceAbstract* currentFactory_ptr = *itFactory;
      assert (currentFactory_ptr != NULL);

      delete (currentFactory_ptr); currentFactory_ptr = NULL;
    }

    // Empty the pool of Service Factories
    _svcPool.clear();
  }

  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::cleanLoggerService() {
    delete _logger; _logger = NULL;
  }
  
  // //////////////////////////////////////////////////////////////////////
  void FacSupervisor::cleanFactory () {
	if (_instance != NULL) {
		_instance->cleanBomLayer();
		_instance->cleanServiceLayer();
        _instance->cleanLoggerService();
 	}
    delete (_instance); _instance = NULL;
  }

}

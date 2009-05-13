// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL-CCM
#include <travel-ccm/service/TRAVEL_CCM_ServiceContext.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/factory/FacTRAVEL_CCMServiceContext.hpp>

namespace TRAVEL_CCM {

  FacTRAVEL_CCMServiceContext* FacTRAVEL_CCMServiceContext::_instance = NULL;

  // //////////////////////////////////////////////////////////////////////
  FacTRAVEL_CCMServiceContext::~FacTRAVEL_CCMServiceContext () {
    _instance = NULL;
  }

  // //////////////////////////////////////////////////////////////////////
  FacTRAVEL_CCMServiceContext& FacTRAVEL_CCMServiceContext::instance () {

    if (_instance == NULL) {
      _instance = new FacTRAVEL_CCMServiceContext();
      assert (_instance != NULL);
      
      FacSupervisor::instance().registerServiceFactory (_instance);
    }
    return *_instance;
  }

  // //////////////////////////////////////////////////////////////////////
  TRAVEL_CCM_ServiceContext& FacTRAVEL_CCMServiceContext::create () {
    TRAVEL_CCM_ServiceContext* aServiceContext_ptr = NULL;

    aServiceContext_ptr = new TRAVEL_CCM_ServiceContext ();
    assert (aServiceContext_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aServiceContext_ptr);

    return *aServiceContext_ptr;
  }

}

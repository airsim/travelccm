// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVEL_CCM 
#include <travel-ccm/factory/FacRequest.hpp>
#include <travel-ccm/bom/Request.hpp>
#include <travel-ccm/factory/FacSupervisor.hpp>
#include <travel-ccm/service/Logger.hpp>

namespace TRAVEL_CCM {

  FacRequest* FacRequest::_instance = NULL;

  // ////////////////////////////////////////////////////////////////////
  FacRequest::~FacRequest () {
    _instance = NULL;
  }

  // ////////////////////////////////////////////////////////////////////
  FacRequest& FacRequest::instance () {

    if (_instance == NULL) {
      _instance = new FacRequest();
      assert (_instance != NULL);

      FacSupervisor::instance().registerBomFactory (_instance);
    }
    return *_instance;
  }

  // ////////////////////////////////////////////////////////////////////
  Request& FacRequest::create () {
    Request* aRequest_ptr = NULL;

    aRequest_ptr = new Request ();
    assert (aRequest_ptr != NULL);

    // The new object is added to the Bom pool
    _pool.push_back (aRequest_ptr);

    return *aRequest_ptr;
  }

}


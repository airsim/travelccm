// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// TRAVELCCM 
#include <travelccm/factory/FacRequest.hpp>
#include <travelccm/bom/Request.hpp>
#include <travelccm/factory/FacSupervisor.hpp>
#include <travelccm/service/Logger.hpp>

namespace TRAVELCCM {

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


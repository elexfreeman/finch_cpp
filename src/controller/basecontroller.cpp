#include "basecontroller.h"

BaseController::BaseController(HttpRequest& aRequest, HttpResponse& aResponse, JConnectionPoll* aPool)

{
    qDebug("BaseController: created");
    pool = aPool;
    request = &aRequest;
    response = &aResponse;
}

BaseController::~BaseController() {};

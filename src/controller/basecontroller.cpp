#include "basecontroller.h"

BaseController::BaseController(HttpRequest& aRequest, HttpResponse& aResponse, JDBConnect* adbConn)

{
    qDebug("BaseController: created");
    dbConn = adbConn;
    request = &aRequest;
    response = &aResponse;
}

BaseController::~BaseController() {};

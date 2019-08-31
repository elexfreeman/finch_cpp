#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H
#include "../system/DBSys/jdbconnect.h"
#include "httprequest.h"
#include "httprequesthandler.h"
#include "httpresponse.h"

using namespace finch;

/**
 * @brief The BaseController class базовый класс для контролера маршрута
 * Вход: Объект приложения, request, response, dbConn
 */
class BaseController {

public:
    QByteArray path;

protected:
    JDBConnect* dbConn;
    HttpRequest* request;
    HttpResponse* response;

    BaseController(HttpRequest& aRequest, HttpResponse& aResponse, JDBConnect* adbConn);
    ~BaseController();
};

#endif // BASECONTROLLER_H

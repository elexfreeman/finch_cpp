#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H
#include "../system/DBSys/connectionpoll.h"

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
    JConnectionPoll* pool;
    HttpRequest* request;
    HttpResponse* response;

    BaseController(HttpRequest& aRequest, HttpResponse& aResponse, JConnectionPoll* aPool);
    ~BaseController();
};

#endif // BASECONTROLLER_H

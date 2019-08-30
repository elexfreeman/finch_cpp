#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H
#include "../jdbconnect.h"
#include "httprequest.h"
#include "httprequesthandler.h"
#include "httpresponse.h"

using namespace finch;

/**
 * @brief The BaseController class базовый класс для контролера маршрута
 * Вход: Объект приложения, request, response, dbConn
 */
class BaseController : public HttpRequestHandler {
  Q_OBJECT
 public:
  QByteArray path;

 protected:
  JDBConnect* dbConn;

  BaseController(QObject* parent, JDBConnect* adbConn);
};

#endif  // BASECONTROLLER_H

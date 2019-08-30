#include "usercontroller.h"

UserController::UserController(QObject* parent, JDBConnect* adbConn)
  : BaseController(parent, adbConn)
{}

/**
 * @brief UserController::init инициализация
 * @param request
 * @param response
 */
void
UserController::init(HttpRequest& request, HttpResponse& response)
{
  qDebug() << "user";
  path = request.getPath();
  if (path.toStdString() == "/user/getUserInfo") {
    getUserInfo(request, response);
  }
};

/**
 * @brief UserController::getUserInfo - информация об юзере по token
 * @param request
 * @param response
 */
void
UserController::getUserInfo(HttpRequest& request, HttpResponse& response)
{
  response.setHeader("Content-Type", "application/json; charset=UTF-8");
  response.setCookie(HttpCookie("firstCookie",
                                "hello",
                                600,
                                QByteArray(),
                                QByteArray(),
                                QByteArray(),
                                false,
                                true));
  response.setCookie(HttpCookie("secondCookie", "world", 600));

  QByteArray body("");

  QJsonObject object{ { "property1", "Привет" }, { "property2", 2 } };
  QJsonDocument doc(object);
  body.append(doc.toJson(QJsonDocument::Compact));

  response.write(body, true);
}

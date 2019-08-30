#include "usercontroller.h"

UserController::UserController(QObject* parent, JDBConnect* adbConn)
    : BaseController(parent, adbConn)
{
}

/**
 * @brief UserController::init инициализация
 * @param request
 * @param response
 */
void UserController::init(HttpRequest& request, HttpResponse& response)
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
void UserController::getUserInfo(HttpRequest& request, HttpResponse& response)
{
    response.setHeader("Content-Type", "application/json; charset=UTF-8");
    QByteArray body("");

    UserDB* userDB = new UserDB(this, dbConn);

    QJsonObject obj;
    obj["user"] = userDB->getUserInfoById(1)->asJson();

    delete userDB;
    //delete userE;

    QJsonDocument doc(obj);
    body.append(doc.toJson(QJsonDocument::Compact));

    response.write(body, true);
}

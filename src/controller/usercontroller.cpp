#include "usercontroller.h"

UserController::UserController(HttpRequest& aRequest, HttpResponse& aResponse, JDBConnect* adbConn)
    : BaseController(aRequest, aResponse, adbConn)
{
}

UserController::~UserController() {};

/**
 * @brief UserController::init инициализация
 * @param request
 * @param response
 */
void UserController::init()
{
    qDebug() << "user";
    path = request->getPath();
    if (path.toStdString() == "/user/getUserInfo") {
        getUserInfo();
    }
};

/**
 * @brief UserController::getUserInfo - информация об юзере по token
 * @param request
 * @param response
 */
void UserController::getUserInfo()
{
    response->setHeader("Content-Type", "application/json; charset=UTF-8");
    QByteArray body("");
    qDebug() << "user getUserInfo";

    UserE* userE;
    UserDB* userDB = new UserDB(dbConn);
    userE = userDB->getUserInfoById(1);
    qDebug() << "username" << userE->username;

    QJsonObject obj;
    obj["user"] = userE->asJson();

    delete userDB;
    delete userE;

    QJsonDocument doc(obj);
    body.append(doc.toJson(QJsonDocument::Compact));

    response->write(body, true);
}

#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../DB/userdb.h"
#include "basecontroller.h"
#include <QObject>
class UserController : public BaseController
{
public:
  UserController(QObject* parent, JDBConnect* adbConn);

  void init(HttpRequest& request, HttpResponse& response);
  void getUserInfo(HttpRequest& request, HttpResponse& response);
};

#endif // USERCONTROLLER_H

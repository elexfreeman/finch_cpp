#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>
#include "basecontroller.h"

class UserController : public BaseController {
 public:
  UserController(QObject* parent, JDBConnect* adbConn);

  void init(HttpRequest& request, HttpResponse& response);
  void getUserInfo(HttpRequest& request, HttpResponse& response);
};

#endif  // USERCONTROLLER_H

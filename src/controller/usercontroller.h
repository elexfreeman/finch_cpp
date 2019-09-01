#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../DB/userdb.h"
#include "basecontroller.h"
#include <QObject>
class UserController : public BaseController {
public:
    UserController(HttpRequest& aRequest, HttpResponse& aResponse, JConnectionPoll* aPool);
    virtual ~UserController();
    void init();
    void getUserInfo();
};

#endif // USERCONTROLLER_H

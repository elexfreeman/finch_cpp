#include "usere.h"

UserE::UserE()
{
    id = 0;
    username = "";
    login = "";
    pass = "";
}

QJsonObject UserE::asJson()
{
    QJsonObject resp;
    resp["id"] = id;
    resp["username"] = username;
    resp["login"] = login;
    resp["pass"] = pass;
    return resp;
}

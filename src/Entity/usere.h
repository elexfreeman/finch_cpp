#ifndef USERE_H
#define USERE_H
#include "baseentity.h"
#include <QString>

class UserE : public BaseEntity {
public:
    int id;
    QString username;
    QString login;
    QString pass;

    UserE();

    QJsonObject asJson();
};

#endif // USERE_H

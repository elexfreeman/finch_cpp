#include "baseentity.h"

BaseEntity::BaseEntity()
{
}

QJsonObject BaseEntity::asJson()
{
    QJsonObject resp;
    resp["obj"] = 0;
    return resp;
}

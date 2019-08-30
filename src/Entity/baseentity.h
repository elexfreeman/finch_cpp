#ifndef BASEENTITY_H
#define BASEENTITY_H
#include <QJsonObject>

class BaseEntity {
public:
    BaseEntity();

    /**
     * @brief asJson - представление как JSON
     * @return JSON
     */
    QJsonObject asJson();
};

#endif // BASEENTITY_H

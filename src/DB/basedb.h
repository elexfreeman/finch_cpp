#ifndef BASEDB_H
#define BASEDB_H

#include "../system/DBSys/connectionpoll.h"

class BaseDB {
protected:
    JConnectionPoll* pool;

public:
    explicit BaseDB(JConnectionPoll* aPool);

signals:

public slots:
};

#endif // BASEDB_H

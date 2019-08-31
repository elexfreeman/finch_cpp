#ifndef BASEDB_H
#define BASEDB_H

#include "../system/DBSys/jdbconnect.h"

class BaseDB {
protected:
    JDBConnect* dbConn;

public:
    explicit BaseDB(JDBConnect* adbConn);

signals:

public slots:
};

#endif // BASEDB_H

#include "basedb.h"

BaseDB::BaseDB(QObject* parent, JDBConnect* adbConn) : QObject(parent) {
  dbConn = adbConn;
}

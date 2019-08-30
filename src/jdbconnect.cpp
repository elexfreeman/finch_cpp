#include "jdbconnect.h"

JDBConnect::JDBConnect() {
  db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("127.0.0.1");
  db.setUserName("root");
  db.setPassword("");
  db.setDatabaseName("web1");
}

bool JDBConnect::bConnect() { return db.open(); }

#ifndef JDBCONNECT_H
#define JDBCONNECT_H
// add DB
#include <QSqlDatabase>
#include <QtSql>

class JDBConnect {
 public:
  QSqlDatabase db;
  JDBConnect();

  bool bConnect();
};

#endif  // JDBCONNECT_H

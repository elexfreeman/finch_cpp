#ifndef BASEDB_H
#define BASEDB_H

#include <QObject>
#include "../jdbconnect.h"

class BaseDB : public QObject {
  Q_OBJECT
 protected:
  JDBConnect* dbConn;

 public:
  explicit BaseDB(QObject* parent, JDBConnect* adbConn);

 signals:

 public slots:
};

#endif  // BASEDB_H

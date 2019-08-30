#include "userdb.h"

UserDB::UserDB(QObject* parent, JDBConnect* adbConn)
    : BaseDB(parent, adbConn) {}

UserE* UserDB::getUserInfoById(int id) {
  QSqlQuery* query;

  QString sql =
      "SELECT u.id, u.username, u.login, u.pass FROM users u WHERE "
      "u.id = :user_id;";

  query = new QSqlQuery(sql, dbConn->db);
  query->prepare(sql);
  query->bindValue(":user_id", id);
  query->exec();

  UserE* userE = new UserE();
  while (query->next()) {
    userE->id = query->value(0).toInt();
    userE->username = query->value(1).toString();
    userE->login = query->value(2).toString();
    userE->pass = query->value(3).toString();
  }

  delete query;

  return userE;
}

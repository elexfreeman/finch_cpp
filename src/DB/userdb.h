#ifndef USERDB_H
#define USERDB_H

#include <QString>
#include "../Entity/usere.h"
#include "basedb.h"

class UserDB : public BaseDB {
 public:
  UserDB(QObject* parent, JDBConnect* adbConn);

  /**
   * @brief getUserInfoById - инфо по userId
   * @param id
   * @return UserE*
   */
  UserE* getUserInfoById(int id);
};

#endif  // USERDB_H

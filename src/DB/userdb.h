#ifndef USERDB_H
#define USERDB_H

#include "../Entity/usere.h"
#include "basedb.h"
#include <QString>

class UserDB : public BaseDB {
public:
    UserDB(JDBConnect* adbConn);

    /**
   * @brief getUserInfoById - инфо по userId
   * @param id
   * @return UserE*
   */
    UserE* getUserInfoById(int id);
};

#endif // USERDB_H

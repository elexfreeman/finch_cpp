#include "userdb.h"

UserDB::UserDB(JConnectionPoll* aPool)
    : BaseDB(aPool)
{
}

void UserDB::getUserInfoById(int id)
{
    UserE* userE = new UserE();
    int connId = QRandomGenerator::global()->bounded(16384);

    qDebug() << "+++ connId:" << connId;
    QString qq = pool->getConnect();
    try {

        QString sql = "SELECT u.id, u.username, u.login, u.pass FROM users u WHERE "
                      "u.id = :user_id;";

        pool->query->prepare(sql);
        pool->query->bindValue(":user_id", id);
        pool->query->exec();
        qDebug() << "+++ query->exec  successful"
                 << "connId:" << connId;

        while (pool->query->next()) {
            userE->id = pool->query->value(0).toInt();
            userE->username = pool->query->value(1).toString();
            userE->login = pool->query->value(2).toString();
            userE->pass = pool->query->value(3).toString();
        }

        pool->query->clear();

        qDebug() << "username" << userE->username;

    } catch (...) {
        qDebug() << ">>> getUserInfoById Error...";
    }

    pool->releaseConnect(qq);
    delete userE;
}

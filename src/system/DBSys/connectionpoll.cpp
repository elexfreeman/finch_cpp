#include "connectionpoll.h"

JConnectionPoll::JConnectionPoll(const QSettings* settings)
{
    connCount = settings->value("connCount").toInt();
    pool.resize(connCount);
    // создаем пул соединений с бд
    for (int i = 0; i < connCount; i++) {
        pool[i] = new JDBConnect(settings);
    }
}

JConnectionPoll::~JConnectionPoll()
{
    for (int i = 0; i < pool.size(); i++) {
        delete pool[i];
    }
}

JConnectionPoll* JConnectionPoll::getInstance(const QSettings* settings)
{
    if (!p_instance)
        p_instance = new JConnectionPoll(settings);
    return p_instance;
}

#ifndef CONNECTIONPOLL_H
#define CONNECTIONPOLL_H
#include "jdbconnect.h"
#include <QSqlDatabase>
#include <QVector>

class JConnectionPoll : public QObject {
    Q_OBJECT
public:
    static JConnectionPoll* p_instance;
    /**
     * @brief pool - пул соединений с БД
     */
    QVector<JDBConnect*> pool;

    int connCount;

    JConnectionPoll(const QSettings* settings);
    ~JConnectionPoll();

    int getFreeConnect();
    void releaseConnect(int connetNumber);

    /**
      * @brief getInstance
      * @return JConnectionPoll singleton
      */
    static JConnectionPoll* getInstance(const QSettings* settings);
};

#endif // CONNECTIONPOLL_H

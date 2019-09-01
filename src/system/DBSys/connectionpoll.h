#ifndef CONNECTIONPOLL_H
#define CONNECTIONPOLL_H
#include "jdbconnect.h"
#include <QQueue>
#include <QRandomGenerator>
#include <QSqlDatabase>

class JConnectionPoll : public QObject {
    Q_OBJECT

public:
    // подклиюение к базе
    QSqlDatabase db;
    QSqlQuery* query;

    // настроки подкл
    const QSettings* settings;

    // очередь на запросы
    QQueue<QString> connQueure;

    // последний номер в очереди
    int queueNumber;

    JConnectionPoll(const QSettings* aSettings);
    ~JConnectionPoll();

    /**
     * @brief getFreeConnect - выдает номер свободного подключния
     * при этом блокирует его для других подключений
     * @return connect number in pool
     */
    QString getConnect();

    /**
     * @brief releaseConnect - освобождает подключение для других клиентов
     * @param connetNumber
     */
    void releaseConnect(QString qq);
};

#endif // CONNECTIONPOLL_H

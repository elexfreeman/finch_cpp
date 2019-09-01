#ifndef JDBCONNECT_H
#define JDBCONNECT_H
// add DB
#include <QSqlDatabase>
#include <QtSql>

class JDBConnect : public QObject {
    Q_OBJECT
public:
    /**
     * @brief db -подключение
     */
    QSqlDatabase db;
    QString connId;

    /**
     * @brief free признак того что свободен
     */
    bool free;
    JDBConnect(const QSettings* settings, QString connName);
    ~JDBConnect();
};

#endif // JDBCONNECT_H

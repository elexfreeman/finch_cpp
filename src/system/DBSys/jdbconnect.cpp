#include "jdbconnect.h"

JDBConnect::JDBConnect(const QSettings* settings, QString connName)
{
    connId = QString::number(QRandomGenerator::global()->bounded(16384));
    db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlDatabase::database(connName);

    db.setHostName(settings->value("hostname").toString());
    db.setUserName(settings->value("username").toString());
    db.setPassword(settings->value("pass").toString());
    db.setDatabaseName(settings->value("dbname").toString());
    if (!db.open()) {
        qFatal("JDBConnect - Connection is not open");
    };
    qDebug() << "JDBConnect: open connect #" << connId;
    free = true;
}

JDBConnect::~JDBConnect()
{
    db.close();
    QSqlDatabase::removeDatabase(connId);
}

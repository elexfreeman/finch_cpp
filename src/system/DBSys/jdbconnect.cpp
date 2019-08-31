#include "jdbconnect.h"

JDBConnect::JDBConnect(const QSettings* settings)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(settings->value("hostname").toString());
    db.setUserName(settings->value("username").toString());
    db.setPassword(settings->value("pass").toString());
    db.setDatabaseName(settings->value("dbname").toString());
    if (!db.open()) {
        qFatal("Connection is not open");
    };

    free = true;
}

JDBConnect::~JDBConnect()
{
    db.close();
}

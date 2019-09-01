#include "connectionpoll.h"

JConnectionPoll::JConnectionPoll(const QSettings* aSettings)
{
    settings = aSettings;
    qDebug() << "JDBConnect: hostname:" << settings->value("hostname").toString();
    qDebug() << "JDBConnect: username:" << settings->value("username").toString();
    qDebug() << "JDBConnect: pass:" << settings->value("pass").toString();
    qDebug() << "JDBConnect: dbname:" << settings->value("dbname").toString();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(settings->value("hostname").toString());
    db.setUserName(settings->value("username").toString());
    db.setPassword(settings->value("pass").toString());
    db.setDatabaseName(settings->value("dbname").toString());

    if (!db.open()) {
        qFatal("JConnectionPoll - Connection is not open");
    };

    query = new QSqlQuery(db);
}

JConnectionPoll::~JConnectionPoll()
{
    delete query;
}

QString JConnectionPoll::getConnect()
{
    QString myQueue = QString::number(queueNumber) + QString::number(QRandomGenerator::global()->bounded(16384));
    qDebug() << ">>>>>>>>>>>>>>> myQueue" << myQueue;
    queueNumber++;
    connQueure.enqueue(myQueue);

    bool bMyQ = false;
    while (!bMyQ) {
        //qDebug() << ">>>>>>>>>>>>>>> head " << connQueure.head();
        if (connQueure.head() == myQueue) {
            bMyQ = true;
        }
    }

    return myQueue;
}

void JConnectionPoll::releaseConnect(QString qq)
{
    qDebug() << " >>>>>>>> releaseConnect" + qq << " +++++++++++++++++++++";
    connQueure.dequeue();
}

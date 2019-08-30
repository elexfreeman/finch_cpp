#include "basecontroller.h"

BaseController::BaseController(QObject* parent, JDBConnect* adbConn)
    : HttpRequestHandler(parent) {
  qDebug("BaseController: created");
  dbConn = adbConn;
}

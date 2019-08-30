/**
  @file
  @author Stefan Frings
*/

#include "requestmapper.h"
#include "DB/userdb.h"
#include "controller/dumpcontroller.h"
#include "controller/fileuploadcontroller.h"
#include "controller/formcontroller.h"
#include "controller/sessioncontroller.h"
#include "controller/templatecontroller.h"
#include "filelogger.h"
#include "global.h"
#include "staticfilecontroller.h"
#include <QCoreApplication>

#include "controller/usercontroller.h"

RequestMapper::RequestMapper(QObject* parent, JDBConnect* adbConn)
  : HttpRequestHandler(parent)
{
  qDebug("RequestMapper: created");
  dbConn = adbConn;
}

RequestMapper::~RequestMapper()
{
  qDebug("RequestMapper: deleted");
}

void
RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
  QByteArray path = request.getPath();
  QByteArray headers = request.getHeader("host");

  qDebug("RequestMapper: path=%s", path.data());
  qDebug("RequestHeaders: path=%s", headers.data());

  if (request.getMethod() == "GET") {
    if (path.startsWith("/user")) {

      UserController* userC = new UserController(this, dbConn);
      userC->init(request, response);

      delete userC;

    } else if (path.startsWith("/dump")) {
      qDebug() << "dump";

      UserE* userE;
      UserDB* userDB = new UserDB(this, dbConn);
      userE = userDB->getUserInfoById(1);
      qDebug() << "username" << userE->username;

      delete userDB;
      delete userE;

      DumpController().service(request, response);
    }

    else if (path.startsWith("/template")) {
      TemplateController().service(request, response);
    }

    else if (path.startsWith("/form")) {
      FormController().service(request, response);
    }

    else if (path.startsWith("/file")) {
      FileUploadController().service(request, response);
    }

    else if (path.startsWith("/session")) {
      SessionController().service(request, response);
    }

    // All other pathes are mapped to the static file controller.
    // In this case, a single instance is used for multiple requests.
    else {
      staticFileController->service(request, response);
    }

  } else if (request.getMethod() == "POST") {
  }

  // For the following pathes, each request gets its own new instance of the
  // related controller.

  qDebug("RequestMapper: finished request");
  // Clear the log buffer
  if (logger) {
    logger->clear();
  }
}

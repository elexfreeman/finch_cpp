/**
  @file
  @author Stefan Frings
*/

#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "./system/DBSys/connectionpoll.h"
#include "httprequesthandler.h"

using namespace finch;

/**
  The request mapper dispatches incoming HTTP requests to controller classes
  depending on the requested path.
*/

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(RequestMapper)

public:
    JConnectionPoll* pool;
    QSqlQuery query;
    /**
      Constructor.
      @param parent Parent object
    */
    RequestMapper(QObject* parent, JConnectionPoll* aPool);

    /**
      Destructor.
    */
    ~RequestMapper();

    /**
      Dispatch incoming HTTP requests to different controllers depending on the URL.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // REQUESTMAPPER_H

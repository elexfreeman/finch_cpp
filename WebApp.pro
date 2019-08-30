# This project demonstrates how to use QtWebAppLib by including the
# sources into this project.

TARGET = WebApp
TEMPLATE = app
QT = core network
CONFIG += console
QT += sql
QTPLUGIN += QSQLMYSQL
HEADERS += \
           QtWebApp/qtservice/qtservice.h \
           QtWebApp/qtservice/qtservice_p.h \
           QtWebApp/qtservice/qtunixserversocket.h \
           QtWebApp/qtservice/qtunixsocket.h \
           src/DB/basedb.h \
           src/DB/userdb.h \
           src/Entity/usere.h \
           src/controller/basecontroller.h \
           src/controller/usercontroller.h \
           src/documentcache.h \
           src/global.h \
           src/jdbconnect.h \
           src/requestmapper.h \
           src/controller/dumpcontroller.h \
           src/controller/templatecontroller.h \
           src/controller/formcontroller.h \
           src/controller/fileuploadcontroller.h \
           src/controller/sessioncontroller.h \
           src/system/sysobjects.h

SOURCES += src/main.cpp \
           QtWebApp/qtservice/qtservice.cpp \
           QtWebApp/qtservice/qtservice_unix.cpp \
           #QtWebApp/qtservice/qtservice_win.cpp \
           QtWebApp/qtservice/qtunixserversocket.cpp \
           QtWebApp/qtservice/qtunixsocket.cpp \
           src/DB/basedb.cpp \
           src/DB/userdb.cpp \
           src/Entity/usere.cpp \
           src/controller/basecontroller.cpp \
           src/controller/usercontroller.cpp \
           src/global.cpp \
           src/jdbconnect.cpp \
           src/requestmapper.cpp \
           src/controller/dumpcontroller.cpp \
           src/controller/templatecontroller.cpp \
           src/controller/formcontroller.cpp \
           src/controller/fileuploadcontroller.cpp \
           src/controller/sessioncontroller.cpp \
           src/system/sysobjects.cpp

OTHER_FILES += etc/* etc/docroot/* etc/templates/* etc/ssl/* logs/* ../readme.txt

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(./QtWebApp/logging/logging.pri)
include(./QtWebApp/httpserver/httpserver.pri)
include(./QtWebApp/templateengine/templateengine.pri)
# Not used: include(../QtWebApp/qtservice/qtservice.pri)

DISTFILES += \
    README.md

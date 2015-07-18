#include <QCoreApplication>
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "server.h"
#include "websocketserver.h"

int main(int argc, char *argv[])
{
    // begin tcp server
    QCoreApplication a(argc, argv);
    CCGTableTopServer tcpserver;
    tcpserver.startServer(4747);

    // begin web socket listener
    QCommandLineParser parser;
    parser.setApplicationDescription("CCGTableTop Server");
    parser.addHelpOption();

    QCommandLineOption dbgOption(QStringList() << "d" << "debug",
    QCoreApplication::translate("main", "Debug output [default: off]."));
    parser.addOption(dbgOption);
    QCommandLineOption portOption(QStringList() << "p" << "port",
    QCoreApplication::translate("main", "Port for server [default: 1234]."),
    QCoreApplication::translate("main", "port"), QLatin1Literal("80"));
    parser.addOption(portOption);
    parser.process(a);

    bool debug = parser.isSet(dbgOption);
    debug = 1;
    int port = parser.value(portOption).toInt();

    WebSocketServer *server = new WebSocketServer(port, debug);
    QObject::connect(server, &WebSocketServer::closed, &a, &QCoreApplication::quit);
    return a.exec();
}

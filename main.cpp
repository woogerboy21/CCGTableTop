#include <QCoreApplication>
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include "server.h"
#include "websocketserver.h"

int main(int argc, char *argv[])
{
	
	bool enableTCPServer = true;
	bool enableWSServer = true;

	QCoreApplication a(argc, argv);
	QCommandLineParser parser;
	parser.setApplicationDescription("CCGTableTop Server");
	parser.addHelpOption();
	QCommandLineOption dbgOption(QStringList() << "d" << "debug",
	QCoreApplication::translate("main", "Debug output [default: false]."));
	parser.addOption(dbgOption);
	QCommandLineOption portOption(QStringList() << "p" << "port",
	QCoreApplication::translate("main", "Port for WebSocket server [default: 80]."),
	QCoreApplication::translate("main", "port"), QLatin1Literal("80"));
	parser.addOption(portOption);
	parser.process(a);

	bool debug = parser.isSet(dbgOption);
	int port = parser.value(portOption).toInt();
	debug = true;

	if (enableTCPServer) {
		CCGTableTopServer tcpserver;
		tcpserver.startServer(4747);
	}

	if (enableWSServer) {
		WebSocketServer *server = new WebSocketServer(port, debug);
		QObject::connect(server, &WebSocketServer::closed, &a, &QCoreApplication::quit);

	}

	return a.exec();
}

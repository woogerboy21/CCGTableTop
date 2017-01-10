#include "server.h"
#include "serverthread.h"

CCGTableTopServer::CCGTableTopServer(QObject *parent) : QTcpServer(parent)
{

}

void CCGTableTopServer::startServer(int port)
{
	if (!this->listen(QHostAddress::Any, port)) {
		qDebug() << "Could not start server";
		return;
	}

    qDebug() << "TCP server listening on port [" << port << "]";
}

void CCGTableTopServer::incomingConnection(qintptr socketDescriptor)
{
	// This function is called by QTcpServer when a new connection is available.
    qDebug() << socketDescriptor << " Connecting...";	// We have a new connection
    CCGTableTopServerThread *thread = new CCGTableTopServerThread(socketDescriptor, this);	// Every new connection will be run in a newly created thread
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));	// connect signal/slot, once a thread is not needed, it will be beleted later
    thread->start();
}

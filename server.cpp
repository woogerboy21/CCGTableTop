#include "server.h"
#include "serverthread.h"

CCGTableTopServer::CCGTableTopServer(QObject *parent) : QTcpServer(parent)
{

}

void CCGTableTopServer::startServer(int port)
{
    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "tcp server listening on port " << port << "...";
    }
}

// This function is called by QTcpServer when a new connection is available.
void CCGTableTopServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    CCGTableTopServerThread *thread = new CCGTableTopServerThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

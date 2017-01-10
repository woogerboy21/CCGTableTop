#include "serverthread.h"
#include "protocolhandler.h"

CCGTableTopServerThread::CCGTableTopServerThread(qintptr ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}

void CCGTableTopServerThread::run()
{
    // thread starts here
    qDebug() << " Thread started";
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))	// set the ID
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal, Qt::DirectConnection is used because it's multithreaded. This makes the slot to be invoked immediately, when the signal is emitted.
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop, thread will stay alive so that signal/slot to function properly not dropped out in the middle when thread dies
    exec();
}

void CCGTableTopServerThread::readyRead()
{
    QByteArray Data = socket->readAll();	// get the information
    qDebug() << socketDescriptor << " Data in: " << Data;	// will write on server side window

	// ** INSERT CODE NEEDED TO PROCESS JSON DATA ** //

    socket->write(Data);
}

void CCGTableTopServerThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}

#ifndef CCGTABLETOPSERVERTHREAD_H
#define CCGTABLETOPSERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class CCGTableTopServerThread : public QThread
{
    Q_OBJECT
public:
    explicit CCGTableTopServerThread(qintptr ID, QObject *parent = 0);
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);
public slots:
    void readyRead();
    void disconnected();
private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // CCGTABLETOPSERVERTHREAD_H

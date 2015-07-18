#ifndef CCGTABLETOPSERVER_H
#define CCGTABLETOPSERVER_H

#include <QTcpServer>

class CCGTableTopServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit CCGTableTopServer(QObject *parent = 0);
    void startServer(int port);
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // CCGTABLETOPSERVER_H

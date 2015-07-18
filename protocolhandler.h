#ifndef PROTOCOLHANDLER_H
#define PROTOCOLHANDLER_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

class ProtocolHandler : public QObject
{
    Q_OBJECT
public:
    explicit ProtocolHandler(QObject *parent = 0);
    QJsonObject processJSONData(QJsonObject &json);

signals:

public slots:

};

#endif // PROTOCOLHANDLER_H

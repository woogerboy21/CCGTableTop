#include "protocolhandler.h"

ProtocolHandler::ProtocolHandler(QObject *parent) : QObject(parent)
{

}

QJsonObject ProtocolHandler::processJSONData(QJsonObject &json)
{
    qDebug() << "JSON Data: [ " << json << " ]";
    QJsonObject results;
    results["response"] = "Success";
    results["reason"] = "Sample Reason";
    return results;
}

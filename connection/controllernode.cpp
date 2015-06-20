#include "controllernode.h"
#include "messagefacade.h"
#include <string>

int ControllerNode::serial = 0;

ControllerNode::ControllerNode(QTcpSocket *pConnector,QObject *parent):
    QObject(parent)
{
    id = serial++;
    _connector =  pConnector;
}

ControllerNode::ControllerNode(QObject *parent):
    QObject(parent)
{

}

int ControllerNode::getId() const
{
    return id;
}

void ControllerNode::closeConnection()
{
    _connector->close();
    _connector->waitForDisconnected(3);
    _connector->destroyed(0);
    delete _connector;

}

void ControllerNode::send(QString pMessage)
{
    std::string m = pMessage.toStdString();
    _connector->write(m.c_str());
    _connector->flush();
    _connector->waitForBytesWritten(24);
}

void ControllerNode::ReadyToRead()
{
    qDebug() <<"Mensaje recibido";
    QString message = _connector->readLine();
    qDebug() << message;
    MessageFacade::getInstance()->interpretMessage(message,this);
}

void ControllerNode::destroyConnection()
{
    emit connectionLost(id);
}

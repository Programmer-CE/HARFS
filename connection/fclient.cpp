#include "fclient.h"


bool FClient::isConnected() const
{
    return _isConnected;
}


QString FClient::getMessage() const
{
    QString Message = "";
    if (!_messages->isEmpty())Message = _messages->dequeue();
    return Message;
}

FClient::FClient(QObject *parent) :
    QObject(parent)
{
    _client = new QTcpSocket(this);
    _messages = new Queue<QString>();
    connect(_client,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(_client,SIGNAL(disconnected()),this,SLOT(unplug()));
    connect(_client,SIGNAL(readyRead()),this,SLOT(ReadyToRead()));
    _isConnected = false;
}

void FClient::connectToHost(QHostAddress pAddress, int pPort)
{
    if (!_isConnected){
        qDebug() << "WATH!!!!";
        //_client->close();
        _client->connectToHost(pAddress,pPort);
        //_isConnected = false;
    }
}

void FClient::onConnected()
{
    _isConnected = true;
    emit connectionOpen();
}

void FClient::unplug()
{
    _isConnected = false;
    emit connectionClosed();
}

void FClient::ReadyToRead()
{
    int lenghtToRead = _client->bytesAvailable();
    _messages->enqueue(_client->read(lenghtToRead));
    emit messageReceive();
}

void FClient::send(QString pMessage)
{
    if (_isConnected){
        _client->write(pMessage.toStdString().c_str());
        _client->flush();
        _client->waitForBytesWritten(24);
    }
}


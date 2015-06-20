#ifndef FCLIENT_H
#define FCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "controlStructure/Queue.h"
class FClient : public QObject
{
    Q_OBJECT
    QTcpSocket *_client;
    bool _isConnected;
    Queue<QString> *_messages;
public:
    explicit FClient(QObject *parent = 0);
    void connectToHost(QHostAddress pAddress, int pPort);
    bool isConnected() const;
    void send(QString pMessage);
    QString getMessage() const;

signals:
    void messageReceive();
    void connectionOpen();
    void connectionClosed();
public slots:
    void onConnected();
    void unplug();
    void ReadyToRead();

};

#endif // FCLIENT_H

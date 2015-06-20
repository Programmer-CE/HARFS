#ifndef FSERVER_H
#define FSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "list/DoubleList.h"
#include "controllernode.h"
#include "test.h"
#include <QMutex>
class FServer : public QTcpServer
{
    Q_OBJECT
    QTcpServer *_server;
    QMutex muter;
    UDoubleList<ControllerNode *> _connectors;
    bool *_serverAvailable;
public:
    explicit FServer(QObject *parent = 0);
    bool openConnection(int pPort);
    void send(QString pMessage, int pControllerNodeId);
    ControllerNode* getControllerById(int pControllerNodeId);
    bool hasConnections();
    void closeServer();
    ~FServer();
    bool *serverAvailable() const;

signals:
    void connectionIsOpen(int pControllerNodeId);
    void fin();

public slots:
    void connectionLost(int pId);
protected:
    void incomingConnection(qintptr socketDescriptor);


};

#endif // FSERVER_H

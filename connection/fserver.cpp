#include "fserver.h"
#include "iostream"
bool FServer::hasConnections()
{
    return _connectors.getLenght() !=0;
}

void FServer::closeServer()
{
    while (_connectors.getLenght() != 0) {
        _connectors.get(0)->closeConnection();
        delete _connectors.get(0);
        _connectors.remove(0);
    }
    _server->close();
    std::cout << "finish" << std::endl;
}

bool *FServer::serverAvailable() const
{
    return _serverAvailable;
}

FServer::FServer(QObject *parent) :
    QTcpServer(parent)
{
    _server = this;
    _serverAvailable = new bool;
    *_serverAvailable = false;
}

bool FServer::openConnection(int pPort)
{
    if (!hasConnections()){
        if (!_server->isListening()){
            qDebug() << "se ha hecho una conexion interna";
            if (!_server->listen(QHostAddress::Any, pPort)){
                return false;
            }
            else{
                qDebug() << "Se escucho el puerto";
                *_serverAvailable = true;
                return true;
            }
        }
    }
    return false;
}

void FServer::send(QString pMessage, int pControllerNodeId)
{
    muter.lock();
    IIterator<ControllerNode*> *iter = _connectors.getIterator();
    for (int x = 0; x < _connectors.getLenght();x++){
        if (pControllerNodeId == iter->getCurrent()->getId()){
            iter->getCurrent()->send(pMessage);
            break;
        }
        iter->getNext();
    }
    delete iter;
    muter.unlock();
}

FServer::~FServer()
{
    closeServer();
    //delete _server;
}

void FServer::connectionLost(int pId)
{
    qDebug() << "connecion perdida";
    muter.lock();
    IIterator<ControllerNode*> *iter = _connectors.getIterator();
    for (int x = 0; x < _connectors.getLenght();x++){
        if (pId == iter->getCurrent()->getId()){
            qDebug() << "se ha encontrado la connexion";
            delete iter->getCurrent();
            _connectors.remove(x);
            break;
        }
        iter->getNext();
    }
    delete iter;
    muter.unlock();
}

void FServer::incomingConnection(qintptr socketDescriptor)
{
    muter.lock();
    std::cout << "Una conexion va a ser abierta" << std::endl;
    qDebug() << "Connexion encontrada";
    QTcpSocket * newconnector = new QTcpSocket();
    newconnector->setSocketDescriptor(socketDescriptor);
    ControllerNode *controllerN = new ControllerNode(newconnector,0);
    _connectors.add(controllerN);
    connect(newconnector,SIGNAL(disconnected()),controllerN,SLOT(destroyConnection()));
    connect(newconnector,SIGNAL(readyRead()),controllerN,SLOT(ReadyToRead()));
    connect(controllerN,SIGNAL(connectionLost(int)),this,SLOT(connectionLost(int)));
    qDebug() << "Finally";
    muter.unlock();
}

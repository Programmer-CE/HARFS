#ifndef CONTROLLERNODE_H
#define CONTROLLERNODE_H
#include <QTcpSocket>
#include <QObject>
class ControllerNode:public QObject
{
    Q_OBJECT
    static int serial;
protected:
    int id;
    QTcpSocket * _connector;

public:
    explicit ControllerNode(QTcpSocket * pConnector,QObject *parent = 0);
    explicit ControllerNode(QObject *parent = 0);
    int getId() const;
    void closeConnection();
    void send(QString pMessage);
signals:
    void connectionLost(int pId);
public slots:
    virtual void ReadyToRead();
    void destroyConnection();
};

#endif // CONTROLLERNODE_H

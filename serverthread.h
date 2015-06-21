#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include "connection/fserver.h"

class ServerThread : public QThread
{
    Q_OBJECT
public:
    FServer *_server;
    bool _run;
    explicit ServerThread(QObject *parent = 0);
    void run();
signals:

public slots:
    void stop(){
        _run =false;
    }

};

#endif // SERVERTHREAD_H

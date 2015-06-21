#include "serverthread.h"
#include "serversender.h"
#include "iostream"

using namespace std;
ServerThread::ServerThread(QObject *parent) :
    QThread(parent)
{
}

void ServerThread::run()
{
    string option;
    char mensaje[50];
    int clientNumber = 0;
    while (option.compare("salir") != 0) {
        cout << "que quiere hacer, enviar o salir" << endl;
        cout << ">>";
        cin >> option;
        if (option.compare("enviar") == 0){
            cout << "a quien quiere enviar el mensaje"<< endl;
            cout << ">>";
            cin >> clientNumber;
            cout << "que mensaje quiere enviar" << endl << ">>";
            cin >> mensaje;
            _server->send(mensaje,clientNumber);
        }
    }
    _server->closeServer();
    _server->close();
    delete _server;
}

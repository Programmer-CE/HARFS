#ifndef MESSAGEFACADE_H
#define MESSAGEFACADE_H
#include "controllernode.h"
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "io/schema.h"
class MessageFacade
{
    static MessageFacade *_instance;
    MessageFacade();
    QString decrypt(QString encryptedMessage);
    QString encrypt(QString messageToEncrypt);
    bool isValidJsonSyntax(QString pMessage, QJsonObject *root);
    void interpretStorageBlockMessage(QJsonObject *root,ControllerNode * pControllerNode);
    void interpretRegisterkMessage(QJsonObject *root,ControllerNode * pControllerNode);
    void interpretUserMessage(QJsonObject *root,ControllerNode * pControllerNode);
    bool createStorageBlock(QJsonObject *root,ControllerNode * pControllerNode);
    bool obtainRaidAndDataStructure(QJsonObject *root,QString *pRaid,QString *pDataStructure);
    /**
     * @brief defineSchema define el squema de la tabla
     * @param root es el root
     * @param pControllerNode
     * @return
     */
    Schema *defineSchema(QJsonObject *root,ControllerNode * pControllerNode);
    bool validatingPrimaryKey(QString primaryKeyName, QJsonObject *columnaPrimaryKey);
public:
    static MessageFacade *getInstance();
    void interpretMessage(QString pMessage,ControllerNode * pControllerNode);
};

#endif // MESSAGEFACADE_H

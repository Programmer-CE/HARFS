#include "messagefacade.h"
#include <QMutex>
#include <iostream>
#include "connectionconstast.h"
#include <QJsonArray>
#include "io/storageblockfacade.h"
QMutex mut;


MessageFacade *MessageFacade::_instance = 0;

MessageFacade::MessageFacade()
{
}

QString MessageFacade::decrypt(QString encryptedMessage)
{
    return encryptedMessage;
}

QString MessageFacade::encrypt(QString messageToEncrypt)
{
    return messageToEncrypt;
}

bool MessageFacade::isValidJsonSyntax(QString pMessage,QJsonObject *root)
{

    QByteArray jsonData = pMessage.toStdString().c_str();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    *root = document.object();
    if(!document.isObject())
    {
        return false;
    }
    else{
        return true;
    }
}

MessageFacade *MessageFacade::getInstance()
{
    mut.lock();
    if (_instance == 0){
        _instance = new MessageFacade();
    }
    mut.unlock();
    return _instance;
}

void MessageFacade::interpretMessage(QString pMessage, ControllerNode *pControllerNode)
{
    mut.lock();
    QJsonObject root;
    // se llama al decifrador
    pMessage = decrypt(pMessage);
    QString messageType;
    //se veridica si cumple con el formato JSON
    if (isValidJsonSyntax(pMessage,&root)){
        //Verifica el tipo de mensaje
        QJsonValue jsonValue = root.value(MESSAGE_TYPE);
        if (!jsonValue.isUndefined() && jsonValue.isString()) {
            messageType = jsonValue.toString();
            //para mensajes de tipo storage block
            if (messageType.compare(MESSAGE_TYPE_STORAGE_BLOCK) == 0){
                interpretStorageBlockMessage(&root,pControllerNode);
            }
            //para mensajes que operen sobre los registros
            else if (messageType.compare(MESSAGE_TYPE_REGISTER) == 0){
                interpretRegisterkMessage(&root,pControllerNode);
            }
            //para mensajes que operen sobre los usarios
            else if (messageType.compare(MESSAGE_TYPE_USER) == 0){
                interpretUserMessage(&root,pControllerNode);
            }
        }
    }
    mut.unlock();

}

void MessageFacade::interpretStorageBlockMessage(QJsonObject *root, ControllerNode *pControllerNode)
{
    QJsonValue jsonValue = root->value(SUB_MESSAGE_TYPE);
    QString messageSubType;
    if (!jsonValue.isUndefined() && jsonValue.isString()) {
        messageSubType = jsonValue.toString();
        // para crear un storage block
        if (messageSubType.compare(SUB_MESSAGE_TYPE_CREATE) == 0){
            createStorageBlock(root,pControllerNode);
        }
        // para listar los storage
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_LIST) == 0){

        }
        // para borrar un storage block
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_ERASE) == 0){

        }
    }
}

void MessageFacade::interpretRegisterkMessage(QJsonObject *root, ControllerNode *pControllerNode)
{
    QJsonValue jsonValue = root->value(SUB_MESSAGE_TYPE);
    QString messageSubType;
    if (!jsonValue.isUndefined() && jsonValue.isString()) {
        messageSubType = jsonValue.toString();
        // para ontener un registro
        if (messageSubType.compare(SUB_MESSAGE_TYPE_OBTAIN) == 0){
            QJsonArray a= jsonValue.toArray();
        }
        // para insertar un registro
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_SAVE) == 0){

        }
        // para borrar un registro
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_ERASE) == 0){

        }
    }
}

void MessageFacade::interpretUserMessage(QJsonObject *root, ControllerNode *pControllerNode)
{
    QJsonValue jsonValue = root->value(SUB_MESSAGE_TYPE);
    QString messageSubType;
    if (!jsonValue.isUndefined() && jsonValue.isString()) {
        messageSubType = jsonValue.toString();
        // para crear un usuario
        if (messageSubType.compare(SUB_MESSAGE_TYPE_CREATE) == 0){

        }
        // para asociar un usuario con un storageblock
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_ASSOCIATE) == 0){

        }
        // para iniciar seccion con el usuario
        else if (messageSubType.compare(SUB_MESSAGE_TYPE_START_SESSION) == 0){

        }
    }
}

bool MessageFacade::createStorageBlock(QJsonObject *root, ControllerNode *pControllerNode)
{

    QString raidType,datastructure;
    QJsonValue jsonValue = root->value(RAID_TYPE);
    //obtiene el raid y la estructura de datos
    bool success = obtainRaidAndDataStructure(root,&raidType,&datastructure);
    if (success){
        Schema *scheme = defineSchema(root,pControllerNode);
        if (scheme){
        }
        else success = false;
    }
    return success;
}

bool MessageFacade::obtainRaidAndDataStructure(QJsonObject *root, QString *pRaid, QString *pDataStructure)
{
    QJsonValue jsonValue = root->value(RAID_TYPE);
    bool success = false;
    if (!jsonValue.isUndefined() && jsonValue.isString()){
        *pRaid = jsonValue.toString();
        success = StorageblockFacade::getInstance()->isValidRaid(*pRaid);
    }
    jsonValue = root->value(DATASTRUCTURE_TYPE);
    if (!jsonValue.isUndefined() && jsonValue.isString()){
        *pDataStructure=jsonValue.toString();
        success = success&&StorageblockFacade::getInstance()->isValidDataStructure(*pDataStructure);
    }
    return success;
}

Schema *MessageFacade::defineSchema(QJsonObject *root, ControllerNode *pControllerNode){
    QJsonValue jsonValue = root->value(SCHEMA);
    if (!jsonValue.isUndefined() && jsonValue.isObject()){
        QJsonObject schema= jsonValue.toObject();
        QJsonValue strings =schema.value(STRING_TYPE);
        QJsonValue ints =schema.value(INT_TYPE);
        QJsonValue primaryKey = schema.value(PRIMARY_KEY);
        if (!strings.isUndefined() && strings.isArray() &&!ints.isUndefined()
                && ints.isArray() && !primaryKey.isUndefined() && primaryKey.isObject()){
            QJsonArray columnaStringType = strings.toArray();
            QJsonArray columnaIntsType = ints.toArray();
            QJsonObject columnaPrimaryKey = primaryKey.toObject();
            bool success = true;
            QJsonObject currentObject;
            for (int x = 0; x < columnaStringType.size(); x++){
                currentObject =columnaStringType.at(x).toObject();
                success = success && currentObject.value(currentObject.keys().at(0)).isDouble();
            }
            for (int x = 0; x < columnaIntsType.size(); x++)success = success && columnaIntsType.at(x).isString();
            QString primaryKeyName =columnaPrimaryKey.keys().at(0);
            qDebug() << "validando....";
            if (success && validatingPrimaryKey(primaryKeyName,&columnaPrimaryKey)){
                qDebug() << "validacion completa el JSON es valido";
                Schema *dataSchema = StorageblockFacade::getInstance()->createSchema(1+columnaIntsType.size()+columnaStringType.size());
                unsigned int sizeOfBytes = 0;
                QJsonObject primaryKeyScheme;
                primaryKeyScheme = columnaPrimaryKey.value(primaryKeyName).toObject();
                if (primaryKeyName.compare(INT_TYPE) == 0)sizeOfBytes = sizeof(int);
                else sizeOfBytes = primaryKeyScheme.value(primaryKeyScheme.keys().at(0)).toInt()*sizeof(char);
                dataSchema->setSchemaOverColumn(0,primaryKeyScheme.keys().at(0).toStdString(),sizeOfBytes,
                (primaryKeyName.compare(INT_TYPE) == 0)?SchemeRow::INT_TYPE:SchemeRow::STRING_TYPE);
                int place= 1;
                for (int x = 0; x < columnaIntsType.size(); x++){
                    currentObject =columnaIntsType.at(x).toObject();
                    dataSchema->setSchemaOverColumn(x+(place++),columnaIntsType.at(x).toString().toStdString(),sizeof(int),SchemeRow::INT_TYPE);
                }
                for (int x = 0; x < columnaStringType.size(); x++){
                    currentObject =columnaStringType.at(x).toObject();
                    currentObject.value(currentObject.keys().at(0)).toString();
                    dataSchema->setSchemaOverColumn(x+place,currentObject.keys().at(0).toStdString(),sizeof(char)*currentObject.value(currentObject.keys().at(0)).toInt(),SchemeRow::STRING_TYPE);
                }
                SchemeRow row;
                QString type;
                for(int x = 0; x < dataSchema->getLenght();x++){
                    row = (*dataSchema)[x];
                    type= (row.getTypeRestrictor()==SchemeRow::INT_TYPE)?"int    ":"string";
                    qDebug() << "| type: "<< type<< "\t| name: " << row.toString().c_str() << "\t\t| size: \t"<< row.getByteSize();
                }
                return dataSchema;
            }
        }
    }
    return 0;
}

bool MessageFacade::validatingPrimaryKey(QString primaryKeyName, QJsonObject *columnaPrimaryKey)
{
    if(primaryKeyName.compare(INT_TYPE) == 0){
        return columnaPrimaryKey->value(INT_TYPE).isString();
    }
    else if(primaryKeyName.compare(STRING_TYPE) == 0){
        if (columnaPrimaryKey->value(primaryKeyName).isObject()){
            QJsonValue primaryKeyScheme;
            primaryKeyScheme = columnaPrimaryKey->value(primaryKeyName);
            if (primaryKeyScheme.isObject()){
                return primaryKeyScheme.toObject().value(primaryKeyScheme.toObject().keys().at(0)).isDouble();
            }
            else return false;
        }
        else return false;
    }
    return false;
}

#ifndef STORAGEBLOCKFACADE_H
#define STORAGEBLOCKFACADE_H
#include "schema.h"
#include <QString>
class StorageblockFacade
{
    static StorageblockFacade* _instance;
    StorageblockFacade();
public:
    static StorageblockFacade *getInstance();
    /**
     * @brief createSchema, crea un esquema para un Storageblock
     * @param leght es la cantidad de columnas que se requieren
     * @return un esquema en memoria dinamica el programador debe de encargase de
     * borrarlo
     */
    Schema *createSchema(unsigned int leght);

    bool isValidRaid(QString raid);
    bool isValidDataStructure(QString pDataStructure);
    QString getAllStorageBlockOnJson();
    void eraseStorageBlock(char pUniqueId[32]);
    QString createStorageBlock(QString pRaidType, QString pDataStructure, Schema* pScheme);
};

#endif // STORAGEBLOCKFACADE_H

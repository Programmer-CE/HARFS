#include "storageblockfacade.h"
#include "connection/connectionconstast.h"

StorageblockFacade::StorageblockFacade()
{
}

StorageblockFacade *StorageblockFacade::getInstance()
{

}

Schema *StorageblockFacade::createSchema(unsigned int leght)
{
    return new Schema(leght);
}

bool StorageblockFacade::isValidRaid(QString raid)
{
    return (raid.compare(RAID_TYPE_NORAID) ==0 || raid.compare(RAID_TYPE_RAID1) == 0);
}

bool StorageblockFacade::isValidDataStructure(QString pDataStructure)
{
    return (pDataStructure.compare(DATASTRUCTURE_TYPE_AVL) ==0 || pDataStructure.compare(DATASTRUCTURE_TYPE_BINARY_TREE) == 0 || pDataStructure.compare(DATASTRUCTURE_TYPE_LINKED_LIST) == 0 || pDataStructure.compare(DATASTRUCTURE_TYPE_B_PLUS_TREE) == 0);
}

QString StorageblockFacade::getAllStorageBlockOnJson()
{
    return "por mientras";
}

void StorageblockFacade::eraseStorageBlock(char pUniqueId[])
{
    // borra el storage block
}

#include "schemerow.h"


int SchemeRow::getByteSize() const
{
    return byteSize;
}

void SchemeRow::setByteSize(int value)
{
    byteSize = value;
}

int SchemeRow::getTypeRestrictor() const
{
    return typeRestrictor;
}

void SchemeRow::setTypeRestrictor(int value)
{
    typeRestrictor = value;
}

SchemeRow::~SchemeRow()
{

}
SchemeRow::SchemeRow()
{
}

SchemeRow::SchemeRow(int pData):RowElement(pData)
{
    
}

SchemeRow::SchemeRow(std::string pData):RowElement(pData)
{

}

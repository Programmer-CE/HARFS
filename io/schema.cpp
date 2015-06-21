#include "schema.h"
#include <QVariant>
#include <string>
Schema::Schema()
{
    scheme = 0;
}

Schema::Schema(unsigned int numberOfColumns)
{
    scheme = new SchemeRow[numberOfColumns];
    lenght = numberOfColumns;
}

bool Schema::setSchemaOverColumn(int columnNum, std::string columnName, unsigned int byteSize,int pType)
{
    if (columnNum < 0 || columnNum >= lenght)return false;
    if (pType != SchemeRow::STRING_TYPE  && pType != SchemeRow::INT_TYPE)return false;
    if (columnName.size() < MAXIMUN_SIZE_COLUMN_NAME){
        scheme[columnNum].setData(columnName);
        scheme[columnNum].setTypeRestrictor(pType);
        scheme[columnNum].setByteSize(byteSize);
    }
}

SchemeRow &Schema::operator[](int columnNum)
{
    if (columnNum < 0 || columnNum >= lenght){
        std::string mensajeDeError = std::string("error");
        throw ArrayIndexOutBounds(mensajeDeError.append(QVariant(columnNum).toString().toStdString()));
    }
    return scheme[columnNum];
}


unsigned int Schema::getLenght()
{
    return lenght;
}
Schema::~Schema()
{
    delete [] scheme;
}

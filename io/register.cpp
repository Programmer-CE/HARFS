#include "register.h"
#include "QVariant"

Register::Register(unsigned int pLength)
{
    lenght = pLength;
    _columns = new RowElement[pLength];
}

RowElement Register::primaryKey()
{
    return _columns[_primaryKey];
}

bool Register::setPrimaryKey(int index)
{
    if (index < 0 || index >= lenght)return false;
    _primaryKey = index;
    return false;
}

RowElement &Register::operator[](int index)
{
    if (index < 0 || index >= lenght){
        std::string mensajeDeError = std::string("error");
        throw ArrayIndexOutBounds(mensajeDeError.append(QVariant(index).toString().toStdString()));
    }
    return _columns[index];
}

Register::~Register()
{
    delete [] _columns;
}

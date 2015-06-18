#include "nosqlrow.h"

NoSQLRow::NoSQLRow(std::string * pSchema, RowElement *pElements, int pLenght)
{
    _schema = pSchema;
    _elements = pElements;
    _lenght = pLenght;
}

RowElement &NoSQLRow::operator[](std::string data)
{
    if (_schema){
        for (int columna = 0;columna < _lenght;columna++){
            if (data.compare(_schema[columna]) == 0){
                return _elements[columna];
            }
        }
        throw ElementDontFounded((std::string("ERROR: No ha sido encontrado el elemento ")).append(data));
    }
    throw NullPointerException("El esquema para la fila es nulo");
}

NoSQLRow::~NoSQLRow()
{
    delete [] _elements;
    _elements = 0;
}

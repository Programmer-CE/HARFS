#include "rowelement.h"
RowElement::RowElement()
{
    _data = 0;
    _type = NULL_TYPE;
}

RowElement::RowElement(int pData)
{
    _data = 0;
    setData(pData);
}

RowElement::RowElement(std::string pData)
{
    _data = 0;
    setData(pData);
}

void RowElement::setData(int pData)
{
    delete _data;
    _data = (void*)(new int(pData));
    _type = INT_TYPE;
    _weight = sizeof(int);
}

void RowElement::setData(std::string pData)
{
    delete _data;
    _type = STRING_TYPE;
    _data = (void*)(new std::string(pData));
    _weight = sizeof(char)*pData.size();
}

std::string RowElement::toString()
{
    if (_type == STRING_TYPE){
        return *((std::string *)(_data));
    }
    throw BadParseException("El elemento no puede ser parseado a una cadena de caracteres");
}

int RowElement::toInt()
{
    if (_type == INT_TYPE){
        return *((int *)(_data));
    }
    throw BadParseException("El elemento no puede ser parseado a entero");

}

int RowElement::getWeight()
{
    return _weight;
}

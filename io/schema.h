#ifndef SCHEMA_H
#define SCHEMA_H
#include "schemerow.h"
#include "arrayindexoutbounds.h"

class Schema
{
    SchemeRow *scheme;
    unsigned int lenght;
public:
    static const int MAXIMUN_SIZE_COLUMN_NAME = 32;
    Schema();
    Schema(unsigned int numberOfColumns);
    bool setSchemaOverColumn(int columnNum, std::string columnName, unsigned int byteSize,int pType);
    SchemeRow &operator[](int columnNum);
    unsigned int getLenght();
    virtual ~Schema();
};

#endif // SCHEMA_H

#ifndef REGISTER_H
#define REGISTER_H
#include "rowelement.h"
#include "arrayindexoutbounds.h"
class Register
{
    RowElement * _columns;
    unsigned int lenght;
public:
    Register(unsigned int pLength);
    RowElement primaryKey();
    RowElement &operator[] (int index);
    virtual ~Register();
};

#endif // REGISTER_H

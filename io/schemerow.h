#ifndef SCHEMEROW_H
#define SCHEMEROW_H
#include "rowelement.h"

class SchemeRow : public RowElement
{
    int byteSize;
    int typeRestrictor;
public:
    SchemeRow();
    SchemeRow(int pData);
    SchemeRow(std::string pData);
    int getByteSize() const;
    void setByteSize(int value);
    int getTypeRestrictor() const;
    void setTypeRestrictor(int value);
    /**
     * @brief ~SchemeRow Debe agregarse el borrado en el RowElement
     */
    virtual ~SchemeRow();
};

#endif // SCHEMEROW_H

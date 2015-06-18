#ifndef NOSQLROW_H
#define NOSQLROW_H
#include "rowelement.h"
#include <string>
#include "nullpointerexception.h"
#include "elementdontfounded.h"
/**
 * @brief Es la clase que representa una fila de una tabla
 * de base de datos nosql
 *
 */
class NoSQLRow
{
    std::string *_schema; /**< TODO */
    RowElement *_elements; /**< TODO */
    int _lenght; /**< TODO */
public:
    /**
     * @brief Es el constructor requiere se un esquema, los elementos
     * que complen con el esquema y por ultimo el largo de el esquema
     * y los elementos
     *
     * @param pSchema es un arreglo de strings, el cual contiene los
     * nombres de las columnas
     * @param pElements son los elementos que pertenecen a la fila
     * @param pLenght es el largo
     */
    NoSQLRow(std::string * pSchema, RowElement * pElements, int pLenght);
    /**
     * @brief Es el operador de busqueda por elementos strings
     *
     * @param pdata es el nombre de la columna de la cual se desea
     * obtener los datos
     * @return RowElement &operator es el dato que pertenece a la fila
     * el cual se busco por el nombre de columna
     * @throw NullPointerException si la fila de elementos es nula
     * @throw ElementDontFounded si pdata no es una fila perteneciente
     */
    RowElement &operator[](std::string pdata);
    /**
     * @brief Es el liberador de memoria
     *
     */
    virtual ~NoSQLRow();
};

#endif // NOSQLROW_H

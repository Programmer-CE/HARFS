#ifndef ROWELEMENT_H
#define ROWELEMENT_H
#include <string>
#include <fstream>
#include "badparseexception.h"
/**
 * @brief Es la clase que representa un elemento de una fila de una
 * tabla de una base de datos
 *
 */
class RowElement
{
    int _type; /**< TODO */
    void *_data; /**< TODO */
    int _weight; /**< TODO */
public:
    static const int NULL_TYPE = 0; /**< TODO */
    static const int INT_TYPE = 1; /**< TODO */
    static const int STRING_TYPE = 2; /**< TODO */
    /**
     * @brief Es el contructor por defecto
     *
     */
    RowElement();
    /**
     * @brief Es el constructor que inicializa el dato interno como
     * in entero
     *
     * @param pData el dato a setear
     */
    RowElement(int pData);
    /**
     * @brief es el constructor que iniciliza el dato interno como un
     * string
     *
     * @param pData el dato que se va a setear como un string
     */
    RowElement(std::string pData);
    /**
     * @brief setea el dato como un entero
     *
     * @param pData el dato a setear
     */
    void setData(int pData);
    /**
     * @brief setea el dato como un string
     *
     * @param pData el dato a setear
     */
    void setData(std::string pData);
    /**
     * @brief retorna el dato como un string si se puede
     *
     * @return std::string el dato como string
     * @throw BadParseException si el dato no es del tipo string
     */
    std::string toString();
    /**
     * @brief retorna el dato con un entero
     *
     * @return int el dato como entero
     * @throw BadParseException si el dato no es del tipo entero
     */
    int toInt();
    /**
     * @brief retorna el tamanio del dato que almacena
     *
     * @return int el tamanio del dato
     */
    int getWeight();
};

#endif // ROWELEMENT_H

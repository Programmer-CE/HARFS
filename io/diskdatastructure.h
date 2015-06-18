#ifndef DISKDATASTRUCTURE_H
#define DISKDATASTRUCTURE_H
#include <string>
/**
 * @brief Es la clase que se encarga de escribir en un archivo
 * de manera que tenga diferentes estructuras de datos.
 * Pueden ser una lista simple, un arbol avl o un arbol binario de
 * busqueda.
 *
 */
class DiskDataStructure
{
public:
    /**
     * @brief Es el contructor
     *
     */
    DiskDataStructure();
    /**
     * @brief Se encarga de escribir un elemento
     *
     * @param pData es el elemento a escribir
     */
    virtual void write(std::string pData) = 0;
    /**
     * @brief se encarga de leer un dato
     *
     * @param pData es la clave del elemento a leer
     * @return std::string es el elemento
     */
    virtual std::string read(std::string pData) = 0;
};

#endif // DISKDATASTRUCTURE_H

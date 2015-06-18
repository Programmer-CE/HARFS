#ifndef ARRAYINDEXOUTBOUNDS_H
#define ARRAYINDEXOUTBOUNDS_H
#include "ioexception.h"
/**
 * @brief Clase ArrayIndexOutBounds es la clase que representa un
 * error al ingresar en una casilla errornea en un arreglo
 *
 */
class ArrayIndexOutBounds:public IOException
{
public:
    /**
     * @brief Es el constructor de la clase inicializando con un
     * mensage.
     *
     * @param pMessage es el mensaje que lanzara el error
     */
    ArrayIndexOutBounds(std::string pMessage);
};

#endif // ARRAYINDEXOUTBOUNDS_H

#ifndef ELEMENTDONTFOUNDED_H
#define ELEMENTDONTFOUNDED_H
#include "ioexception.h"
/**
 * @brief Es un error que se lanza cuando un elemento no es encontrado
 * en un array
 *
 */
class ElementDontFounded:public IOException
{
public:
    /**
     * @brief Es el contructor
     *
     * @param pMessage es el mensaje que se desea lanzar
     */
    ElementDontFounded(std::string pMessage);
};

#endif // ELEMENTDONTFOUNDED_H

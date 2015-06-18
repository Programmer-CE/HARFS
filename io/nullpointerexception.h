#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H
#include "ioexception.h"
/**
 * @brief Representa al error al usar indebidamente un puntero
 * nulo
 *
 */
class NullPointerException:public IOException
{
public:
    /**
     * @brief es el contructor que define el mensaje del error
     *
     * @param pMessage es el mensaje de error
     */
    NullPointerException(std::string pMessage);

    // IOException interface
public:
    /**
     * @brief setea el mensaje de error
     *
     * @param pMessage es el mensaje de error
     */
    void setMessage(std::string pMessage);
    /**
     * @brief retorna el mensaje del error a lanzar
     *
     * @return std::string el mensaje a lanzar
     */
    std::string getMessage();
};

#endif // NULLPOINTEREXCEPTION_H

#ifndef BADPARSEEXCEPTION_H
#define BADPARSEEXCEPTION_H
#include "ioexception.h"
/**
 * @brief Es un error que representa el mal casteo de un dato
 *
 */
class BadParseException:public IOException
{
public:
    /**
     * @brief Inicializa el objeto con el mensaje que se quiera mostrar
     *
     * @param pMessage
     */
    BadParseException(std::string pMessage);

    // IOException interface
public:
    /**
     * @brief Setea el mensaje a mostrarse
     *
     * @param pMessage el mensaje que se mostrara
     */
    void setMessage(std::string pMessage);
    /**
     * @brief obtiene el mensaje
     *
     * @return std::string el mensaje del error
     */
    std::string getMessage();
};

#endif // BADPARSEEXCEPTION_H

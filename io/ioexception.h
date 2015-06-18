#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H
#include <string>
/**
 * @brief Es la clase que representa un error
 *
 */
class IOException
{
protected:
    std::string _message; /**< TODO */
public:
    /**
     * @brief Es el constructor
     *
     */
    IOException();
    /**
     * @brief setea el mensaje a lanzar
     *
     * @param pMessage es el mensaje a lanzar
     */
    virtual void setMessage(std::string pMessage);
    /**
     * @brief obtiene el mensaje a lanzar
     *
     * @return std::string es el mensaje de error a lanzar
     */
    virtual std::string getMessage();
};

#endif // IOEXCEPTION_H

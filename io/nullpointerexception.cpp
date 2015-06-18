#include "nullpointerexception.h"

NullPointerException::NullPointerException(std::string pMessage)
{
    this->_message = pMessage;
}

void NullPointerException::setMessage(std::string pMessage)
{
    this->_message = pMessage;
}

std::string NullPointerException::getMessage()
{
    return _message;
}

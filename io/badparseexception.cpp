#include "badparseexception.h"

BadParseException::BadParseException(std::string pMessage)
{
    _message = pMessage;
}


void BadParseException::setMessage(std::string pMessage)
{
    this->_message = pMessage;
}

std::string BadParseException::getMessage()
{
    return _message;
}

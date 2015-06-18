#include "ioexception.h"

IOException::IOException()
{
}

void IOException::setMessage(std::string pMessage)
{
    _message = pMessage;
}

std::string IOException::getMessage()
{
    return _message;
}

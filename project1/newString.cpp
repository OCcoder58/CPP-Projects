#include "newString.h"
#include <cstring>

namespace mystring
{

String::String()
{
    _length = 0;
    _data = new char[1];
    _data[0] = '\0';
}

String::String(const char* text)
{
    if (text == nullptr)
    {
        _length = 0;
        _data = new char[1];
        _data[0] = '\0';
    }
    else
    {
        _length = std::strlen(text);
        _data = new char[_length + 1];
        std::memcpy(_data, text, _length + 1);
    }
}

String::~String()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

const char* String::getString() const
{
    return _data;
}

std::size_t String::getLength() const
{
    return _length;
}

}

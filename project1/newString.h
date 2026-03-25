#ifndef NEWSTRING_H
#define NEWSTRING_H

#include <cstddef>

namespace mystring {

class String
{
private:
    char* _data;
    std::size_t _length;

public:
    String();
    String(const char* text);
    ~String();

    const char* getString() const;
    std::size_t getLength() const;
};

}

#endif

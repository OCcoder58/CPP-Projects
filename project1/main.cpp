
#include <iostream>
#include "newString.h"

int main()
{
    mystring::String a("Hallo");
    mystring::String b(nullptr);
    mystring::String c;

    std::cout << a.getString() << " (" << a.getLength() << ")\n";
    std::cout << b.getString() << " (" << b.getLength() << ")\n";
    std::cout << c.getString() << " (" << c.getLength() << ")\n";

    return 0;
}

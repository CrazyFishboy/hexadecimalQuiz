#include <iostream>
#include "Hexadecimal.h"


int main(){
    Hexadecimal a("0x0000fffff");
    ++a;
    std::cout << a.getValue() << std::endl;
    Hexadecimal b("");
    Hexadecimal c("000F");
    a = b = c;
    std::cout << a.getValue() << std::endl;

    return 0;
}
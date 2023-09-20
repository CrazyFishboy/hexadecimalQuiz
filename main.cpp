#include <iostream>
#include "Hexadecimal.h"


int main(){
    int x = -1;
    if(Hexadecimal::decimalValueOfCharacter('f',x)){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }
    std::cout << x << std::endl;

    Hexadecimal a("FFFFF");
    Hexadecimal b("200");
    a.addHex(b);
    std::cout << a.getValue() << std::endl;

    return 0;
}
#include <iostream>
#include "Hexadecimal.h"


int main(){
    Hexadecimal a("fffff");
    ++a;
    std::cout << a.getValue() << std::endl;
    Hexadecimal b("");
    Hexadecimal c("FFA");
    a = b = c;
    std::cout << a.getValue() << std::endl;

    return 0;
}
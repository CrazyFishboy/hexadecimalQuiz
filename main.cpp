#include <iostream>
#include "Hexadecimal.h"


int main(){
    Hexadecimal a("0x7846FA");
    Hexadecimal b;
    b.setValue("0x1234");

    std::cout << "a: " << a.getValue() << std::endl;
    std::cout << "b: " << b.getValue() << std::endl;

    return 0;
}
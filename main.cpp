#include <iostream>
#include "Hexadecimal.h"
#include <fstream>


int main(){
    Hexadecimal a("FfF000");
    Hexadecimal b("ff0");
    Hexadecimal d = "0xf1";
    Hexadecimal c;
    c = a + b + d;
    std::cout << a << " + " << b << " + " << d << " = " << c << std::endl;
    return 0;
}
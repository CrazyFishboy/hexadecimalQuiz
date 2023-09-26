#include <iostream>
#include "Hexadecimal.h"
#include <fstream>


int main(){
    Hexadecimal a("FfF00");
    Hexadecimal b("ff");
    Hexadecimal d(1);
    Hexadecimal c;
    c = a + b + d;
    std::cout << a << " + " << b << " + " << d << " = " << c << std::endl;
    return 0;
}
#include <iostream>
#include "Hexadecimal.h"


int main(){
    Hexadecimal a("fffff");
    ++a;
    std::cout << a.getValue() << std::endl;

    return 0;
}
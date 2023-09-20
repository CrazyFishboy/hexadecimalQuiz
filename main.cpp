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

    return 0;
}
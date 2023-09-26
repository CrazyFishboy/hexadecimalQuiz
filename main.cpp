#include <iostream>
#include "Hexadecimal.h"
#include <fstream>


int main(){
    Hexadecimal a("FfF");
    int i = a;
    std::cout << a << ": " << i << std::endl;
    return 0;
}
#include <iostream>
//#include "Hexadecimal.h"
//#include <fstream>
#include <ctime>
#include <random>
#include <string>


int main(){
    unsigned max = 16*16*16*16;
    std::srand(std::time(0));
    int rand = std::rand() % max;
    std::cout << "Hexadecimal: 0x" << std::hex << rand << std::endl;
    std::cout << "Decimal?: ";
    
    
    return 0;
}
#include <iostream>
#include "Hexadecimal.h"
#include <cstdlib>
#include <string>

int main() {
    enum {hexMode, decMode, octMode, binMode};

    short mode = hexMode;

    std::cout << "Hex:\nDec:\nOct:\nBin:" << std::endl;


    std::cout << "Enter a number: ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << "You entered \'" << input << "\'" << std::endl;


    return 0;
}
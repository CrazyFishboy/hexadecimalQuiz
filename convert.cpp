#include <iostream>
#include "Hexadecimal.h"
#include "binary.h"
#include <cstdlib>
#include <string>


/*

Command-line arguments structure should be: 
    -n --number ~ their number to be converted
    -n flag is optional. Anything without a flag will be interpreted as this
    -b --base ~ the base their number is in ~ Default is base 16 (hexadecimal)
    -o --output ~ the desired base of the output ~ Default is base 10 (decimal)
    -h --help ~ displays a help message then quits

*/


/***NEED TO MAKE HEXADECIMAL CLASS SUPPORT MATH OPERATIONS IN THE SET VALUE FUNCTIONS***/

int main(int argc, char *argv[]) {

    short bases[] = {2,8,10,16}; // Binary, Octal, Decimal, Hexadecimal


    if(argc >1){
        std::cout << "Command line arguments detected... They are:" << std::endl;
        for(int i = 0; i < argc; ++i){
            std::cout << i << ": \'" << *(argv+i) << "\'" << std::endl;
        }
    }



    enum {hexMode, decMode, octMode, binMode};

    short mode = hexMode;

    std::cout << "Hex:\nDec:\nOct:\nBin:" << std::endl;
    Hexadecimal hex;

/*
    // Gets input from user
    do {
        std::cout << "Enter a number: ";
        std::string input;
        std::getline(std::cin, input);
        std::cout << "You entered \'" << input << "\'" << std::endl;

        hex = input;
        if(hex.fail()){
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cout << hex << std::endl;
        }
    } while(hex.fail());

*/

    Binary test(-1);
    std::cout << test.getValue() << std::endl;
    test.makeBytes();
    std::cout << test.getValue() << std::endl;



    return 0;
}
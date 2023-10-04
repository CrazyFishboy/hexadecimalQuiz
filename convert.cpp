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

void display(uint64_t num);

int main(int argc, char *argv[]) {


    if(argc >1){
        std::cout << "Command line arguments detected... They are:" << std::endl;
        for(int i = 0; i < argc; ++i){
            std::cout << i << ": \'" << *(argv+i) << "\'" << std::endl;
        }
    }


    uint64_t num = 1103;
    display(num);


    return 0;
}

void display(uint64_t num){
    unsigned counter = 0;
    std::string binary = "";
    while((num>>counter)>0){
        binary = std::to_string((num >> counter) & 1) + binary;
        ++counter;
    }
    std::cout << std::showbase << std::endl;
    std::cout << std::hex << "Hexadecimal: " << num << std::endl;
    std::cout << std::dec << "Decimal: " << num << std::endl;
    std::cout << std::oct << "Octal: " << num << std::endl;
    std::cout << std::dec << "Binary: " << binary << std::endl;
}
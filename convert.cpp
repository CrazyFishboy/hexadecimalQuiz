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


int main(int argc, char *argv[]) {


    if(argc >1){
        std::cout << "Command line arguments detected... They are:" << std::endl;
        for(int i = 0; i < argc; ++i){
            std::cout << i << ": \'" << *(argv+i) << "\'" << std::endl;
        }
    }


    int num = 2000000000;
    std::string binary = "";
    while(num>0){
        //std::cout << n;
        binary = std::to_string(num & 1) + binary;
        num >>= 1;
    }
    
    std::cout << binary << std::endl;
    /*
    for(unsigned i = binary.size(); i > 0; --i){
        std::cout << binary[i-1];
    }
    std::cout << std::endl;

    */





    return 0;
}
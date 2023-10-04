#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


/*

Command-line arguments structure should be: 
    -n --number ~ their number to be converted
    -n flag is optional. Anything without a flag will be interpreted as this
    -b --base ~ the base their number is in ~ Default is base 16 (hexadecimal)
    -o --output ~ the desired base of the output ~ Default is base 10 (decimal)
    -h --help ~ displays a help message then quits

*/

const char validDigits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void display(uint64_t num);
uint64_t convertBase(std::string str, int base);

int main(int argc, char *argv[]) {
    bool numberSpecified = false;
    bool baseSpecified = false;
    bool outputSpecified = false;

    std::string numberStr = "";
    std::string baseStr = "";
    std::string outputBaseStr = "";

    int base = 0;
    int outputBase = 0;

    if(argc >1){
        std::cout << "Command line arguments detected... They are:" << std::endl;
        std::string argument = "";
        for(int i = 1; i < argc; ++i){
            argument = *(argv+i);
            if(argument == "-n" || argument == "--number"){
                if(numberSpecified){
                    std::cout << "Multiple uses of -n flag is not allowed" << std::endl;
                    exit(1);
                }
                numberSpecified = true;
                if(i+1 < argc){ // If there is another argument after flag
                    if(*(argv+i+1)[0] != '-'){ // If the next argument does not start with '-'
                        numberStr = *(argv+i+1);
                        ++i;
                    } else {
                        std::cout << "No number detected after -n flag" << std::endl;
                        exit(1);
                    }
                } else {
                    std::cout << "No number detected after -n flag" << std::endl;
                    exit(1);
                }
            } 
            
            
            else if(argument == "-b" || argument == "--base"){
                if(baseSpecified){
                    std::cout << "Multiple uses of -b flag is not allowed" << std::endl;
                    exit(1);
                }
                baseSpecified = true;
                if(i+1 < argc){ // If there is another argument after flag
                    if(*(argv+i+1)[0] != '-'){ // If the next argument does not start with '-'
                        baseStr = *(argv+i+1);
                        ++i;
                    } else {
                        std::cout << "No number detected after -b flag" << std::endl;
                        exit(1);
                    }
                } else {
                    std::cout << "No number detected after -b flag" << std::endl;
                    exit(1);
                }
            } 
            
            
            else if(argument == "-o" || argument == "--output"){
                if(outputSpecified){
                    std::cout << "Multiple uses of -o flag is not allowed" << std::endl;
                    exit(1);
                }
                outputSpecified = true;
                if(i+1 < argc){ // If there is another argument after flag
                    if(*(argv+i+1)[0] != '-'){ // If the next argument does not start with '-'
                        outputBaseStr = *(argv+i+1);
                        ++i;
                    } else {
                        std::cout << "No number detected after -o flag" << std::endl;
                        exit(1);
                    }
                } else {
                    std::cout << "No number detected after -o flag" << std::endl;
                    exit(1);
                }
            }


            else if(argument == "-h" || argument == "--help"){
                std::cout << "This will be a help message" << std::endl;
                exit(1);
            }
        }
    }

    std::cout << numberStr << std::endl << baseStr << std::endl << outputBaseStr << std::endl;
    if(!numberSpecified){
        std::cout << "A number must be specified. Use -n <number>" << std::endl;
        exit(1);
    }

    if(baseSpecified){
        if(baseStr == "2"){
            base = 2;
        } else if(baseStr == "8"){
            base = 8;
        } else if(baseStr == "10"){
            base = 10;
        } else if(baseStr == "16"){
            base = 16;
        } else {
            std::cout << "Invalid base specified. Supported bases are 2,8,10,16" << std::endl;
            exit(1);
        }
    } else {
        base = 10;
    }

    std::cout << "Base: " << base << std::endl;



    return 0;
}

void display(uint64_t num){

    // Gets the binary representation of the number
    unsigned counter = 0;
    std::string binary = "";
    while((num>>counter)>0){
        binary = std::to_string((num >> counter) & 1) + binary;
        ++counter;
    }

    // Displays the numbers
    std::cout << std::showbase << std::endl;
    std::cout << std::hex << "Hexadecimal: " << num << std::endl;
    std::cout << std::dec << "Decimal: " << num << std::endl;
    std::cout << std::oct << "Octal: " << num << std::endl;
    std::cout << std::dec << "Binary: " << binary << std::noshowbase << std::endl;
}


uint64_t convertBase(std::string str, int base){
    if(base != 2 && base != 8 && base != 10 && base != 16) {
        std::cout << "Invalid base entered" << std::endl;
        exit(1);
    }
    uint64_t value = 0;
    int charVal;
    for(unsigned i = str.size(); i > 0; --i){
        charVal = -1;
        for(int j = 0; j < base; ++j){
            if(str[i-1] == validDigits[j]){
                charVal = j;
                break;
            }
        }
        if(charVal < 0){
            std::cout << "Invalid character detected" << std::endl;
            exit(1);
        }
        value += charVal * (std::pow(base,str.size()-i));
    }
    return value;
}
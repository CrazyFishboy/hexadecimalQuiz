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


    if(argc >1){
        std::cout << "Command line arguments detected... They are:" << std::endl;
        for(int i = 0; i < argc; ++i){
            std::cout << i << ": \'" << *(argv+i) << "\'" << std::endl;
        }
    }

    std::string test = "1D";
    int num = 0;
    num = convertBase(test,16);
    std::cout << num << std::endl;



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
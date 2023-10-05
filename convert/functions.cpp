#include "functions.h"


void display(uint64_t num, int base){

    // Displays the numbers
    std::cout << std::showbase;
    if(base == 16 || base == 0){
        std::cout << std::hex << "Hexadecimal: " << num << std::endl;
    }
    if(base == 10 || base == 0){
        std::cout << std::dec << "Decimal: " << num << std::endl;
    }
    if(base == 18 || base == 0){
        std::cout << std::oct << "Octal: " << num << std::endl;
    }
    if(base == 2 || base == 0){
        // Gets the binary representation of the number
        std::string binary = "";
        while(num>0){
            if(num&1){
                binary = '1' + binary;
            } else {
                binary = '0' + binary;
            }
            num >>= 1;
        }
        while(binary.size() > 1 && binary[0] == '0'){
            binary.assign(binary,1);
        }
        std::cout << "Binary: " << binary <<std::endl;
    }
    // Resets display settings
    std::cout << std::dec << std::noshowbase;
}


uint64_t convertBase(std::string str, unsigned base){
    if(base != 2 && base != 8 && base != 10 && base != 16) {
        std::cout << "Invalid base entered" << std::endl;
        exit(1);
    }
    uint64_t value = 0;
    int charVal;
    int powerOfTwo = 0;
    if(base == 2){
        powerOfTwo = 1;
    } else if(base == 8){
        powerOfTwo = 3;
    } else if(base == 16){
        powerOfTwo = 4;
    }
    
    for(unsigned i = 0; i < str.size(); ++i){
        //std::cout << i << ": " << str[i];
        charVal = -1;
        for(unsigned j = 0; j < base; ++j){
            if(std::tolower(validDigits[j]) == std::tolower(str[i])){
                charVal = j;
                break;
            }
        }
        //std::cout << "~" << charVal << std::endl;
        if(charVal < 0){
            std::cout << "Invalid character detected" << std::endl;
            exit(1);
        }
        
        if(base != 10){
            uint64_t val = std::pow(2,(((str.size()-1)*powerOfTwo)-(powerOfTwo*i))) * charVal;
            value += val;
            //std::cout << std::hex << std::left << std::setw(17) << val << ": " << value << std::endl;
        } else {
            uint64_t val = std::pow(10,((str.size()-1)-i)) * charVal;
            value += val;
            //std::cout << std::hex << std::left << std::setw(17) << val << ": " << value << std::endl;
        }
    }
    return value;
}


void printHelp(){
    std::cout << "Usage: <executable> [options] <number>" << std::endl;
    std::cout << "Options:\n  <number>\tNumber to be converted. Required. Base specifiers " << std::endl;
    std::cout << "\t\t(0b=2,0=8,0x=16) can preceed the number to allow inferring\n";
    std::cout << "\t\tthe base of the number"<< std::endl;
    std::cout << "  -b <number>\tBase of the specified number. Can be 2,8,10,16. Default is 10" << std::endl;
    std::cout << "  -o <number>\tBase of the number output. Can be 2,8,10,16. If not specified\n";
    std::cout << "\t\tthe value will be displayed in the 4 bases" << std::endl;
}
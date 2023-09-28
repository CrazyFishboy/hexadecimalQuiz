#include <iostream>
#include "Hexadecimal.h"
//#include <fstream>
#include <ctime>
#include <random>
#include <string>

std::string cleanInput(const std::string &in);

int main(){
    unsigned max = 16;
    std::srand(std::time(0));
    int rand = std::rand() % max;
    Hexadecimal secret(rand);
    std::cout << "Hexadecimal: 0x" << secret << std::endl;
    std::cout << "Decimal?: ";
    std::string input;
    std::getline(std::cin, input);
    input = cleanInput(input);
    if(input.size() > 0){
        if(std::stoi(input) == rand){
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. The answer was: " << rand << std::endl;
        }
    } else {
        std::cout << "Please only enter digits (0-9)." << std::endl;
    }
    
    
    return 0;
}


std::string cleanInput(const std::string &in){
    std::string replacement;
    for(unsigned i = 0; i < in.size(); ++i){
        if(in[i] >= '0' && in[i] <= '9'){
            replacement += in[i];
        }
    }
    return replacement;
}
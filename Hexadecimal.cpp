#include "Hexadecimal.h"

const int Hexadecimal::base = 16;
const char Hexadecimal::validCharacters [base] {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

bool Hexadecimal::isValidCharacter(char character){
    for(int i = 0; i < base; ++i){
        if(std::tolower(character) == tolower(validCharacters[i])){
            return true;
        }
    }
    return false;
}

void Hexadecimal::setValue(std::string val){
    this->value = val;
}
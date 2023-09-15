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

// Need to make it remove preceeding 0x before number if present
bool Hexadecimal::setValue(std::string val){
    unsigned index = 0;
    if(val.size() > 2){
        if(val[0] == '0' && (val[1] == 'x' || val[1] == 'X')){
            index = 2;
        } 
    }
    for(; index < val.size(); ++index){
        if(!isValidCharacter(val[index])){
            return false;
        }
    }
    value = val;
    return true;
}
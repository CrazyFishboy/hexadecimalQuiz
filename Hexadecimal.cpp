/**
 * @file Hexadecimal.cpp
 * @author Josh Gillum
 * @brief Function definitions for the Hexadecimal class
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Hexadecimal.h"

const int Hexadecimal::base = 16; // Base of this number system.
const char Hexadecimal::validCharacters [base] {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; // All valid characters of this number system


/**
 * @brief Static function. 
 * Returns boolean value for if the argument is a character within the validCharacters array
 * 
 * @param character, a char to be checked
 * @return true, the char is present in the array
 * @return false, the char is not present in the array
 */
bool Hexadecimal::isValidCharacter(char character){
    for(int i = 0; i < base; ++i){
        if(std::tolower(character) == tolower(validCharacters[i])){ // Compares lowercase versions of the chars
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


/**
 * @brief Adds the integer value passed as an argument to the Hexadecimal value.
 * It is assumed that this value is in base 10
 * 
 * @param val, the value to be added to this
 * @return Hexadecimal*, pointer to the Hexadecimal object
 */
Hexadecimal* addDecimal(int val){
    ;

}
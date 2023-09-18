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

Hexadecimal* Hexadecimal::operator++(){
    for(int i = this->value.size() - 1; i >= 0; --i){
        if(std::tolower(value[i]) != std::tolower(validCharacters[base-1])){
            // If character can have 1 added to it, then
            // find the index of the character in valid characters array, and assign its
            // value to valid characters at index + 1
            unsigned index = 0;
            while(std::tolower(value[i]) != std::tolower(validCharacters[index])){
                ++index;
            }
            value[i] = validCharacters[++index];
            return this;
        } else {
            // Otherwise set the value to be the first character of valid characters ("0")
            value[i] = validCharacters[0];
        }
    }
    value = validCharacters[1] + value;
    return this;
}

// Need to make it remove preceeding 0x before number if present
bool Hexadecimal::setValue(std::string val){
    if(val.size() > 0){
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
    return false;
}


/**
 * @brief Adds the integer value passed as an argument to the Hexadecimal value.
 * It is assumed that this value is in base 10
 * 
 * @param val, the value to be added to this
 * @return Hexadecimal*, pointer to the Hexadecimal object
 */
Hexadecimal* Hexadecimal::addDecimal(int val){
    return this;
}
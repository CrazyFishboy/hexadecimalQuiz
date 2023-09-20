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

bool Hexadecimal::decimalValueOfCharacter(char character, int &index){
    for(int i = 0; i < base; ++i){
        if(std::tolower(character) == tolower(validCharacters[i])){
            index = i;
            return true;
        }
    }
    return false;
}


Hexadecimal::Hexadecimal(std::string val){
    if(!setValue(val)){
        value = "0";
    }
}

/**
 * @brief Adds 1 to the current value of the object, then returns a pointer to this object
 * 
 * @return Hexadecimal*, a pointer to this object
 */
Hexadecimal* Hexadecimal::operator++(){
    for(int i = this->getSize() - 1; i >= 0; --i){
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

/**
 * @brief Assignment operator overload. Assigns the value of the object on the right
 * side of the operator to the one on the left (this object)
 * 
 * @param right, the object being copied
 * @return Hexadecimal*, returns a pointer to this object
 */
Hexadecimal* Hexadecimal::operator=(Hexadecimal *right){
    this->value = right->value;
    return this;
}


/**
 * @brief Sets the value of the object to the one provided
 * 
 * @param val, the value to set the object's to
 * @return true, the provided value was valid and the object's value was updated
 * @return false, the provided value was not valid and the object's value was not updated
 */
bool Hexadecimal::setValue(std::string val){
    if(val.size() > 0){
        unsigned index = 0;
        std::string newVal = "";
        if(val.size() > 2){
            if(val[0] == '0' && (val[1] == 'x' || val[1] == 'X')){
                index = 2;
            } 
        }
        bool nonZeroEncounterd = false;
        for(; index < val.size(); ++index){
            if(!isValidCharacter(val[index])){
                return false;
            } else {
                if(!nonZeroEncounterd && val[index] != validCharacters[0]){
                    nonZeroEncounterd = true;
                }
                if(nonZeroEncounterd){
                    newVal += val[index];
                }
            }
        }
        value = newVal;
        return true;
    }
    return false;
}


/**
 * @brief Adds the integer value passed as an argument to the Hexadecimal value.
 * It is assumed that this value is in base 10
 * 
 * @param val, the value to be added to this
 * @return Hexadecimal*, pointer to this object
 */
Hexadecimal* Hexadecimal::addDecimal(int val){
    return this;
}


Hexadecimal* Hexadecimal::addHex(const Hexadecimal &hex){
    int * values = new int [3]; // 0 is remainder from previous, 1 is this object, 2 is hex object
    values[0] = 0;
    std::string otherValue = hex.getValue();
    int thisSize = getSize();
    int thisSizeGrowth = 0;
    int otherSize = hex.getSize();
    for(int i = 1; i <= thisSize+thisSizeGrowth; ++i){
        int temp = 0;
        decimalValueOfCharacter(value[thisSize-i-thisSizeGrowth],temp);
        values[1] = temp;

        if(otherSize - i < 0){
            values[2] = 0;
        } else {
            decimalValueOfCharacter(otherValue[otherSize-i],temp);
            values[2] = temp;
        }

        values[0] += values[1] + values[2];

        int nextPower = values[0]/16;
        values[0] -= nextPower * 16;
        std::cout << nextPower << " " << values[0] << " " << values[1] << " " << values[2] << " " << std::endl;
        this->value[thisSize+thisSizeGrowth-i] = validCharacters[values[0]];
        values[0] = nextPower;
        if(i >= thisSize+thisSizeGrowth){
            if((i < otherSize) || (values[0] > 0)){
                value = validCharacters[0] + value;
                thisSizeGrowth++;
            }
        }

    }

    delete [] values;
    return this;
}
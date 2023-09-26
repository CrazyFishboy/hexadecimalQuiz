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


/**
 * @brief Static function. 
 * Returns boolean value for if the argument is a character within the validCharacters array.
 * Also sets the index parameter to be the index in the validCharacters array that the character is located
 * 
 * @param character, a char to be checked
 * @param &index, the variable to store the index of the character
 * @return true, the char is present in the array
 * @return false, the char is not present in the array
 */
bool Hexadecimal::decimalValueOfCharacter(char character, int &index){
    for(int i = 0; i < base; ++i){
        if(std::tolower(character) == tolower(validCharacters[i])){
            index = i;
            return true;
        }
    }
    return false;
}


/**
 * @brief Constructs a Hexadecimal object from a string. If the provided string is not suitable, sets the value ot 0
 * 
 * @param val, the hexadecimal value to set this object to
 */
Hexadecimal::Hexadecimal(std::string val){
    if(!setValue(val)){
        value = "0";
    }
}


Hexadecimal::Hexadecimal(int val){
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

Hexadecimal::operator int() const{
    int val = 0;
    int power = 0;
    int temp = 0;
    for(int i = this->value.length()-1; i >= 0; --i){
        decimalValueOfCharacter(value[i],temp);
        val += std::pow(16,power) * temp;
        ++power;
    }
    return val;
}


std::ostream &operator<<(std::ostream &out, Hexadecimal obj){
    out << obj.getValue();
    return out;
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
                    newVal += std::toupper(val[index]);
                }
            }
        }
        value = newVal;
        return true;
    }
    return false;
}

bool Hexadecimal::setValue(int val){
    if(val >= 0){
        int power = 0;
        while(std::pow(16,power+1) <= val){
            ++power;
        }
        int index = 0;
        std::string workingValue = "";
        for(;power >= 0; --power){
            index = val / std::pow(16,power);
            workingValue += validCharacters[index];
            val = val - (std::pow(16,power) * index);
        }
        this->value = workingValue;
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
    int * values = new int [3]; 
    values[0] = 0;
    std::string otherValue = hex.getValue(); // value of the hex object being added to this one
    int thisSize = getSize(); // size of this objects hex value
    int thisSizeGrowth = 0; // Keeps track of how many digits had to be added to this object
    int otherSize = hex.getSize(); // size of the value of the hex object being added to this one

    /*
        This function loops through every character of this object's value.
        The values array will store the integer value of this object's value at the current index in 
        values[1], it will do the same with the other object and store it in values[2].
        It will then store their sum in values[0]. The number of multiples of 16 within this sum is found,
        this will be added to the sum of the values at the next power. These multiples of 16 are then taken out
        of values[0]. The value of this object at the current index is then set to values[0] as a character.
        Then values[0] is set to the next power's value for the next iteration. On the next iteration, the 
        values of values[1] and values[2] will be added to this value.
    */
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
        if(i >= thisSize+thisSizeGrowth){ // Checks if i is on the left-most character of the string
            if((i < otherSize) || (values[0] > 0)){ // If the other object is longer, or if there is a value for the next power
                value = validCharacters[0] + value; // Add a zero character before the rest of value
                thisSizeGrowth++; // Reflect the increase in size
            }
        }

    }

    delete [] values;
    return this;
}

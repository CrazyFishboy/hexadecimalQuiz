#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>

class Hexadecimal{
public:
static const int base;
static const char validCharacters[];
static bool isValidCharacter(char character);
Hexadecimal() : Hexadecimal("0x0"){}
Hexadecimal(std::string val){
    this->value = val;
}

std::string getValue() const{
    return value;
}

// Should make this return bool, for whether it was successful or not
bool setValue(std::string val);

protected:
std::string value;

};
#endif
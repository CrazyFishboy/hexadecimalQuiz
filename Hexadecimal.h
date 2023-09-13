#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include <string>

class Hexadecimal{

public:
Hexadecimal() : Hexadecimal("0x0"){}
Hexadecimal(std::string val){
    this->value = val;
}

std::string getValue() const{
    return value;
}

// Should make this return bool, for whether it was successful or not
void setValue(std::string val) {
    this->value = val;
}

protected:
std::string value;

};
#endif
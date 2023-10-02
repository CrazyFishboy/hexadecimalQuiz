#ifndef BINARY_H
#define BINARY_H

#include "Hexadecimal.h"
#include <string>


class Binary {

public:
    
    Binary() : Binary("0") {}
    Binary(std::string str);


    std::string getValue() const {
        return value;
    }
    bool setValue(std::string str);
    bool makeBytes();


private:
    std::string value;



};



#endif
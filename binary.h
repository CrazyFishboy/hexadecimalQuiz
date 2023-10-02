#ifndef BINARY_H
#define BINARY_H

#include "Hexadecimal.h"
#include <string>


class Binary {

public:
    
    Binary() : Binary("0") {}
    Binary(std::string);


    std::string getValue() const {
        return value;
    }


private:
    std::string value;



};



#endif
#ifndef BINARY_H
#define BINARY_H

#include "Hexadecimal.h"
#include <string>
#include <cmath>


class Binary {

public:
    
    Binary() : Binary("0") {}
    Binary(std::string str);
    Binary(int num);


    std::string getValue() const {
        return value;
    }
    bool setValue(std::string str);
    bool setValue(int num);
    bool makeBytes();

    void addValue(int num);
    


private:
    std::string value;



};



#endif
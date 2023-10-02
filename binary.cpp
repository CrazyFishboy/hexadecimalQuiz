#include "binary.h"


Binary::Binary(std::string str){
    if(!setValue(str)){
        this->value = "0";
    }
}

Binary::Binary(int num){
    if(!setValue(num)){
        this->value = "0";
    }
}


bool Binary::setValue(std::string str){
    if(str.size() > 0){
        for(unsigned i = 0; i < str.size(); ++i){
            if(str[i] != '0' && str[i] != '1'){
                return false;
            }
        }
        this->value = str;
        return true;
    } else {
        return false;
    }
}

bool Binary::setValue(int num){
    if(num >= 0){
        std::string temp = "";
        int power = -1;
        do {
            ++power;
        } while (std::pow(2,power+1) <= num);
        do {
            if(std::pow(2,power) <= num){
                temp += "1";
                num -= std::pow(2,power);
            } else {
                temp += "0";
            }
            --power;
        } while(power >= 0);
        value = temp;
        return true;
    } else {
        return false;
    }
}

bool Binary::makeBytes(){
    while(value.size() % 8 != 0){
        value = "0" + value;
    }
    return true;
}
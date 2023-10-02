#include "binary.h"


Binary::Binary(std::string str){
    if(!setValue(str)){
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

bool Binary::makeBytes(){
    while(value.size() % 8 != 0){
        value = "0" + value;
    }
    return true;
}
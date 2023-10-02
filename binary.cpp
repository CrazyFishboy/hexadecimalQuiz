#include "binary.h"


Binary::Binary(std::string str){
    if(str.size() > 0){
        bool valid = true;
        for(unsigned i = 0; i < str.size(); ++i){
            if(str[i] != '0' && str[i] != '1'){
                valid = false;
            }
        }
        if(valid){
            this->value = str;
        } else {
            this->value = "0";
        }
    } else {
        this->value = "0";
    }
}
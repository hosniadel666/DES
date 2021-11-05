#include <iostream>
#include "../include/des.h"

asu::des::des(std::string key){
    asu::des::key = key;
}
asu::des::des(){
    asu::des::key = "123"; // Defult key
}

std::string asu::des::encrypt(std::string data){
    
    return "encrypted " + data +" with " + asu::des::key;
}

std::string asu::des::decrypt(std::string data){
    return "decrypted "+ data +" with " + asu::des::key;
}

#include <iostream>
#include <string>
#include "./include/des.h"

enum ARGUMENT
{
    FUNC = 1,
    DATA,
    KEY
};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "./des.out: missing operand\n";
        std::cout << "Usage: des [OPTION] [DATA] [KEY]\n";
        std::cout << "[OPTION] - encrypt or decrypt\n";
        return 0;
    }

    std::string func = argv[FUNC];
    std::string data = argv[DATA];
    std::string key = argv[KEY];

    asu::des d1(key);

    if (func == "encrypt")
        std::cout << "cipher:\t" << d1.encrypt(data) << std::endl;
    else if (func == "decrypt")
        std::cout << "plain:\t" << d1.decrypt(data) << std::endl;
    else
        std::cout << "Usage: des [OPTION] [DATA] [KEY]\n[OPTION] --> encrypt or decrypt\n";
        
    return 0;
}





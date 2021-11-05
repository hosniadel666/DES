#ifndef __des_H__
#define __des_H__

#include <iostream>

namespace asu{

    class des{
        private:
            std::string key;
        public:
            des();
            des(std::string key);
            std::string encrypt(std::string data);
            std::string decrypt(std::string data);
    };
}

#endif
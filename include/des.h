#ifndef __des_H__
#define __des_H__

#include <iostream>
#include <vector>

namespace asu{
    class des{
        private:
            std::string key_hex, key_bin;
            std::vector<std::string> roundkeys_bin; // rkb for RoundKeys in binary
	        std::vector<std::string> roundkeys_hex; // rk for RoundKeys in hexadecimal
        public:
            des();
            des(std::string key);
            std::string encrypt(std::string data);
            std::string decrypt(std::string data);
    };
}

#endif
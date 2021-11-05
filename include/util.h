#ifndef __UTIL_H__
#define __UTIL_H__

namespace asu
{
    class util{
        public:
            util();
            std::string convert_h2b(std::string s);
            std::string convert_b2h(std::string s);
            std::string permute(std::string k, int* arr, int n);
            std::string shift_left(std::string k, int shifts);
            std::string xoring(std::string a, std::string b);

    };
}


#endif
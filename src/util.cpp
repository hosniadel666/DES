#include <iostream>
#include <map>
#include "../include/util.h"

asu::util::util() {}
// hexadecimal to binary conversion
std::string asu::util::convert_h2b(std::string s)
{
    std::string binary_num = "";
    std::map<char, std::string> mp;
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['A'] = "1010";
    mp['B'] = "1011";
    mp['C'] = "1100";
    mp['D'] = "1101";
    mp['E'] = "1110";
    mp['F'] = "1111";

    for (int i = 0; i < s.size(); i++)
        binary_num += mp[s[i]];

    return binary_num;
}

// binary to hexadecimal conversion
std::string asu::util::convert_b2h(std::string s)
{
    std::string hex_num = "";
    std::map<std::string, std::string> mp;
    mp["0000"] = "0";
    mp["0001"] = "1";
    mp["0010"] = "2";
    mp["0011"] = "3";
    mp["0100"] = "4";
    mp["0101"] = "5";
    mp["0110"] = "6";
    mp["0111"] = "7";
    mp["1000"] = "8";
    mp["1001"] = "9";
    mp["1010"] = "A";
    mp["1011"] = "B";
    mp["1100"] = "C";
    mp["1101"] = "D";
    mp["1110"] = "E";
    mp["1111"] = "F";

    // Each 4 bit of binary number represent one digit of hex number
    for (int i = 0; i < s.length(); i += 4)
    {
        std::string ch = "";
        ch += s[i];
        ch += s[i + 1];
        ch += s[i + 2];
        ch += s[i + 3];
        hex_num += mp[ch];
    }
    return hex_num;
}

std::string asu::util::shift_left(std::string k, int shifts)
{
    std::string s = "";
    for (int i = 0; i < shifts; i++)
    {
        for (int j = 1; j < 28; j++)
        {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}

std::string asu::util::xoring(std::string a, std::string b)
{
    std::string ans = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans += "0";
        }
        else {
            ans += "1";
        }
    }
    return ans;
}

std::string asu::util::permute(std::string k, int* arr, int n)
{
    std::string per = "";
    for (int i = 0; i < n; i++) {
        per += k[arr[i] - 1];
    }
    return per;
}
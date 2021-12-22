#include <iostream>
#include <map>
#include "../include/util.h"

asu::util::util()
{
}

std::string asu::util::to_upper(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - 32;
  }
}

uint64_t asu::util::str_to_u64(std::string data)
{
  uint64_t value = 0;
  for (int i = 0; i < 16; ++i)
  {
    char c = data[i];
    if (c >= '0' && c <= '9')
      value |= (uint64_t)(c - '0') << ((15 - i) << 2);
    else if (c >= 'A' && c <= 'F')
      value |= (uint64_t)(c - 'A' + 10) << ((15 - i) << 2);
    else if (c >= 'a' && c <= 'f')
      value |= (uint64_t)(c - 'a' + 10) << ((15 - i) << 2);
  }
  return value;
}

std::string asu::util::u64_to_str(uint64_t value)
{
  char buffer[200];
  sprintf(buffer, "%016llx", value);
  for (int i = 0; buffer[i] != '\0'; i++)
  {
    if (buffer[i] >= 'a' && buffer[i] <= 'z')
      buffer[i] = buffer[i] - 32;
  }

  return buffer;
}
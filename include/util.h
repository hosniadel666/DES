#ifndef __UTIL_H__
#define __UTIL_H__

namespace asu
{
class util
{
public:
  util();
  std::string to_upper(std::string str);
  uint64_t str_to_u64(std::string data);
  std::string u64_to_str(uint64_t data);
};
}

#endif
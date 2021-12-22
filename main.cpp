#include <iostream>

#include "util.h"
#include "des.h"

#ifdef __GNUC__
#define __rdtsc __builtin_ia32_rdtsc
#else
#include <intrin.h>
#endif

enum ARGUMENT
{
  FUNC = 1,
  DATA,
  KEY
};

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "./des.out: missing operand\n";
    std::cout << "Usage: des [OPTION] [DATA] [KEY]\n";
    std::cout << "[OPTION] - encrypt or decrypt\n";
    return 0;
  }
  asu::util u;
  std::string func = argv[FUNC];
  uint64_t data = u.str_to_u64(argv[DATA]);
  uint64_t key = u.str_to_u64(argv[KEY]);

  asu::des d1(key);
  std::string result;

  long long t1, t2;
  if (func == "encrypt")
  {
    t1 = __rdtsc();
    result = u.u64_to_str(d1.encrypt(data));
    t2 = __rdtsc();
    std::cout << "Cipher: " << result << std::endl;
  }
  else if (func == "decrypt")
  {
    t1 = __rdtsc();
    result = u.u64_to_str(d1.decrypt(data));
    t2 = __rdtsc();
    std::cout << "Plain: " << result << std::endl;
  }
  else
    std::cout << "Usage: des [OPTION] [DATA] [KEY]\n[OPTION] --> encrypt or decrypt\n";

  std::cout << "Cycles: " << t2 - t1 << std::endl;

  return 0;
}

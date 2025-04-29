#include "TestWrapper.h"
#include <cstdint>

static bool mycustomcompare(const char *a,
                            size_t alen,
                            const char *b,
                            size_t blen) {
  if (alen != blen)
    return 0;
  int result = 1;
  for (size_t i = 0; i < alen; i++) {
    result &= (*a == *b);
    a++;
    b++;
  }
  return result;
}

void HandleInput(std::string input) {
  std::string needle(std::getenv("NEEDLE"));

  if (mycustomcompare(input.c_str(), input.size(),
                      needle.c_str(),
                      needle.size()))
    trigger_bug();
}
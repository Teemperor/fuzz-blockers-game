#include "TestWrapper.h"
#include <cstdint>

static bool mycustomcompare(const char *a,
                            size_t alen,
                            const char *b,
                            size_t blen) {
  if (alen != blen)
    return false;
  for (size_t i = 0; i < alen; i++)
    if (*a++ != *b++)
      return false;
  return true;
}

void HandleInput(std::string input) {
  std::string needle(std::getenv("NEEDLE"));
  if (mycustomcompare(input.c_str(), input.size(),
                      needle.c_str(),
                      needle.size()))
    trigger_bug();
}
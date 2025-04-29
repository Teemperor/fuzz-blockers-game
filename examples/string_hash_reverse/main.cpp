#include "TestWrapper.h"
#include <cstdint>

#include <cstring>

void HandleInput(std::string input) {
  if (std::hash<std::string>{}(input) ==
      0xec246a11c2970beaULL)
    abort();
}
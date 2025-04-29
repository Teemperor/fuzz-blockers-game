#include "TestWrapper.h"
#include <cstdint>

#include <cstring>

void HandleInput(std::string input) {
  if (strcmp(input.c_str(), "somelonginput\n") ==
      0)
    trigger_bug();
}
#include "TestWrapper.h"
#include <cstdint>

#include <cstring>

void HandleInput(std::string input) {
  if (strcmp(input.c_str(),
             std::getenv("NEEDLE")) == 0)
    trigger_bug();
}
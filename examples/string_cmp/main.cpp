#include "TestWrapper.h"
#include <cstdint>

void HandleInput(std::string input) {
  if (input == std::getenv("NEEDLE"))
    abort();
}
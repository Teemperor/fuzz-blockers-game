#include "TestWrapper.h"
#include <cstdint>
#include <cstring>

void HandleInput(std::string input) {
  std::string needle = std::getenv("NEEDLE");

  if (std::hash<std::string>{}(input) ==
      std::hash<std::string>{}(needle))
    trigger_bug();
}
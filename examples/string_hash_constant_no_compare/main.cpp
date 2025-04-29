#include "TestWrapper.h"
#include <cstdint>

#include <cstring>

void HandleInput(std::string input) {
  if (std::hash<std::string>{}(input) ==
      std::hash<std::string>{}(
          "somelonginput\n")) {
    trigger_bug();
  }
}
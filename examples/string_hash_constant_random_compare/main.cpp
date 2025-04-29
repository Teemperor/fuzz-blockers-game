#include "TestWrapper.h"
#include <cstdint>

#include <cstring>

const char *banana = "This is really dumb?";

void HandleInput(std::string input) {

  if (std::hash<std::string>{}(input) ==
      std::hash<std::string>{}(
          "somelonginput\n")) {
    if (strcmp(banana, "somelonginput\n") == 0)
      return;
    trigger_bug();
  }
}
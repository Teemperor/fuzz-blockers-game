#include "TestWrapper.h"
#include <cstdint>

#include <unordered_map>

std::unordered_map<std::string, std::string>
    lookup;
void HandleInput(std::string input) {
  lookup["somelonginput\n"] = "needle";

  if (lookup[input] == "needle")
    trigger_bug();
}
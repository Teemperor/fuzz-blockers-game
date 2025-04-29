#include "TestWrapper.h"
#include <cstdint>

#include <unordered_map>

std::unordered_map<std::string, std::string> lookup;
void HandleInput(std::string input) {
  lookup[std::getenv("NEEDLE")] = "needle";

  if (lookup[input] == "needle")
    abort();
}
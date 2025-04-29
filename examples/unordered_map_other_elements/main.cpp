#include "TestWrapper.h"
#include <cstdint>

#include <unordered_map>

std::unordered_map<std::string, std::string> lookup;
void HandleInput(std::string input) {
  lookup[std::getenv("NEEDLE")] = "needle";
  for (int i = 0; i < 1000; i += 1)
    lookup[std::to_string(i)] = "x";

  if (lookup[input] == "needle")
    abort();
}
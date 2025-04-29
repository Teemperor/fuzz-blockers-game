#include "TestWrapper.h"
#include <cstdint>

#include <unordered_set>

std::unordered_set<std::string> lookup = {
    std::getenv("NEEDLE")};
void HandleInput(std::string input) {
  if (lookup.count(input))
    trigger_bug();
}
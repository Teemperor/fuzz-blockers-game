#include "TestWrapper.h"
#include <cstdint>

#include <set>

std::set<std::string> lookup = {
    std::getenv("NEEDLE")};
void HandleInput(std::string input) {
  if (lookup.count(input))
    trigger_bug();
}
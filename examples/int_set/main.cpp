#include "TestWrapper.h"
#include <cstdint>

#include <iomanip>
#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>

std::set<int> lookup = {1234};

void HandleInput(std::string input) {
  if (lookup.count(std::stoi(input)))
    trigger_bug();
}
#include "TestWrapper.h"
#include <cstdint>

#include <iomanip>
#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>

void HandleInput(std::string input) {
  if (std::stoi(input) == 1234)
    trigger_bug();
}
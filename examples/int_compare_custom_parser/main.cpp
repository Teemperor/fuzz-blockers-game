#include "TestWrapper.h"
#include <cstdint>

#include <iomanip>
#include <iostream>
#include <set>
#include <stdexcept>
#include <utility>

unsigned mystoi(std::string input) {
  unsigned result = 0;
  for (char c : input) {
    if (c >= '0' && c <= '9') {
      result *= 10;
      result += (unsigned)(c - '0');
    } else
      return result;
  }
  return result;
}

void HandleInput(std::string input) {
  if (std::stoi(input) == 1234)
    abort();
}
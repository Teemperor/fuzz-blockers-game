#include "TestWrapper.h"
#include <cstdint>

#include <vector>

void HandleInput(std::string input) {
  std::vector<char> inputList(input.rbegin(),
                              input.rend());

  std::vector<char> needleList;
  for (char *x = std::getenv("NEEDLE"); *x; x++)
    needleList.push_back(*x);

  if (inputList == needleList)
    trigger_bug();
}
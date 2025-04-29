#include "TestWrapper.h"
#include <cstdint>

#include <list>

void HandleInput(std::string input) {
  std::list<char> inputList(input.begin(),
                            input.end());

  std::list<char> needleList;
  for (char *x = std::getenv("NEEDLE"); *x; x++)
    needleList.push_front(*x);

  if (inputList == needleList)
    abort();
}
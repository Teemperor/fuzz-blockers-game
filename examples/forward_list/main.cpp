#include "TestWrapper.h"
#include <forward_list>
#include <list>

void HandleInput(std::string input) {
  std::forward_list<char> inputList(input.begin(),
                                    input.end());

  std::list<char> needleList;
  for (char *x = std::getenv("NEEDLE"); *x; x++)
    needleList.push_back(*x);
  std::forward_list<char> needleListForward(
      needleList.begin(), needleList.end());

  if (inputList == needleListForward)
    abort();
}
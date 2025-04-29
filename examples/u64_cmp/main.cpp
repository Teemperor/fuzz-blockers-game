#include "TestWrapper.h"

void HandleInput(std::string input) {
  if (inputToI64(input) == 0x5A5A55465A5A5546ULL)
    trigger_bug();
}
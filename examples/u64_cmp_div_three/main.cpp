#include "TestWrapper.h"

volatile uint64_t three = 3;
void HandleInput(std::string input) {
  if ((inputToI64(input) / three) ==
      (0x5A5A55465A5A5546ULL / 3ULL))
    trigger_bug();
}
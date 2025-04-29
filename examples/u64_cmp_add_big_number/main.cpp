#include "TestWrapper.h"

volatile uint64_t number = 0x1234;

void HandleInput(std::string input) {
  if ((inputToI64(input) + number) ==
      (0x5A5A55465A5A5546ULL + 0x1234ULL))
    trigger_bug();
}
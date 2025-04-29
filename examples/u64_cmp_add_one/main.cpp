#include "TestWrapper.h"

volatile uint64_t one = 1;
void HandleInput(std::string input) {
  if ((inputToI64(input) + one) ==
      (0x5A5A55465A5A5546ULL + 1ULL))
    abort();
}
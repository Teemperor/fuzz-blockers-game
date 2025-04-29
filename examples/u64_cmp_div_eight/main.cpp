#include "TestWrapper.h"

volatile uint64_t eight = 8;
void HandleInput(std::string input) {
  if ((inputToI64(input) / eight) ==
      (0x5A5A55465A5A5546ULL / 8ULL))
    abort();
}
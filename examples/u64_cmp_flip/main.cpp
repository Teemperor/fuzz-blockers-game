#include "TestWrapper.h"

volatile uint64_t allOnes = 0xFFFFFFFFFFFFFFFFULL;

void HandleInput(std::string input) {
  if ((inputToI64(input) ^ allOnes) ==
      (0x5A5A55465A5A5546ULL ^
       0xFFFFFFFFFFFFFFFFULL))
    abort();
}
#include "TestWrapper.h"

void HandleInput(std::string input) {
  uint64_t i = inputToI64(input);
  if (i > 20394)
    if (i % 4242 == 0)
      if (i & 0xff0f0f0 != 0)
        abort();
}
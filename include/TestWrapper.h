#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void HandleInput(std::string input);

union Reinterpret64 {
  uint64_t asInt;
  char chars[sizeof(uint64_t)];
};

uint64_t inputToI64(std::string input) {
  if (input.size() < 8)
    return 0;
  Reinterpret64 re;
  std::memcpy(re.chars, input.c_str(),
              sizeof(re));
  return re.asInt;
}

void trigger_bug() {
  // Our test script checks this to make sure we found the specific bug and
  // not some unrelated crash.
  std::cerr << "BUG_TRIGGERED\n";
  abort();
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    std::string input(reinterpret_cast<const char *>(Data), Size);
    try {
        HandleInput(input);
    } catch (...) {
        // Prevent unrelated crashes leading to FP detection.
        printf("Caught random exception.");
    }
    return 0;
}
#include "TestWrapper.h"
#include <cstdint>
#include <list>

void HandleInput(std::string input) {
  unsigned idx = 0;
  if (input.at(idx++) == 'f')
    if (input.at(idx++) == 'u')
      if (input.at(idx++) == 'z')
        if (input.at(idx++) == 'z')
          if (input.at(idx++) == 'f')
            if (input.at(idx++) == 'u')
              if (input.at(idx++) == 'z')
                if (input.at(idx++) == 'z')
                  trigger_bug();
}
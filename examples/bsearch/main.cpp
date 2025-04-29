#include "TestWrapper.h"
#include <cstdint>

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct data {
  char const *key;
  int value;
};
int data_cmp(void const *lhs, void const *rhs) {
  struct data const *const l =
      (struct data const *)lhs;
  struct data const *const r =
      (struct data const *)rhs;
  return strcmp(l->key, r->key);
}
// clang-format off
struct data dat[] = {{"akey\n", 1},
  {"bsomeotherlonginput\n", 2}, {"c1nothe", 3},
  {"d9notherkey", 3}, {getenv("NEEDLE"), 5},
  {"tc1notherkey", 3}, {"td9notherkey", 3}};
// clang-format on
void HandleInput(std::string input) {

  struct data key = {.key = input.c_str()};
  struct data const *res;
  res = (struct data const *)bsearch(
      &key, dat, sizeof dat / sizeof dat[0],
      sizeof dat[0], data_cmp);
  if (res && res->value == 5)
    trigger_bug();
}

#include <iostream>

int main ( [[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  char const * a = "aaaa";
  const char * b = "bbb";
  char * const c = new char[5];
  c[0] = 'a';
  c = new char[10];
  char const * const d = "cvvv";
  return 0;
}

#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_set>
#include <utility>

#include <fmt/core.h>
#include <fmt/ranges.h>

template<class T> void test_func( [[maybe_unused]] T val ) {
  static int stat_val = 0;
  std::cout <<  fmt::format("stat_val = {}", ++stat_val ) << std::endl;;
}

int main( [[maybe_unused]] int argc, [[maybe_unused]] char* argv[] ) {

  test_func(1);
  test_func(2);
  test_func(3.0);
  test_func(3);
  test_func('a');
  return EXIT_FAILURE;
};

#include <stdlib.h>

#include <iostream>

#include <fmt/core.h>

int main( [[maybe_unused]] int argc, char* argv[] ) {
  for ( auto i = 0; i <= 16; ++i ) {
    auto num = 1 << i;
    std::cout << fmt::format("number = {0:>10x}\t{0:>20b}\t{0:>20o}\t{0:>20d}", num, num, num, num) << std::endl;
  }
  for ( auto i = 0; i <= 10; ++i ) {
    auto num = i*16;
    std::cout << fmt::format("number = {0:>10x}\t{0:>20b}\t{0:>20o}\t{0:>20d}", num, num, num, num) << std::endl;
  }
  return EXIT_SUCCESS;
}

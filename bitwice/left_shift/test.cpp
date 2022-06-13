#include <stdlib.h>

#include <iostream>

#include <fmt/core.h>

int main( [[maybe_unused]] int argc, [[maybe_unused]] char* argv[] ) {
  int a = 1000 << 1;
  int b = 1000 << 2;
  auto&& c = 1000 << 3;
  std::cout << fmt::format("shifted by 1 a = {}", a ) << std::endl;
  std::cout << fmt::format("shifted by 2 b = {}", b ) << std::endl;
  std::cout << fmt::format("shifted by 3 c = {}", c ) << std::endl;

  int d = 1000 >> 1;
  int e = 1000 >> 2;
  auto&& f = 1000 >> 3;
  std::cout << fmt::format("shifted by 1 d = {}", d ) << std::endl;
  std::cout << fmt::format("shifted by 2 e = {}", e ) << std::endl;
  std::cout << fmt::format("shifted by 3 f = {}", f ) << std::endl;
  return EXIT_SUCCESS;
}

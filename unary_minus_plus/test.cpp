#include <iostream>

#include <typeinfo>

#include <stdlib.h>

#include <fmt/core.h>

#define varname(v) #v 

auto ret_test() {
  return 2+3;
}

int main( [[maybe_unused]] int argc, [[maybe_unused]]char* argv[] ) {
  int a = -2;
  double b = 3.2;
  auto&& d = 4 + 5;
  int test = ret_test();


  std::cout << fmt::format("+a = {} -b = {}, a+b = {} rvaluelink = {}  {} {} {}", +a, -b, a + b, d++, d, (void*)&d, test ) << std::endl;
  return EXIT_SUCCESS;
}

#include <stdlib.h>

#include <new>
#include <climits>
#include <iostream>

#include <fmt/format.h>
#include <fmt/ranges.h>

int main() {
  int n = -1;
  try {
    int* a = new int[n];
    std::cout << fmt::format("a = {}", a[0] ) << std::endl;
  }
  catch( const std::bad_array_new_length& e ) {
    std::cout << fmt::format("bad array new length = {}", e.what() ) << std::endl;
  }


  return EXIT_SUCCESS;
};

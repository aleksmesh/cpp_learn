#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_set>
#include <utility>

#include <fmt/core.h>
#include <fmt/ranges.h>

int main( int argc, char* argv[] ) {
  if ( 2 > argc ) {
    std::cout << "Enter int-sequence separated by commas" << std::endl;
    return EXIT_FAILURE;
  }
  std::string seqstr(argv[1]);

  int counter[255]{};

  for ( auto c : seqstr ) {
    ++counter[static_cast<int>(c)];
  }
  int pos = 0;
  for ( auto c : seqstr ) {
    if ( 1 == counter[static_cast<int>(c)] ) {
      std::cout << fmt::format("first uniq char position = {}", pos ) << std::endl;
      return EXIT_SUCCESS;
    }
    ++pos;
  }

  std::cout << "not found uniq symbol!" << std::endl;
  return EXIT_FAILURE;
};

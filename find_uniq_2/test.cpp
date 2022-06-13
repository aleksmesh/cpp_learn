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

  std::unordered_set<char> checked_symbols;

  int counter = 1;
  for ( auto c : seqstr ) {
    if ( checked_symbols.end() != checked_symbols.find(c) ) {
      ++counter;
      continue;
    }
    size_t pos = seqstr.find( c, counter );
    if ( std::string::npos == pos ) {
      std::cout << fmt::format("find uniq symbol at pos = {}. The symbol is {}", counter - 1, seqstr[counter-1] ) << std::endl;
      return EXIT_SUCCESS;
    }
    else {
      checked_symbols.insert(c);
    }
    ++counter;
  }

  std::cout << "not found uniq symbol!" << std::endl;
  return EXIT_FAILURE;
};

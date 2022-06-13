#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_set>
#include <utility>

#include <fmt/core.h>
#include <fmt/ranges.h>

int find_next( const std::string& str, char symbol, size_t num ) {
  if ( num >= str.size() ) {
    return -1;
  }
  for ( size_t i = num; i < str.size(); ++i ) {
    char c = str[i];
    if ( c == symbol ) {
      return num;
    }
  }
  return -1;
}

int main( int argc, char* argv[] ) {
  if ( 2 > argc ) {
    std::cout << "Enter int-sequence separated by commas" << std::endl;
    return EXIT_FAILURE;
  }
  std::string seqstr(argv[1]);
  std::unordered_set<char> repetitions;
  for ( size_t i = 0; i < seqstr.size(); ++i ) {
    char c = seqstr[i];
    if ( repetitions.end() != repetitions.find(c) ) {
      continue;
    }
    if ( -1 == find_next(seqstr, c, i + 1 ) ) {
      std::cout << fmt::format("uniq symbol = {}. index of symbol = {}", seqstr[i], i) << std::endl;
      return i;
    }
    repetitions.insert(c);
  }
  std::cout << "not found uniq symbol!" << std::endl;
  return EXIT_FAILURE;
};

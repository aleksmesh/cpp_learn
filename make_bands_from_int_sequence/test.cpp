#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <utility>

#include <fmt/core.h>
#include <fmt/ranges.h>

int main( int argc, char* argv[] ) {
  if ( 2 > argc ) {
    std::cout << "Enter int-sequence separated by commas" << std::endl;
    return EXIT_FAILURE;
  }
  std::string seqstr(argv[1]);
  std::cout << "seqstr = " << seqstr << std::endl;
  std::cout << "size of seqstr =" << seqstr.size() << std::endl;
  std::cout << "last symbol = " << seqstr[seqstr.size()] << std::endl;

  std::cout << fmt::format("symbol num = {:d}", seqstr[seqstr.size()]) << std::endl;

  std::list<int> numlist;

  std::istringstream input(seqstr);

  for ( std::string substr; std::getline( input, substr, ',' ); ) {
    numlist.push_back( std::stoi(substr) );
  }
  if ( 0 == numlist.size() ) {
    std::cout << "please, enter values" << std::endl;
    return EXIT_FAILURE;
  }
  if ( 1 == numlist.size() ) {
    std::cout << fmt::format("sequences = {}", seqstr) << std::endl;
    return EXIT_SUCCESS;
  }

  std::cout << fmt::format("list = {}", numlist) << std::endl;
  numlist.sort();

  std::list<std::string> ranges;

  std::list<int>::iterator fit = numlist.begin(), end = numlist.end();
  std::list<int>::iterator sit = ++numlist.begin();

  while ( fit != end ) {
    int first = *fit;
    int last = first;
     while ( sit != end ) {
      int second = *sit;
      std::cout << "first =" << first << std::endl;
      if ( second > last + 1 ) {
        if ( first == last ) {
          ranges.push_back( std::to_string(first) );
        }
        else {
          ranges.push_back( fmt::format("{} - {}", first, last) );
        }
        fit = sit;
        ++sit;
        if ( sit == end ) {
          ranges.push_back( std::to_string(second) );
        }
        break;
      }
      last = second;
      fit = sit;
      ++sit;
      if ( sit == end ) {
        if ( first == last ) {
          ranges.push_back( std::to_string(first) );
        }
        else {
          ranges.push_back( fmt::format("{} - {}", first, last) );
        }
      }
    }
    if ( sit == end ) {
      break;
    }
  }
  std::cout << fmt::format("ranges = {}", ranges) << std::endl;

//  [[maybe_unused]] std::pair< int, int > last_pair = std::make_pair( *it, ++(*it) );



  return EXIT_SUCCESS;
};

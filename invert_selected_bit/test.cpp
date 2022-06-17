#include <stdlib.h>

#include <string>
#include <iostream>
#include <stdexcept>

#include <fmt/core.h>

bool invert_bit( [[maybe_unused]] void* array, unsigned bitnum ) {
  if ( 7 < bitnum ) {
    std::cout << fmt::format("wrong bit number = {}", bitnum ) << std::endl;
    return false;
  }
  unsigned char* charr = reinterpret_cast<unsigned char*>(array);
  unsigned mask = 1 << bitnum;
  *charr = *charr ^ mask;

  return true;
}

bool convert_str_to_int( const std::string& str, int* number ) {
  if ( nullptr == number ) {
    std::cout << "nullptr as input parameter" << std::endl;
    return false;
  }
  try {
    *number = std::stoi(str);
  }
  catch ( const std::invalid_argument& ex ) {
    std::cout << fmt::format("Invalid arg for number = {}, ex = {}", str, ex.what() ) << std::endl;
    return false;
  }
  catch ( const std::out_of_range& ex ) {
    std::cout << fmt::format("Out of range for number = {}, ex = {}", str, ex.what() ) << std::endl;
    return false;
  }

  return true;
}

int main( int argc, char* argv[] ) {
  if ( 3 > argc ) {
    std::cout << "Enter digit and bit number please" << std::endl;
    return EXIT_FAILURE;
  }

  std::string strnumber{argv[1]};
  int number = 0;
  if ( false == convert_str_to_int( strnumber, &number ) ) {
    std::cout << fmt::format("wrong symbols for number = {}", strnumber ) << std::endl;
    return EXIT_FAILURE;
  }
  std::string strbitnumber{argv[2]};
  int bitnumber = 0;
  if ( false == convert_str_to_int( strbitnumber, &bitnumber ) ) {
    std::cout << fmt::format("wrong symbols for bitnumber = {}", strbitnumber ) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << fmt::format( "input number = {0:>5d} {0:0>8b}", number, number ) << std::endl;


  bool res = invert_bit( reinterpret_cast<void*>(&number), bitnumber );
  std::cout << fmt::format("resul number = {0:>5d} {0:0>8b}", number, number ) << std::endl;

  return EXIT_SUCCESS;
}

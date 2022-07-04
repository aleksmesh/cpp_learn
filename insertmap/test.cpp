#include <stdlib.h>

#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <qvector.h>
#include <qset.h>

int main( [[maybe_unused]]int argc, [[maybe_unused]] char* argv[] )
{
  std::map<int, std::string> insmap;
  insmap.insert( {1, "12"} );
  insmap.insert( {1, "14"} );
  std::cout << fmt::format( "insmap = {}", insmap ) << std::endl;
  insmap.insert_or_assign( 1, "14" );
  insmap.insert_or_assign( 3, "18" );
  insmap.insert_or_assign( 2, "18" );
  std::cout << fmt::format( "insmap = {}", insmap ) << std::endl;

  std::unordered_map<int, std::string> inshash;
  inshash.insert( {1, "12"} );
  inshash.insert( {1, "14"} );
  std::cout << fmt::format( "inshash = {}", inshash ) << std::endl;
  inshash.insert_or_assign( 1, "14" );
  inshash.insert_or_assign( 3, "18" );
  inshash.insert_or_assign( 2, "18" );
  std::cout << fmt::format( "inshash = {}", inshash ) << std::endl;

  QVector<int> qvec{ 1, 2, 3, 4, 4, 5 };
  QSet<int> qset( qvec.begin(), qvec.end() );

  std::cout << fmt::format( "qvec = {}", qvec ) << std::endl;
  std::cout << fmt::format( "qset = {}", qset ) << std::endl;

  return EXIT_SUCCESS;
}

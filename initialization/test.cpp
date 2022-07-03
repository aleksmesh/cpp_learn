#include <stdlib.h>

#include <iostream>
#include <string>

#include <fmt/format.h>
#include <fmt/ranges.h>

class tmp {
  public:
    int a;
    bool b;
    float c;
    char d;

    std::string to_string() const {
      return fmt::format( "a = {}, b = {}, c = {}, d = {}", a, b ,c ,d );
    }

//  private:
//    char g;
};

static int gla[255];
int glb[255];

int main( [[maybe_unused]]int argc, [[maybe_unused]]char* argv[] ) {
  int a[255];
  int b[255]{};
  int c[255]{0};
  int d[255] = {};
  int e[255] = {0};

  std::cout << fmt::format("a = {}", a ) << std::endl;
  std::cout << fmt::format("b = {}", b ) << std::endl;
  std::cout << fmt::format("c = {}", c ) << std::endl;
  std::cout << fmt::format("d = {}", d ) << std::endl;
  std::cout << fmt::format("e = {}", e ) << std::endl;
  std::cout << fmt::format("gla = {}", gla ) << std::endl;
  std::cout << fmt::format("glb = {}", glb ) << std::endl;

  tmp s = { 1, false, 3, 'a' };

  std::cout << "s = " << s.to_string() << std::endl;

  return EXIT_SUCCESS;
};

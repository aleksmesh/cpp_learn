#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <list>

class MoveTest {
  public:
    MoveTest( const MoveTest& mc ) : array_(new char[20]) {
      std::cout << "copy constr" << std::endl;
    }
    MoveTest() : array_(new char[20]) {
      std::cout << "def constr" << std::endl;
    }
    MoveTest( MoveTest&& mc ) {
      std::cout << "move constr" << std::endl;
      array_ = mc.array_;
      mc.array_ = nullptr;
    }

    ~MoveTest() {
      std::cout << "del" << std::endl;
      delete[] array_;
    }

    MoveTest& operator=( MoveTest&& mc ) {
      std::cout << "rass!" << std::endl;
      delete[] array_;
      array_ = mc.array_;
      mc.array_ = nullptr;
      return *this;
    }

    MoveTest& operator=( const MoveTest& mc ) {
      std::cout << "lass!" << std::endl;
      ::memset( array_, 0, 20 );
      ::memcpy( array_, mc.array_, 20 );
      return *this;
    }

  private:
    char* array_ = nullptr;
};

MoveTest get_obj() {
  MoveTest m;
  return m;
};

int main( [[maybe_unused]] int argc, [[maybe_unused]] char* argv[] ) {
//  MoveTest m = get_obj();
  MoveTest a;
  a = get_obj();
//  MoveTest b(get_obj());

  std::list<MoveTest> mvec;
  mvec.push_back( get_obj() );
  mvec.push_back( get_obj() );
  mvec.push_back( get_obj() );
  mvec.push_back( get_obj() );

  return EXIT_SUCCESS;
}

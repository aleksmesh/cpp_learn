#include <iostream>

#include <fmt/core.h>

using namespace std;
class A {
  public:
    A () {
      cout << "A::A()" << endl;
      foo (1);
    }
    ~A () {
      cout << "A::~A()" << endl;
      foo (1);
    }
    virtual void foo (int arg = 13) {
      cout << "A::foo(" << arg << ")" << endl;
    }
};

class B : public A {
  public:
    B () {
      cout << "B::B()" << endl;
      foo (2);
      values_ = new int[42];
    }
    ~B () {
      cout << "B::~B()" << endl;
      foo (2);
      delete[] values_;
    }
    virtual void foo (int arg = 42) {
      cout << "B::foo(" << arg << ")" << endl;
    }
  private:
    int *values_;
};

int main ( [[maybe_unused]]int argc, [[maybe_unused]]char *argv[]) {
  A *a = new B ();
  B *b = new B ();
  a->foo ();
  b->foo ();
  delete a;
  delete b;

  std::cout << fmt::format("input vals = {:x} & {:x} or {:b} & {:b}", 0x53, 0x71, 0x53, 0x71 ) << std::endl;

  unsigned res = 0x53 & 0x71;

  std::cout << fmt::format("result = {:d} {:x} {:b}", res, res, res ) << std::endl;

  return 0;
}
/*
A::A()
A::foo(1)
B::B()
A::foo(2)
A::A()
A::foo(1)
B::B()
A::foo(2)
B::foo(13)
B::foo(42)
A::~A()
A::foo(1)
B::~B()
B::foo(2)
A::~A()
A::foo(1)
 * */

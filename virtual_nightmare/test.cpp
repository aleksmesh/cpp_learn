
#include <iostream>
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

int main (int argc, char *argv[]) {
  A *a = new B ();
  B *b = new B ();
  a->foo ();
  b->foo ();
  delete a;
  delete b;
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

#include <stdlib.h>
#include <string.h>

#include <utility>
#include <iostream>
#include <vector>
#include <list>

#include <fmt/core.h>

template<class T> class Array  {
  public:
    Array( const Array& copy [[maybe_unused]] ) {
      std::cout << "copy constructor" << std::endl;
    }
    Array( size_t arrsize ) : array_{ new T[arrsize] }, size_{arrsize} {
      std::cout << "init constructor" << std::endl;
    }
    Array() {
      std::cout << "default constructor" << std::endl;
    }
    Array( Array&& copy ) 
     : array_{copy.array_}, size_{copy.size_} {
      copy.size_ = 0;
      copy.array_ = nullptr;
      std::cout << "move constructor" << std::endl;
    }
    ~Array() {
      delete[] array_;
      array_ = nullptr;
      size_ = 0;
    }

    Array<T>& operator=( const Array& rhs ) {
      std::cout << "operator =" << std::endl;
      Array<T> copy{rhs};
      swap(copy);
      return *this;
    }
    Array<T>& operator=( Array&& rhs ) {
      std::cout << "rvalue operator =" << std::endl;
      if ( &rhs != this ) {
        delete[] array_;
        array_ = rhs.array_;
        size_ = rhs.size_;
        rhs.array_ = nullptr;
        rhs.size_ = 0;
      }
      return *this;
    }
    const T& operator[]( size_t index ) const {
//      std::cout << "const operator[]" << std::endl;
      if ( index >= size_ ) {
        throw std::out_of_range {"Index too large" + std::to_string(index) };
      }
      return array_[index];
    }
    T& operator[]( size_t index ) {
//      std::cout << "operator[]" << std::endl;
      return const_cast<T&>( std::as_const(*this)[index] );
    }

    T* data() const { return array_; }
    size_t size() const { return size_; }
//    void push_back( T elem ) {
//    }

  private:
    T* array_ = nullptr;
    size_t size_ = 0;

  private:

    void swap( Array<T>& other ) noexcept {
      std::swap( size_, other.size_ );
      std::swap( array_, other.array_ );
    }
};

template<typename T> void swap( Array<T>& one, Array<T>& other ) noexcept {
  one.swap(other);
}

Array<int> buid_array_one(size_t size) {
  std::cout << "func for create result" << std::endl;
  Array<int> result{size};
  for ( size_t i {}; i < size; ++i ) {
    result[i] = i;
  }
  return result;
}
//
//Array<int>&& buid_array_two(size_t size) {
//  std::cout << "func for create result two";
//  Array<int> result{size};
//  for ( size_t i {}; i < size; ++i ) {
//    result[i] = i;
//  }
//  return result;
//}

std::list<Array<int>> fwdlist;

template<typename T> void test_forward( T&& fwd_array) {
  std::cout << "try fwd elem" << std::endl;
  fwdlist.push_back( std::forward<T>(fwd_array) );
}

int main( [[maybe_unused]] int argc, [[maybe_unused]] char* argv[] ) {

  std::vector<Array<int>> arr_vec;
//  arr_vec.push_back(10);
  arr_vec.push_back( buid_array_one(15) );


  std::list<Array<int>> list_vec;
  list_vec.push_back( buid_array_one(15) );

  Array<int> a{10};
  list_vec.push_back(std::move(a));
  std::cout << fmt::format("origin size = {} ptr to data = {}", a.size(), static_cast<void*>( a.data() ) ) << std::endl;

  Array<int> tmparr{14};        //two lines for activate move assignment operator
//  auto&& tmpfwd = tmparr;

  test_forward(tmparr);
  test_forward(buid_array_one(1));

//  Array<int> lvalue{20};


  return EXIT_SUCCESS;
}

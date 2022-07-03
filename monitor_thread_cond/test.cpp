#include <stdlib.h>

#include <iostream>

#include <queue>
#include <condition_variable>
#include <mutex>
#include <functional>
#include <thread>
#include <chrono>

#include <list>

#include <fmt/core.h>
#include <fmt/ranges.h>

int max_val = 0;

int counter{0};

template<typename Message>
class FIFOMessageQueue
{
  public:
    explicit FIFOMessageQueue( size_t max_elements );
    void put( Message msg );
    Message get();

  private:
    size_t max_elements_{0};
    std::queue<Message> msgs_{};
    std::mutex mutex_;
    std::condition_variable gcond_;
    std::condition_variable pcond_;

//    std::mutex qmutex_;
};

template<typename Message> FIFOMessageQueue<Message>::FIFOMessageQueue( size_t max_elements )
  : max_elements_{max_elements}
{
}

template<typename Message> void FIFOMessageQueue<Message>::put( [[maybe_unused]]Message msg ) {
  std::cout << "put before lock" << std::endl;
  std::unique_lock lock{mutex_};
  pcond_.wait( lock, [this]{ return max_elements_ > msgs_.size(); } );

  std::cout << "put before notify" << std::endl;
//  std::lock_guard qlock(qmutex_);
  msgs_.push(msg);
  gcond_.notify_all();
  std::cout << "success put" << std::endl;
  std::cout << "counter = " << ++counter << std::endl;
}

template<typename Message> Message FIFOMessageQueue<Message>::get()
{ 
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "try get" << std::endl;
  std::unique_lock lock{mutex_};
  gcond_.wait( lock, [this]{ return false == msgs_.empty(); } );

  std::cout << "get before notify" << std::endl;

//  std::lock_guard qlock(qmutex_);

  Message msg = msgs_.front();
  msgs_.pop();
  pcond_.notify_all();
  std::cout << "success get =" << msg << std::endl;
  if ( max_val < msg ) {
    max_val = msg;
  }
  std::cout << "counter = " << --counter << std::endl;
  return msg;
}

int main( [[maybe_unused]]int argc, [[maybe_unused]]char* argv[] ) {
  int amount = 5000;
  std::vector<std::thread*> getters(amount);
  std::vector<std::thread*> putters(amount);

  FIFOMessageQueue<int> queue(5);

  while (true) {

    for ( int i = 0; i < amount; ++i ) {
      std::thread* getter = new std::thread( &FIFOMessageQueue<int>::get, std::ref(queue) );
      std::thread* putter = new std::thread( &FIFOMessageQueue<int>::put, std::ref(queue), i );
      getters[i] = getter;
      putters[i] = putter;
    }
    for ( int i = 0; i < amount; ++i ) {
      getters[i]->join();
      putters[i]->join();
    }
    for ( auto g : getters ) {
      delete g;
    }
    for ( auto p : putters ) {
      delete p;
    }
    std::this_thread::sleep_for(std::chrono::seconds(8));
  }
  std::this_thread::sleep_for(std::chrono::seconds(25));
  std::cout << fmt::format("max get value = {}", max_val ) << std::endl;
  
  return EXIT_SUCCESS;
}

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
    std::mutex gmutex_;
    std::condition_variable gcond_;

    std::mutex pmutex_;
    std::condition_variable pcond_;

    std::mutex qmutex_;
};

template<typename Message> FIFOMessageQueue<Message>::FIFOMessageQueue( size_t max_elements )
  : max_elements_{max_elements}
{
}

template<typename Message> void FIFOMessageQueue<Message>::put( [[maybe_unused]]Message msg ) {
  std::unique_lock lock{pmutex_};
  pcond_.wait( lock, [this]{ return max_elements_ >= msgs_.size(); } );

  std::cout << "put before notify" << std::endl;
  std::lock_guard glock{gmutex_};
  std::lock_guard qlock(qmutex_);
  msgs_.push(10);
  gcond_.notify_one();
//  lock.unlock();
  std::cout << "success put" << std::endl;
  std::cout << "counter = " << ++counter << std::endl;
}

template<typename Message> Message FIFOMessageQueue<Message>::get()
{ 
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "try get" << std::endl;
  std::unique_lock lock{gmutex_};
  gcond_.wait( lock, [this]{ return false == msgs_.empty(); } );

  std::cout << "get before notify" << std::endl;
  std::lock_guard plock{pmutex_};

  std::lock_guard qlock(qmutex_);

  Message msg = msgs_.front();
  msgs_.pop();
  lock.unlock();
  pcond_.notify_one();
  std::cout << "success get =" << msg << std::endl;
  std::cout << "counter = " << --counter << std::endl;
  return msg;
}

int main( [[maybe_unused]]int argc, [[maybe_unused]]char* argv[] ) {
  int amount = 500;
  std::vector<std::thread*> getters(amount);
  std::vector<std::thread*> putters(amount);

  FIFOMessageQueue<int> queue(100);

  for ( int i = 0; i < amount; ++i ) {
    std::thread* getter = new std::thread( &FIFOMessageQueue<int>::get, std::ref(queue) );
    std::thread* putter = new std::thread( &FIFOMessageQueue<int>::put, std::ref(queue), 10 );
    getters[i] = getter;
    putters[i] = putter;
  }
//  for ( int i = 0; i < amount; ++i ) {
//    putters[i]->detach();
//  }
//  std::this_thread::sleep_for(std::chrono::seconds(5));
//  for ( int i = 0; i < amount; ++i ) {
//    getters[i]->detach();
//  }
  std::this_thread::sleep_for(std::chrono::seconds(25));
//  FIFOMessageQueue<int> msgs{100};
  
  return EXIT_SUCCESS;
}

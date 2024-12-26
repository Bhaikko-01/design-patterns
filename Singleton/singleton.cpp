#include <iostream>
#include <string>
#include <thread>
#include <mutex>

class Singleton {
public:
  std::string val;

protected:
  static Singleton* singleton;
  static std::mutex mutex;

private:
  Singleton(std::string val) {
    this->val = val;
  }

public:
  static Singleton* getInstanceThreadUnsafe(std::string value);
  static Singleton* getInstanceThreadSafe(std::string value);
};

// * Required to initialise static variables in Cpp
Singleton* Singleton::singleton = nullptr;
std::mutex Singleton::mutex;

Singleton* Singleton::getInstanceThreadUnsafe(std::string value) {
  if (singleton == nullptr) {
    singleton = new Singleton(value);
  }

  return singleton;
}

Singleton* Singleton::getInstanceThreadSafe(std::string value) {
  if (singleton == nullptr) {
    Singleton::mutex.lock();

    if (singleton == nullptr) {
      singleton = new Singleton(value);
    }

    Singleton::mutex.unlock();
  }

  return singleton;
}

void threadFoo()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  // Singleton* singleton = Singleton::getInstanceThreadUnsafe("foo");
  Singleton* singleton = Singleton::getInstanceThreadSafe("foo");

  std::cout << singleton->val << "\n";
}

void threadBar()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  // Singleton* singleton = Singleton::getInstanceThreadUnsafe("bar");
  Singleton* singleton = Singleton::getInstanceThreadSafe("bar");

  std::cout << singleton->val << "\n";
}

int main()
{
  std::thread t1(threadFoo);
  std::thread t2(threadBar);

  // * For unsafe instantiation, multithreading will yield 2 instances
  t1.join();
  t2.join();

  return 0;
}

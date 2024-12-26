#include <iostream>
#include <string>
#include <algorithm>

class Adaptee {
public:
  std::string process() {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

class AdapterInterface {
public:
  virtual std::string request() = 0;
};

class ConcreteAdapter : public AdapterInterface {
private:
  Adaptee* adaptee;

public:
  ConcreteAdapter(Adaptee* adaptee) {
    this->adaptee = adaptee;
  }

  virtual std::string request() override {
    std::string dup = std::string(adaptee->process());

    std::reverse(dup.begin(), dup.end());

    return dup;
  }
};

int main()
{
  Adaptee* adaptee = new Adaptee();
  std::cout << "Without Using Adapter --- " << std::endl;
  std::cout << "Adaptee Output: " << adaptee->process() << std::endl;

  AdapterInterface* adapter = new ConcreteAdapter(adaptee);

  std::cout << "Using Adapter --- " << std::endl;
  std::cout << "Adapter Output: " << adapter->request() << std::endl;

  return 0;
}

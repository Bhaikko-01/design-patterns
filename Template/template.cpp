#include <iostream>
#include <string>

class AbstractClass {
public:
  virtual void templateMethod() final {
    this->base1();
    this->base2();
    this->hook1();
    this->required1();
    this->required2();
    this->hook2();
  }

protected:
  virtual void base1() {
    std::cout << "Base 1" << std::endl;
  }

  virtual void base2() {
    std::cout << "Base 2" << std::endl;
  }

  virtual void required1() = 0;
  virtual void required2() = 0;

  virtual void hook1() {}
  virtual void hook2() {}
};

class Concrete1 : public AbstractClass {
protected:
  virtual void required1() override {
    std::cout << "Concrete Required 1" << std::endl;
  }

  virtual void required2() override {
    std::cout << "Concrete Required 2" << std::endl;
  }

  virtual void hook1() override {
    std::cout << "Concrete Hook 1" << std::endl;
  }
};

int main()
{
  Concrete1* concrete1 = new Concrete1();
  concrete1->templateMethod();

  return 0;
}

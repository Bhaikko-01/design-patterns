#include <iostream>
#include <string>

class Implementation {
public:
  virtual std::string operation() = 0;
};

class ConcreteImplementationA : public Implementation {
public:
  virtual std::string operation() override {
    return "Concrete Implementation A working.";
  }
};

class ConcreteImplementationB : public Implementation {
public:
  virtual std::string operation() override {
    return "Concrete Implementation B working.";
  }
};

class Abstraction {
protected:
  Implementation* implementation;

public:
  Abstraction(Implementation* implementation) {
    this->implementation = implementation;
  }

  virtual std::string operation() {
    return "Abstraction: " + implementation->operation();
  }
};

class ExtendedAbstraction : public Abstraction {
public:
  ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}

  virtual std::string operation() override {
    return "Extended Abstraction: " + implementation->operation();
  }
};

int main()
{
  Implementation* implementation = new ConcreteImplementationA();
  Abstraction* abstraction = new Abstraction(implementation);

  std::cout << abstraction->operation() << std::endl;

  delete implementation;
  delete abstraction;

  implementation = new ConcreteImplementationB;
  abstraction = new ExtendedAbstraction(implementation);

  std::cout << abstraction->operation() << std::endl;

  delete implementation;
  delete abstraction;

  return 0;
}

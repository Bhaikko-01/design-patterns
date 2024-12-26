#include <iostream>
#include <string>

class Subsystem1 {
public:
  std::string operation1() {
    return "Subsystem 1: Ready";
  }

  std::string operation2() {
    return "Subsystem 2: Finish";
  }
};

class Subsystem2 {
public:
  std::string operation1() {
    return "Subsystem 1: Ready";
  }

  std::string operation2() {
    return "Subsystem 2: Finish";
  }
};

class Facade {
protected:
  Subsystem1* subsystem1;
  Subsystem2* subsystem2;

public:
  Facade() {
    subsystem1 = new Subsystem1();
    subsystem2 = new Subsystem2();
  }

  virtual std::string operation() {
    return "Facade init \n" +
           subsystem1->operation1() + "\n" +
           subsystem1->operation2() + "\n" +
           subsystem2->operation1() + "\n" +
           subsystem2->operation2();
  }
};

int main()
{
  Subsystem1 *subsystem1 = new Subsystem1;
  Subsystem2 *subsystem2 = new Subsystem2;

  Facade* facade = new Facade();

  std::cout << facade->operation() << std::endl;

  delete facade;

  return 0;
}

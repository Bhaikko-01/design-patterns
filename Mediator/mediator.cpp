#include <iostream>
#include <string>

class BaseComponent;

class Mediator {
public:
  virtual void notify(BaseComponent* sender, std::string event) = 0;
};

class BaseComponent {
protected:
  Mediator* mediator;

public:
  void setMediator(Mediator* mediator) {
    this->mediator = mediator;
  }
};

class Component1 : public BaseComponent {
public:
  void DoA() {
    std::cout << "Component1 does A." << std::endl;

    this->mediator->notify(this, "A");
  }

  void DoB() {
    std::cout << "Component1 does B." << std::endl;

    this->mediator->notify(this, "B");
  }
};

class Component2 : public BaseComponent {
public:
  void DoC() {
    std::cout << "Component2 does C." << std::endl;

    this->mediator->notify(this, "C");
  }

  void DoD() {
    std::cout << "Component1 does D." << std::endl;

    this->mediator->notify(this, "D");
  }
};

class ConcreteMediator : public Mediator {
private:
  Component1* component1;
  Component2* component2;

public:
  ConcreteMediator(Component1* c1, Component2* c2) {
    this->component1 = c1;
    this->component2 = c2;

    this->component1->setMediator(this);
    this->component2->setMediator(this);
  }

  virtual void notify(BaseComponent* sender, std::string event) override {
    if (event == "A") {
      std::cout << "Mediator reacts on A and triggers" << std::endl;
      component2->DoC();
    }

    if (event == "D") {
      std::cout << "Mediator reacts on D and triggers" << std::endl;
      component1->DoB();
      component2->DoC();
    }
  }
};

int main()
{
  Component1* c1 = new Component1();
  Component2* c2 = new Component2();

  ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

  std::cout << "Client triggers operation A." << std::endl;
  c1->DoA();
  std::cout << std::endl;
  std::cout << "Client triggers operation D." << std::endl;
  c2->DoD();

  return 0;
}

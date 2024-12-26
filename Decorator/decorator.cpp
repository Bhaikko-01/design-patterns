#include <iostream>
#include <string>

class Component {
public:
  virtual std::string operation() = 0;
};

class ConcreteComponent : public Component {
public:
  virtual std::string operation() override {
    return "ConcreteComponent";
  }
};

class Decorator : public Component {
protected:
  Component* component;

public:
  Decorator(Component* component) {
    this->component = component;
  }

  virtual std::string operation() override {
    return this->component->operation();
  }
};

class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component* component) : Decorator(component) {}

  virtual std::string operation() override {
    return "ConcreteDecoratorA(" + Decorator::operation() + ")";
  }
};

class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component* component) : Decorator(component) {}

  virtual std::string operation() override {
    return "ConcreteDecoratorB(" + Decorator::operation() + ")";
  }
};

int main()
{
  Component* simple = new ConcreteComponent;
  std::cout << "Client: I've got a simple component: " << std::endl;
  std::cout << "Result: " << simple->operation() << std::endl << std::endl;

  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Client: Now I've got a decorated component: " << std::endl;
  std::cout << "Result: " << decorator2->operation() << std::endl;

  delete simple;
  delete decorator1;
  delete decorator2;

  return 0;
}

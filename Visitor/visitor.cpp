#include <iostream>
#include <string>

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
public:
  virtual void visitConcreteComponentA(ConcreteComponentA* element) = 0;
  virtual void visitConcreteComponentB(ConcreteComponentB* element) = 0;
};

class Component {
public:
  std::string name;

public:
  virtual void accept(Visitor* visitor) = 0;
};

class ConcreteComponentA : public Component {
public:
  ConcreteComponentA(std::string name) {
    this->name = name;
  }

  virtual void accept(Visitor* visitor) {
    visitor->visitConcreteComponentA(this);
  }
};

class ConcreteComponentB : public Component {
public:
  ConcreteComponentB(std::string name) {
    this->name = name;
  }

  virtual void accept(Visitor* visitor) {
    visitor->visitConcreteComponentB(this);
  }
};

class ConcreteVisitor1 : public Visitor {
public:
  virtual void visitConcreteComponentA(ConcreteComponentA* element) {
    std::cout << "Concrete Visitor 1 visited by " << element->name << std::endl;
  }

  virtual void visitConcreteComponentB(ConcreteComponentB* element) {
    std::cout << "Concrete Visitor 1 visited by " << element->name << std::endl;
  }
};

class ConcreteVisitor2 : public Visitor {
public:
  virtual void visitConcreteComponentA(ConcreteComponentA* element) {
    std::cout << "Concrete Visitor 2 visited by " << element->name << std::endl;
  }

  virtual void visitConcreteComponentB(ConcreteComponentB* element) {
    std::cout << "Concrete Visitor 2 visited by " << element->name << std::endl;
  }
};

int main()
{
  Component* component1 = new ConcreteComponentA("Concrete A");
  Component* component2 = new ConcreteComponentB("Concrete B");

  Visitor* visitor1 = new ConcreteVisitor1();
  Visitor* visitor2 = new ConcreteVisitor2();

  component1->accept(visitor1);
  component1->accept(visitor2);
  component2->accept(visitor1);
  component2->accept(visitor2);

  return 0;
}

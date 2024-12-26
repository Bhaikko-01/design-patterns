#include <iostream>
#include <unordered_map>
#include <string>

enum Type {
  PROTOTYPE_1 = 0,
  PROTOTYPE_2
};

class Prototype {
protected:
  std::string name;
  float field;

public:
  Prototype(std::string name) {
    this->name = name;
  }

  virtual Prototype* clone() = 0;

  virtual void setField(float field) {
    this->field = field;

    std::cout << "Setting Field of " << name << " with field " << this->field << std::endl;
  }
};

class ConcretePrototype1 : public Prototype {
private:
  float field1;

public:
  ConcretePrototype1(std::string name, float field1) : Prototype(name) {
    this->field1 = field1;
  }

  virtual Prototype* clone() override {
    return new ConcretePrototype1(*this);
  }
};

class ConcretePrototype2 : public Prototype {
private:
  float field2;

public:
  ConcretePrototype2(std::string name, float field2) : Prototype(name) {
    this->field2 = field2;
  }

  virtual Prototype* clone() override {
    return new ConcretePrototype2(*this);
  }
};

class PrototypeFactory {
private:
  std::unordered_map<Type, Prototype*> prototypes;

public:
  PrototypeFactory() {
    prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.f);
    prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 60.f);
  }

  Prototype* createPrototype(Type type) {
    return prototypes[type]->clone();
  }
};

int main()
{
  PrototypeFactory* factory = new PrototypeFactory();

  std::cout << "Let's create a Prototype 1" << std::endl;

  Prototype *prototype = factory->createPrototype(Type::PROTOTYPE_1);
  prototype->setField(90);
  delete prototype;

  std::cout << std::endl;

  std::cout << "Let's create a Prototype 2" << std::endl;

  prototype = factory->createPrototype(Type::PROTOTYPE_2);
  prototype->setField(10);

  delete prototype;

  return 0;
}

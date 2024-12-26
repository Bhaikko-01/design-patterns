#include <iostream>
#include <string>

class AbstractProductA {
public:
  virtual std::string processA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
  virtual std::string processA() const override {
    return "Concrete Product A1";
  }
};

class ConcreteProductA2 : public AbstractProductA {
public:
  virtual std::string processA() const override {
    return "Concrete Product A2";
  }
};

class AbstractProductB {
public:
  virtual std::string processB() const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
  virtual std::string processB() const override {
    return "Concrete Product B1";
  }
};

class ConcreteProductB2 : public AbstractProductB {
public:
  virtual std::string processB() const override {
    return "Concrete Product B2";
  }
};

class AbstractFactory {
public:
  virtual AbstractProductA* createProductA() const = 0;
  virtual AbstractProductB* createProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
  virtual AbstractProductA* createProductA() const override {
    return new ConcreteProductA1();
  }

  virtual AbstractProductB* createProductB() const override {
    return new ConcreteProductB1();
  }
};

class ConcreteFactory2 : public AbstractFactory {
public:
  virtual AbstractProductA* createProductA() const override {
    return new ConcreteProductA2();
  }

  virtual AbstractProductB* createProductB() const override {
    return new ConcreteProductB2();
  }
};

int main()
{
  ConcreteFactory1* f1 = new ConcreteFactory1();
  AbstractProductA* pA1 = f1->createProductA();
  AbstractProductB* pB1 = f1->createProductB();

  std::cout << pA1->processA() << std::endl;
  std::cout << pB1->processB() << std::endl;

  ConcreteFactory2* f2 = new ConcreteFactory2();
  AbstractProductA* pA2 = f2->createProductA();
  AbstractProductB* pB2 = f2->createProductB();

  std::cout << pA2->processA() << std::endl;
  std::cout << pB2->processB() << std::endl;
}

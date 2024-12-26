#include <iostream>
#include <string>

class Product {
public:
  virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
  virtual std::string operation() const override {
    return "ConcreteProduct1 Operation";
  }
};

class ConcreteProduct2 : public Product {
public:
  virtual std::string operation() const override {
    return "ConcreteProduct2 Operation";
  }
};

class Creator {
public:
  virtual Product* factoryMethod() const = 0;

  std::string someOperation() const {
    Product* product = this->factoryMethod();

    std::string result = "Creator called for " + product->operation();

    delete product;
    return result;
  }
};

class ConcreteCreator1 : public Creator {
public:
  virtual Product* factoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
public:
  virtual Product* factoryMethod() const override {
    return new ConcreteProduct2();
  }
};

int main()
{
  Creator* creator1 = new ConcreteCreator1();
  std::cout << creator1->someOperation() << std::endl;

  Creator* creator2 = new ConcreteCreator2();
  std::cout << creator2->someOperation() << std::endl;

  delete creator1;
  delete creator2;

  return 0;
}

#include <iostream>
#include <vector>
#include <string>

class Product1 {
public:
  std::vector<std::string> parts;

  void listParts() {
    std::cout << "Product Parts: ";

    for (std::string part: parts) {
      std::cout << part << ", ";
    }

    std::cout << std::endl << std::endl;
  }
};

class Builder {
public:
  virtual Builder* addPartA() = 0;
  virtual Builder* addPartB() = 0;
  virtual Builder* addPartC() = 0;
};

class ConcreteBuilder1 : public Builder {
private:
  Product1* product;

public:
  ConcreteBuilder1() {
    this->reset();
  }

  void reset() {
    this->product = new Product1();
  }

  virtual Builder* addPartA() override {
    this->product->parts.push_back("Part A1");
    return this;
  }

  virtual Builder* addPartB() override {
    this->product->parts.push_back("Part B1");
    return this;
  }

  virtual Builder* addPartC() override {
    this->product->parts.push_back("Part C1");
    return this;
  }

  Product1* getProduct() {
    Product1* result = this->product;
    this->reset();

    return result;
  }
};

class Director {
private:
  Builder* builder;

public:
  void setBuilder(Builder* builder) {
    this->builder = builder;
  }

  void buildMinimalBuild() {
    this->builder->addPartA();
  }

  void buildFullBuild() {
    this->builder->addPartA()->addPartB()->addPartC();
  }
};

int main()
{
  Director* director = new Director();

  ConcreteBuilder1* builder = new ConcreteBuilder1();
  director->setBuilder(builder);
  std::cout << "Standard basic product: " << std::endl;
  director->buildMinimalBuild();

  Product1* p = builder->getProduct();
  p->listParts();
  delete p;

  std::cout << "Standard full featured product: " << std::endl;
  director->buildFullBuild();

  p = builder->getProduct();
  p->listParts();
  delete p;

  std::cout << "Custom product: " << std::endl;
  builder->addPartA()->addPartC();
  p = builder->getProduct();
  p->listParts();
  delete p;

  delete builder;

  return 0;
}

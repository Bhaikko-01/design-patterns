#include <iostream>
#include <string>

class Strategy {
public:
  virtual void perform(std::string data) = 0;
};

class Context {
private:
  Strategy* strategy;

public:
  Context(Strategy* strategy) {
    this->strategy = strategy;
  }

  void setStrategy(Strategy* strategy) {
    this->strategy = strategy;
  }

  void businessLogic() {
    strategy->perform("hello world");
  }
};

class ConcreateStrategyA : public Strategy {
public:
  virtual void perform(std::string data) {
    std::cout << "Strategy A processing " << data << std::endl;
  }
};

class ConcreateStrategyB : public Strategy {
public:
  virtual void perform(std::string data) {
    std::cout << "Strategy B processing " << data << std::endl;
  }
};

int main()
{
  Strategy* concreateStrategyA = new ConcreateStrategyA();
  Strategy* concreateStrategyB = new ConcreateStrategyB();

  Context* context = new Context(concreateStrategyA);
  context->businessLogic();

  context->setStrategy(concreateStrategyB);
  context->businessLogic();

  return 0;
}

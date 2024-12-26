#include <iostream>
#include <string>
#include <vector>

class Handler {
public:
  virtual Handler* setNext(Handler* handler) = 0;
  virtual std::string handle(std::string request) = 0;
};

class AbstractHandler : public Handler {
private:
  Handler* handler;

public:
  AbstractHandler() {
    this->handler = nullptr;
  }

  Handler* setNext(Handler* handler) {
    this->handler = handler;

    return this->handler;
  }

  virtual std::string handle(std::string request) override {
    if (this->handler) {
      return this->handler->handle(request);
    }

    return "";
  }
};

class MonkeyHandler : public AbstractHandler {
public:
  virtual std::string handle(std::string request) override {
    if (request == "Banana") {
      return "Monkey: Eat " + request;
    }

    return AbstractHandler::handle(request);
  }
};

class SquirrelHandler : public AbstractHandler {
public:
  virtual std::string handle(std::string request) override {
    if (request == "Nut") {
      return "Squirrel: Eat " + request;
    }

    return AbstractHandler::handle(request);
  }
};

class DogHandler : public AbstractHandler {
public:
  virtual std::string handle(std::string request) override {
    if (request == "MeatBall") {
      return "Dog: Eat " + request;
    }

    return AbstractHandler::handle(request);
  }
};

void eatFood(Handler* handler)
{
  std::vector<std::string> foods = { "Nut", "Banana", "Coffee" };

  for (std::string food: foods) {
    std::string res = handler->handle(food);

    if (res.empty()) {
      std::cout << "No one touched " << food << std::endl;
    } else {
      std::cout << res << std::endl;
    }
  }
}

int main()
{
  MonkeyHandler* monkey = new MonkeyHandler();
  SquirrelHandler* squirrel = new SquirrelHandler();
  DogHandler* dog = new DogHandler();

  monkey->setNext(squirrel)->setNext(dog);

  std::cout << "Chain: Monkey > Squirrel > Dog" << std::endl;
  eatFood(monkey);
  std::cout << std::endl;

  std::cout << "Subchain: Squirrel > Dog" << std::endl;
  eatFood(squirrel);

  delete monkey;
  delete squirrel;
  delete dog;

  return 0;
}

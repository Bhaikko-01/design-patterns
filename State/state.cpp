#include <iostream>
#include <string>

class Context;

class State {
protected:
  Context* context;

public:
  std::string name;

public:
  State(std::string name) {
    this->name = name;
  }

  void setContext(Context* context, std::string name) {
    this->context = context;
    this->name = name;
  }

  virtual void transition1() = 0;
  virtual void transition2() = 0;
};

class Context {
private:
  State* state;

public:
  Context(State* state) {
    this->state = nullptr;
    this->transitionTo(state);
  }

  void transitionTo(State* state) {
    std::cout << "Current State: " << state->name << std::endl;

    this->state = state;
    this->state->setContext(this, state->name);
  }

  void request1() {
    this->state->transition1();
  }

  void request2() {
    this->state->transition2();
  }
};

class ConcreteStateA : public State {
public:
  ConcreteStateA(std::string name) : State(name) {}

  virtual void transition1() override {
    std::cout << "State A handles 1" << std::endl;
  }

  virtual void transition2() override;
};

class ConcreteStateB : public State {
public:
  ConcreteStateB(std::string name) : State(name) {}

  virtual void transition1() override {
    std::cout << "State B handles 1" << std::endl;
  }

  virtual void transition2() override {
    std::cout << "State B handles 2" << std::endl;

    this->context->transitionTo(new ConcreteStateA("A"));
  }
};

void ConcreteStateA::transition2() {
  std::cout << "State A handles 2" << std::endl;

  this->context->transitionTo(new ConcreteStateB("B"));
}

int main()
{
  Context* context = new Context(new ConcreteStateA("A"));
  context->request1();
  context->request2();

  return 0;
}

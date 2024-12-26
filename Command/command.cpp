#include <iostream>
#include <string>

class Command {
public:
  virtual void execute() = 0;
};

class SimpleCommand : public Command {
private:
  std::string payload;

public:
  SimpleCommand(std::string payload) {
    this->payload = payload;
  }

public:
  virtual void execute() override {
    std::cout << "SimpleCommand: Printing " << payload << std::endl;
  }
};

class ComplexCommand : public Command {
private:
  std::string payload1;
  std::string payload2;

public:
  ComplexCommand(std::string payload1, std::string payload2) {
    this->payload1 = payload1;
    this->payload2 = payload2;
  }

  virtual void execute() override {
    std::cout << "ComplexCommand: Printing " << payload1 << " " << payload2 << std::endl;
  }
};

class Invoker {
private:
  Command* onStart;
  Command* onEnd;

public:
  void setOnStart(Command* command) {
    this->onStart = command;
  }

  void setOnEnd(Command* command) {
    this->onEnd = command;
  }

  void process() {
    std::cout << "Before Start" << std::endl;
    this->onStart->execute();

    std::cout << "Processing..." << std::endl;

    this->onEnd->execute();
  }
};

int main()
{
  Invoker* invoker = new Invoker();

  invoker->setOnStart(new SimpleCommand("Starting..."));
  invoker->setOnEnd(new ComplexCommand("Add log", "Send alert"));

  invoker->process();

  return 0;
}

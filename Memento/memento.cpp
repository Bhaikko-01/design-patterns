#include <iostream>
#include <string>
#include <stack>

class Memento {
public:
  virtual std::string currState() = 0;
};

class ConcreteMemento : public Memento {
private:
  std::string state;

public:
  ConcreteMemento(std::string state) {
    this->state = state;
  }

  virtual std::string currState() override {
    return this->state;
  }
};

class Originator {
private:
  std::string state;

public:
  Originator(std::string state) {
    this->state = state;
  }

  std::string getState() {
    return this->state;
  }

  void updateState(std::string state) {
    this->state = state;
  }

  Memento* save() {
    return new ConcreteMemento(this->state);
  }

  void restore(Memento* memento) {
    this->state = memento->currState();
  }
};

class Caretaker {
private:
  std::stack<Memento*> memetos;

  Originator* originator;

public:
  Caretaker(Originator* originator) {
    this->originator = originator;
  }

  void backup() {
    this->memetos.push(originator->save());
  }

  void undo() {
    if (memetos.empty()) {
      return;
    }

    Memento* top = memetos.top();
    memetos.pop();

    this->originator->restore(top);
  }
};

int main()
{
  Originator* originator = new Originator("State 0");
  Caretaker* caretaker = new Caretaker(originator);

  caretaker->backup();
  originator->updateState("State 1");
  caretaker->backup();
  originator->updateState("State 2");
  caretaker->backup();
  originator->updateState("State 3");

  std::cout << "Client: Now, let's rollback!" << std::endl;
  caretaker->undo();
  std::cout << "Client: Once more!" << std::endl;
  caretaker->undo();

  std::cout << originator->getState() << std::endl;

  return 0;
}

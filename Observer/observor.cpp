#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IObserver {
public:
  virtual void update(std::string message) = 0;
};

class ISubject {
public:
  virtual void attach(IObserver* observer) = 0;
  virtual void detach(IObserver* ovserver) = 0;
  virtual void notify() = 0;
};

class Subject : public ISubject {
private:
  std::vector<IObserver*> observers;
  std::string message;

public:
  virtual void attach(IObserver* observer) override {
    this->observers.push_back(observer);
  }

  virtual void detach(IObserver* observer) override {
    auto it = std::find(observers.begin(), observers.end(), observer);

    this->observers.erase(it);
  }

  virtual void notify() override {
    std::cout << "Broadcasting to " << observers.size() << " observers" << std::endl;

    for (IObserver* observer: observers) {
      observer->update(message);
    }
  }

  void businessLogic(std::string message) {
    std::cout << "Updating state" << std::endl;
    notify();
  }
};

class Observer : public IObserver {
private:
  Subject* subject;

public:
  Observer(Subject* subject) {
    this->subject = subject;

    this->subject->attach(this);
  }

  virtual void update(std::string message) override {
    std::cout << "Observor got notifier" << std::endl;
  }

  void removeFromList() {
    this->subject->detach(this);
  }
};

int main()
{
  Subject* subject = new Subject();
  Observer* observer1 = new Observer(subject);
  Observer* observer2 = new Observer(subject);
  Observer* observer3 = new Observer(subject);
  Observer* observer4;
  Observer* observer5;

  subject->businessLogic("Hello World! :D");
  observer3->removeFromList();

  subject->businessLogic("The weather is hot today! :p");
  observer4 = new Observer(subject);

  observer2->removeFromList();
  observer5 = new Observer(subject);

  subject->businessLogic("My new car is great! ;)");
  observer5->removeFromList();

  observer4->removeFromList();
  observer1->removeFromList();

  return 0;
}

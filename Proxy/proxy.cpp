
#include <iostream>
#include <string>

class Subject {
public:
  virtual void request() = 0;
};

class RealSubject : public Subject {
public:
  virtual void request() override {
    std::cout << "RealSubject: Handling request" << std::endl;
  }
};

class Proxy : public Subject {
private:
  Subject* subject;

public:
  Proxy(Subject* subject) {
    this->subject = subject;
  }

  bool checkAccess() {
    std::cout << "Proxy: Checking access" << std::endl;
    return true;
  }

  virtual void request() override {
    if (checkAccess()) {
      subject->request();
    }
  }
};

int main()
{
  std::cout << "Client: Executing the client code with a real subject: " << std::endl;

  Subject* realSubject = new RealSubject;
  realSubject->request();

  std::cout << std::endl;

  std::cout << "Client: Executing the same client code with a proxy: " << std::endl;;
  Proxy* proxy = new Proxy(realSubject);
  proxy->request();

  return 0;
}

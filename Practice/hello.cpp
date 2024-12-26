#include <bits/stdc++.h>

using namespace std;

void hello() {
  cout << "hello with no args" << endl;
}

void hello(int x) {
  cout << "hello with 1 args " << x << endl;
}

class InterfaceClass {
  virtual void hello() const = 0;
};

class X {
public:
  virtual void hello() {
    cout << "X hello" << endl;
  }
};

class Z {
public:
  virtual void hello() {
    cout << "X hello" << endl;
  }
};

class Y : public X, public Z {
public:
  virtual void hello() override {
    cout << "Y hello" << endl;
  }
};

// field -> variables
// behavior -> methods

void solution()
{
  // hello();
  // hello(1);

  // X x;
  // Y y;

  // x.hello();
  // y.hello();

  X* x = new Y();
  x->hello();
  // Y* y = new X();
}

/*
  Y < X


*/

int main()
{
  // solution();
  cout << "Start" << endl;

  int i = 0;
  while (i < 100000000) {
    i++;
  }

  cout << "Done" << endl;

  return 0;
}

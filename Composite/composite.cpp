#include <iostream>
#include <string>
#include <vector>

class Component {
protected:
  Component* parent;

public:
  virtual void setParent(Component* parent) {
    this->parent = parent;
  }

  virtual bool isComposite() const {
    return false;
  }

  virtual std::string operation() = 0;
};

class Leaf : public Component {
  virtual std::string operation() override {
    return "Leaf";
  }
};

class Composite : public Component {
protected:
  std::vector<Component*> children;

public:
  virtual void add(Component* child) {
    this->children.push_back(child);
  }

  virtual std::string operation() override {
    std::string result = "";
    int n = children.size();

    for (int i = 0; i < children.size(); i++) {
      Component* component = children[i];

      if (i == n - 1) {
        result += component->operation();
      } else {
        result += component->operation() + " | ";
      }
    }

    return "Branch(" + result + ")";
  }
};

int main()
{
  Component* simple = new Leaf();

  std::cout << "Client: I've got a simple component:" << std::endl;
  std::cout << "Result: " << simple->operation() << std::endl;
  std::cout << std::endl;

  Composite* tree = new Composite();
  Composite* branch1 = new Composite();

  Leaf* leaf1 = new Leaf();
  Leaf* leaf2 = new Leaf();
  Leaf* leaf3 = new Leaf();

  branch1->add(leaf1);
  branch1->add(leaf1);

  Composite* branch2 = new Composite();
  branch2->add(leaf3);
  tree->add(branch1);
  tree->add(branch2);

  std::cout << "Client: Now I've got a composite tree:" << std::endl;
  std::cout << "Result: " << tree->operation() << std::endl;
  std::cout << std::endl;

  std::cout << "Client: I don't need to check the components classes even when managing the tree:" << std::endl;
  std::cout << "Result: " << tree->operation() << std::endl;
  std::cout << std::endl;

  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf1;
  delete leaf2;
  delete leaf3;

  return 0;
}

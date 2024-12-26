#include <iostream>
#include <string>
#include <unordered_map>

class SharedState {
public:
  std::string brand;
  std::string model;
  std::string color;

public:
  SharedState(std::string brand, std::string model, std::string color) {
    this->brand = brand;
    this->model = model;
    this->color = color;
  }

  std::string operation() {
    return "[ " + this->brand + " , " + this->model + " , " + this->color + " ]";
  }
};

class UniqueState {
public:
  std::string owner;
  std::string plates;

public:
  UniqueState(std::string owner, std::string plates) {
    this->owner = owner;
    this->plates = plates;
  }

  std::string operation() {
    return "[ " + this->owner + " , " + this->plates + " ]";
  }
};

class Flyweight {
private:
  SharedState* sharedState;

public:
  Flyweight(SharedState* sharedState) {
    this->sharedState = sharedState;
  }

  Flyweight(Flyweight* other) {
    this->sharedState = other->sharedState;
  }

  std::string operation(UniqueState* uniqueState) {
    return "Flyweight: Displaying shared (" + sharedState->operation() + ") and unique (" + uniqueState->operation() + ") state.";
  }
};

class FlyweightFactory {
private:
  std::unordered_map<std::string, Flyweight*> flyweights;

  std::string getKey(SharedState* sharedState) {
    return sharedState->brand + "-" + sharedState->color + "-" + sharedState->color;
  }

public:
  FlyweightFactory(std::initializer_list<SharedState*> sharedStates) {
    for (SharedState* sharedState: sharedStates) {
      std::string key = getKey(sharedState);
      flyweights[key] = new Flyweight(sharedState);
    }
  }

  Flyweight* getFlyweight(SharedState* sharedState) {
    std::string key = getKey(sharedState);

    if (this->flyweights[key]) {
      std::cout << "FlyweightFactory: Reusing Existing." << std::endl;
    } else {
      std::cout << "FlyweightFactory: Creating new one." << std::endl;
      flyweights[key] = new Flyweight(sharedState);
    }

    return this->flyweights[key];
  }

  void listFlyweights() {
    std::cout << "FlyweightFactory: " << this->flyweights.size() << " flyweights exist." << std::endl;

    for (std::pair<std::string, Flyweight*> pair: this->flyweights) {
      std::cout << pair.first << std::endl;
    }
  }
};

void addCarToDatabase(FlyweightFactory* factory, SharedState* sharedState, UniqueState* uniqueState) {
  Flyweight* flyweight = factory->getFlyweight(sharedState);

  flyweight->operation(uniqueState);
}

int main()
{
  SharedState* s1 = new SharedState("Chevrolet", "Camaro2018", "Pink");
  SharedState* s2 = new SharedState("Mercedes Benz", "C300", "Black");
  SharedState* s3 = new SharedState("Mercedes Benz", "C500", "Red");
  SharedState* s4 = new SharedState("BMW", "M5", "Red");
  SharedState* s5 = new SharedState("BMW", "X6", "White");
  SharedState* s6 = new SharedState("BMW", "X1", "Red");

  FlyweightFactory* factory = new FlyweightFactory({
    s1, s2, s3, s4, s5
  });

  factory->listFlyweights();

  UniqueState* uniqueState1 = new UniqueState("CL234IR", "James Doe");
  addCarToDatabase(factory, s1, uniqueState1);

  UniqueState* uniqueState2 = new UniqueState("CL234IR", "James Doe");
  addCarToDatabase(factory, s6, uniqueState2);

  factory->listFlyweights();
}

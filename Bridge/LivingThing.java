package Bridge;

interface BreatheImplementor {
  public void breathe();
}

class LandBreatheImplementor implements BreatheImplementor {
  public void breathe() {
    System.out.println("Breathe through lungs");
  }
}

class SeaBreatheImplementor implements BreatheImplementor {
  public void breathe() {
    System.out.println("Breathe through gills");
  }
}

abstract class LivingThing {
  BreatheImplementor breathImplementor;

  LivingThing(BreatheImplementor breathImplementor) {
    this.breathImplementor = breathImplementor;
  }

  abstract public void breathe();
}

class Dog extends LivingThing {
  public Dog(BreatheImplementor breatheImplementor) {
    super(breatheImplementor);
  }

  public void breathe() {
    this.breathImplementor.breathe();
  }
}

class Fish extends LivingThing {
  public Fish(BreatheImplementor breatheImplementor) {
    super(breatheImplementor);
  }

  public void breathe() {
    this.breathImplementor.breathe();
  }
}

class Main {
  void main() {
    Dog dog = new Dog(new LandBreatheImplementor());
    Fish fish = new Fish(new SeaBreatheImplementor());

    dog.breathe();
    fish.breathe();
  }
}

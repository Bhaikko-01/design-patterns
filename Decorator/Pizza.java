/**
 * Design a Pizza cost management system where Different types of Pizza can
 * exist with different addons such as
 * extra cheese, mushroom
 */

package Decorator;

abstract class BasePizza {
  abstract int cost();
}

// Decorator class for Topping which will have both `has-a` and `is-a` relation
// with BasePizza
abstract class ToppingDecorator extends BasePizza {
  BasePizza pizza;
}

// Simple pizza classes whose objects can be used
class Margherita extends BasePizza {
  public int cost() {
    return 100;
  }
}

class Farmhouse extends BasePizza {
  public int cost() {
    return 150;
  }
}

// Using Topping Decorator to create different Topping classes
class ExtraCheese extends ToppingDecorator {
  public ExtraCheese(BasePizza pizza) {
    // Adding ref of base pizza
    this.pizza = pizza;
  }

  public int cost() {
    return this.pizza.cost() + 10;
  }
}

class Mushroom extends ToppingDecorator {
  public Mushroom(BasePizza pizza) {
    this.pizza = pizza;
  }

  public int cost() {
    return this.pizza.cost() + 20;
  }
}

class Main {
  // Using above classes to Generate cost of different Permutations of Pizza
  void main() {
    Margherita mPizza = new Margherita();
    mPizza.cost(); // Cost of Margherita pizza

    // Marghrita with Extra Cheese
    ExtraCheese ecPizza = new ExtraCheese(mPizza);
    ecPizza.cost();

    // Marghrita with Extra Cheese and Mushroom
    Mushroom mEcPizza = new Mushroom(ecPizza);
    mEcPizza.cost();
  }
}

package Facade;

class Order {
  public void placeOrder() {
    System.out.println("Placing order");
  }

  public void dispatch() {
    System.out.println("Dispatching order");
  }
}

class Payment {
  public void processPayment() {
    System.out.println("Payment processing");
  }
}

class Inventory {
  public void updateInventory() {
    System.out.println("Updating inventory");
  }
}

// * This class will act as Facade for handling Order System
class OrderFacade {
  Order order;
  Payment payment;
  Inventory inventory;

  public OrderFacade() {
    this.order = new Order();
    this.payment = new Payment();
    this.inventory = new Inventory();
  }

  public void processOrder() {
    this.order.placeOrder();
    this.payment.processPayment();
    this.inventory.updateInventory();
    this.order.dispatch();
  }
}

class Main {
  void main() {
    OrderFacade orderFacade = new OrderFacade();
    orderFacade.processOrder();
  }
}

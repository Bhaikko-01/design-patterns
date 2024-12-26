package NullObject;

interface Vehicle {
  int price();
}

class Car implements Vehicle {
  public int price() {
    return 10;
  }
}

class NullVehicle implements Vehicle {
  public int price() {
    // Null object handling
    return 0;
  }
}

class VehicleFactory {
  public static Vehicle getVehicle(String type) {
    switch (type) {
      case "Car":
        return new Car();
      default:
        // Returning Null Object of vehicle instead of null
        return new NullVehicle();
    }
  }

}

class Main {
  void printPriceOfVehicle(Vehicle vehicle) {
    // This will never be null if object is created by VehicleFactory
    System.out.println(vehicle.price());
  }

  void main() {
    Vehicle car = VehicleFactory.getVehicle("Car");
    printPriceOfVehicle(car);

    Vehicle unknown = VehicleFactory.getVehicle("Bike");
    printPriceOfVehicle(unknown);
  }
}

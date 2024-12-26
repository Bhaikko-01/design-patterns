package AbstractFactory;

interface Vehicle {
  public int price();
}

class Mercedes implements Vehicle {
  public int price() {
    return 0;
  }
}

class Bmw implements Vehicle {
  public int price() {
    return 0;
  }
}

class Swift implements Vehicle {
  public int price() {
    return 0;
  }
}

class WagonR implements Vehicle {
  public int price() {
    return 0;
  }
}

interface VehicleFactory {
  public Vehicle getVehicle(String type);
}

class LuxaryFactory implements VehicleFactory {
  public Vehicle getVehicle(String type) {
    switch (type) {
      case "Mercedes":
        return new Mercedes();
      case "Bmw":
        return new Bmw();
      default:
        return null;
    }
  }
}

class AffordableFactory implements VehicleFactory {
  public Vehicle getVehicle(String type) {
    switch (type) {
      case "WagonR":
        return new WagonR();
      case "Swift":
        return new Swift();
      default:
        return null;
    }
  }
}

class VehicleTypeFactory {
  VehicleFactory getFactory(String type) {
    switch (type) {
      case "Luxory":
        return new LuxaryFactory();
      case "Affordable":
        return new AffordableFactory();
      default:
        return null;
    }
  }

}

class Main {
  void main() {
    VehicleTypeFactory vehicleTypeFactory = new VehicleTypeFactory();

    VehicleFactory vehicleFactory = vehicleTypeFactory.getFactory("Luxory");
    Vehicle vehicle = vehicleFactory.getVehicle("Bmw");

    vehicle.price();
  }
}

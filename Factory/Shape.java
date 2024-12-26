package Factory;

interface Shape {
  public void draw();
}

class Rectangle implements Shape {
  public void draw() {
    // Rectangle logic to draw
  }
}

class Circle implements Shape {
  public void draw() {
    // Circle logic to draw
  }
}

// This will act as Single source of truth for generating Objects based on
// conditions
class ShapeFactory {
  public Shape getShape(String type) {
    switch (type) {
      case "Circle":
        return new Circle();
      case "Rectangle":
        return new Rectangle();
      default:
        return null;
    }
  }
}

class Main {
  void main() {
    ShapeFactory factory = new ShapeFactory();

    Shape rectangle = factory.getShape("Rectangle");
    Shape circle = factory.getShape("Circle");

    rectangle.draw();
    circle.draw();
  }
}

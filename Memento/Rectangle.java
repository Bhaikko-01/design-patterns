package Memento;

import java.util.ArrayList;
import java.util.List;

// * Memento object
class RectangleMemento {
  // * Storing state of Originator
  public int height;
  public int width;

  RectangleMemento(int height, int width) {
    this.height = height;
    this.width = width;
  }
}

// * Originator
class Rectangle {
  public int height;
  public int width;

  Rectangle(int height, int width) {
    this.height = height;
    this.width = width;
  }

  RectangleMemento createMemento() {
    return new RectangleMemento(this.height, this.width);
  }

  void restoreMemento(RectangleMemento memento) {
    this.height = memento.height;
    this.width = memento.width;
  }
}

// * Caretaker
class RectangleCaretaker {
  List<RectangleMemento> history = new ArrayList<>();

  public void addMemento(RectangleMemento memento) {
    history.add(memento);
  }

  public RectangleMemento undo() {
    // * Pick the last element and return that memento

    return history.getLast();
  }
}

class Main {
  void main() {
    Rectangle rectangle = new Rectangle(1, 2);
    RectangleCaretaker rectangleCaretaker = new RectangleCaretaker();

    RectangleMemento memento = rectangle.createMemento();
    rectangleCaretaker.addMemento(memento);

    rectangle.width = 10;

    rectangle.restoreMemento(memento);
  }
}

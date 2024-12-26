package Visitor;

// * Visitor interface for Implementing methods for each object type
interface RoomVisitor {
  void visit(SingleRoom room);

  void visit(DoubleRoom room);
}

// * Element interface for Visitor Pattern
interface RoomElement {
  void accept(RoomVisitor visitor);
}

class SingleRoom implements RoomElement {
  public int price = 0;

  @Override
  public void accept(RoomVisitor visitor) {
    visitor.visit(this);
  }

}

class DoubleRoom implements RoomElement {
  public int price = 0;

  @Override
  public void accept(RoomVisitor visitor) {
    visitor.visit(this);
  }

}

class RoomPricingVisitor implements RoomVisitor {

  @Override
  public void visit(SingleRoom room) {
    room.price += 10;
  }

  @Override
  public void visit(DoubleRoom room) {
    room.price += 20;
  }

}

class Main {
  void main() {
    RoomElement singleRoom = new SingleRoom();
    RoomElement doubleRoom = new DoubleRoom();

    RoomPricingVisitor roomPricingVisitor = new RoomPricingVisitor();

    singleRoom.accept(roomPricingVisitor);
    doubleRoom.accept(roomPricingVisitor);
  }
}

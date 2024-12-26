package Mediator;

import java.util.ArrayList;
import java.util.List;

interface Colleague {
  void placeBid(int amount);

  void receiveBidNotification(int bidAmount);

  String getName();
}

interface AuctionMediator {
  void addBidder(Colleague colleague);

  void placeBid(Colleague bidder, int amount);
}

public class Auction implements AuctionMediator {
  List<Colleague> colleagues = new ArrayList<Colleague>();

  @Override
  public void addBidder(Colleague colleague) {
    colleagues.add(colleague);
  }

  @Override
  public void placeBid(Colleague bidder, int amount) {
    for (Colleague colleague : colleagues) {
      if (colleague.getName() != bidder.getName()) {
        colleague.receiveBidNotification(amount);
      }
    }
  }
}

class Bidder implements Colleague {
  String name;
  AuctionMediator auctionMediator;

  Bidder(String name, AuctionMediator auctionMediator) {
    this.name = name;
    this.auctionMediator = auctionMediator;

    auctionMediator.addBidder(this);
  }

  @Override
  public void placeBid(int amount) {
    this.auctionMediator.placeBid(this, amount);
  }

  @Override
  public void receiveBidNotification(int bidAmount) {
    System.out.println("Someone placed bid: " + bidAmount);
  }

  @Override
  public String getName() {
    return this.name;
  }
}

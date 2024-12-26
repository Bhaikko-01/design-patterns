package Observer;

/**
 * Design a Notification system where a button 'Restock alert' exists. Upon click, user will be subscribed to it
 * When restock happens, all subscribers will be notified
 */

import java.util.List;

interface NotificationAlertObserver {
  public void update();
}

interface StocksObservable {
  public void add(NotificationAlertObserver observer);

  public void remove(NotificationAlertObserver observer);

  public void notifySubscribers();

  public void setStockCount(int count);

  public int getStockCount();
}

class IPhoneObservableImpl implements StocksObservable {
  List<NotificationAlertObserver> observers;
  int count;

  public void add(NotificationAlertObserver observer) {
    observers.add(observer);
  }

  public void remove(NotificationAlertObserver observer) {
    observers.remove(observer);
  }

  public void notifySubscribers() {
    for (NotificationAlertObserver observer : observers) {
      observer.update();
    }
  }

  public void setStockCount(int count) {
    // Business logic to whether notify observers
    this.count = count;
    notifySubscribers();
  }

  public int getStockCount() {
    return 0;
  }
}

class EmailAlertObserverImpl implements NotificationAlertObserver {
  StocksObservable observable;
  String email;

  EmailAlertObserverImpl(String email, StocksObservable observable) {
    this.email = email;
    this.observable = observable;
  }

  public void update() {
    // this.observable; // Reference to object whose state updated

    // Business logic to handle Email notification
  }
}

class MobileAlertObserverImpl implements NotificationAlertObserver {
  StocksObservable observable;
  String number;

  MobileAlertObserverImpl(String number, StocksObservable observable) {
    this.number = number;
    this.observable = observable;
  }

  public void update() {
    // this.observable; // Reference to object whose state updated

    // Business logic to handle Mobile notification
  }
}

class Main {
  void main() {
    IPhoneObservableImpl iphoneObservable = new IPhoneObservableImpl();

    EmailAlertObserverImpl emailObserver1 = new EmailAlertObserverImpl("hello@world.com", iphoneObservable);
    EmailAlertObserverImpl emailObserver2 = new EmailAlertObserverImpl("hello2@world.com", iphoneObservable);
    MobileAlertObserverImpl mobileObserver1 = new MobileAlertObserverImpl("123", iphoneObservable);

    iphoneObservable.add(emailObserver1);
    iphoneObservable.add(emailObserver2);
    iphoneObservable.add(mobileObserver1);

    // This will trigger notification to all observers
    iphoneObservable.setStockCount(10);
  }
}

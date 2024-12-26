package Template;

abstract class PaymentFlow {
  abstract void validateRequest();

  abstract void calculateFees();

  abstract void debitAmount();

  // * Since this is marked final, this cannot be overridden and step sequence
  // * wont change
  public final void sendMoney() {
    validateRequest();
    validateRequest();
    debitAmount();
  }
}

class FriendPaymentFlow extends PaymentFlow {

  @Override
  void validateRequest() {
    System.out.println("Friend validate");
  }

  @Override
  void calculateFees() {
    System.out.println("Friend calculate");
  }

  @Override
  void debitAmount() {
    System.out.println("Friend debit");
  }

}

class MerchantPaymentFlow extends PaymentFlow {

  @Override
  void validateRequest() {
    System.out.println("Merchant validate");
  }

  @Override
  void calculateFees() {
    System.out.println("Merchant calculate");
  }

  @Override
  void debitAmount() {
    System.out.println("Merchant debit");
  }

}

class Main {
  void main() {
    FriendPaymentFlow friendPaymentFlow = new FriendPaymentFlow();
    friendPaymentFlow.sendMoney();

    MerchantPaymentFlow merchantPaymentFlow = new MerchantPaymentFlow();
    merchantPaymentFlow.sendMoney();
  }
}

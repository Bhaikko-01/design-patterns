package Composite;

interface Computable {
  int compute();
}

class Expression implements Computable {
  String operator;
  Computable leftExpression;
  Computable rightExpression;

  Expression(String operator, Computable leftExpression, Computable rightExpression) {
    this.operator = operator;
    this.leftExpression = leftExpression;
    this.rightExpression = rightExpression;
  }

  public int compute() {
    int leftExpressionResult = leftExpression.compute();
    int rightExpressionResult = rightExpression.compute();

    switch (operator) {
      case "+":
        return leftExpressionResult + rightExpressionResult;
      case "-":
        return leftExpressionResult - rightExpressionResult;
      case "*":
        return leftExpressionResult * rightExpressionResult;
      case "/":
        return leftExpressionResult / rightExpressionResult;
      default:
        return 0;
    }
  }
}

class Number implements Computable {
  int number;

  Number(int num) {
    this.number = num;
  }

  public int compute() {
    return this.number;
  }
}

class Main {
  void main() {
    // 2 + (3 * 4)
    Number num3 = new Number(3);
    Number num4 = new Number(4);
    Expression expression = new Expression("*", num3, num4);

    Number num2 = new Number(2);
    Expression finalExp = new Expression("+", num2, expression);

    System.out.println(finalExp);
  }
}

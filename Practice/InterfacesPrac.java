// class X {
//   public void hello() {
//     System.out.println("X hello");
//   }
// }

// class Z {
//   public void hello() {
//     System.out.println("Z hello");
//   }
// }

// class Y extends X {
//   public void hello() {
//     System.out.println("Y hello");
//   }
// }

interface Duck {
  void quack();
}

interface Fly {
  void fly();
}

class Person implements Duck, Fly {
  @Override
  public void quack() {
    System.out.println("Person quacked");
  }

  @Override
  public void fly() {
    System.out.println("Person fly");
  }
}

interface DatabaseInterface {
  String query(String queryToRun);
  // String query(String x, String y);

  // String executeTransaction();
}

class PostgresDb implements DatabaseInterface {
  @Override
  public String query(String queryToRun) {
    // PSQL
    System.out.println("Postgres Query");

    return "POstgres result";
  }

  // public String executeTransaction() {

  // }
}

class MySQLDb implements DatabaseInterface {
  @Override
  public String query(String queryToRun) {
    // PSQL
    System.out.println("MySQL Query");

    return "MySQL result";
  }

  public void hello() {

  }
}

// class SqliteDb implements DatabaseInterface {
// @Override
// public String query(String queryToRun) {
// // PSQL
// System.out.println("MySQL Query");

// return "MySQL result";
// }

// public String executeTransaction() {
// throw Exception("Not possible");
// }
// }

public class InterfacesPrac {
  public static void main(String[] args) {
    // System.out.println("hello");

    // Y y = new Y();
    // y.hello();

    // Person p = new Person();
    // p.fly();
    // p.quack();

    DatabaseInterface db = new PostgresDb();
    // DatabaseInterface db = new MySQLDb();

    // PostgresDb db = new MySQLDb();
    // db.query("hello");
  }
}

/*
 * Strategy -
 * Observer -
 * Decorator -
 * Factory, Abstract Factory
 * Chain of Responsibility
 * Proxy
 * State
 * Composite
 * Builder
 * Facade
 * Prototype
 * Singleton
 * Command
 * Iterator
 * Visitor
 * Memento
 */

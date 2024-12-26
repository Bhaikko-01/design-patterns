package Singleton;

public class DBConnection {
  private static DBConnection dbConnection;

  // * Marking Constructor as private so it cannot be called manually
  private DBConnection() {
  }

  public static DBConnection getInstance() {
    if (dbConnection == null) {
      // * Only putting lock if we have not initialised object
      synchronized (DBConnection.class) {
        // * Checking in case two threads reach this code simultaneously
        if (dbConnection == null) {
          dbConnection = new DBConnection();
        }
      }
    }

    return dbConnection;
  }

}

package State;

abstract class State {
  Player player;

  State(Player player) {
    this.player = player;
  }

  public abstract String onLock();

  public abstract String onUnlock();
}

class LockedState extends State {
  LockedState(Player player) {
    super(player);
    this.player = player;
  }

  // * Each state implementing all the methods that will be possible by this state
  // * These methods may throw exception or error as if the method is not possible
  // * on current state
  public String onLock() {
    return "Already Locked.";
  }

  public String onUnlock() {
    return "Unlocked.";
  }
}

class UnlockedState extends State {
  UnlockedState(Player player) {
    super(player);
    this.player = player;
  }

  public String onLock() {
    return "Locked.";
  }

  public String onUnlock() {
    return "Already Unlocked.";
  }
}

class Player {
  State state;

  Player() {
    this.state = new LockedState(this);
  }

  public void changeState(State state) {
    this.state = state;
  }
}

class Main {
  void main() {
    Player player = new Player();

    player.state.onUnlock();
  }
}

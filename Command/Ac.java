package Command;

import java.util.Stack;

interface ICommand {
  void execute();

  void undo();
}

public class Ac {
  boolean isOn;

  Ac() {
    this.isOn = false;
  }

  public void turnOn() {
    this.isOn = true;
  }

  public void turnOff() {
    this.isOn = false;
  }
}

class AcTurnOffCommand implements ICommand {
  Ac ac;

  AcTurnOffCommand(Ac ac) {
    this.ac = ac;
  }

  public void execute() {
    this.ac.turnOn();
  }

  public void undo() {
    this.ac.turnOff();
  }
}

class AcTurnOnCommand implements ICommand {
  Ac ac;

  AcTurnOnCommand(Ac ac) {
    this.ac = ac;
  }

  public void execute() {
    this.ac.turnOff();
  }

  public void undo() {
    this.ac.turnOn();
  }
}

class AcInvoker {
  Stack<ICommand> acCommandHistory = new Stack<ICommand>();
  ICommand command;

  AcInvoker(ICommand command) {
    this.command = command;
  }

  public void setCommand(ICommand command) {
    this.command = command;
  }

  public void pressButton() {
    command.execute();
    acCommandHistory.push(command);
  }

  public void undo() {
    if (acCommandHistory.empty()) {
      return;
    }

    ICommand lastCommand = acCommandHistory.pop();
    lastCommand.undo();
  }
}

class Main {
  void main() {
    Ac ac = new Ac();

    ICommand offCommand = new AcTurnOffCommand(ac);
    ICommand onCommand = new AcTurnOnCommand(ac);

    AcInvoker acInvoker = new AcInvoker(onCommand);

    acInvoker.pressButton();

    acInvoker.setCommand(offCommand);
    acInvoker.pressButton();
    acInvoker.undo();
  }
}

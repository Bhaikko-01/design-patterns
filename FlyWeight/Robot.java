package FlyWeight;

import java.util.HashMap;

interface Displayable {
  void display(int x, int y);
}

class Sprite {
}

public class Robot implements Displayable {
  // * Intrinsic data that will be reused
  String type;
  Sprite sprite;

  Robot(String type, Sprite sprite) {
    this.sprite = sprite;
    this.type = type;
  }

  // * Keeping extrinsic data outside class
  public void display(int x, int y) {
    System.out.println(String.format("Displaying on (%d, %d)", x, y));
  }
}

class RobotFactory {
  public static final String HUMAN_ROBOT_TYPE = "HUMAN_ROBOT";
  public static final String DOG_ROBOT_TYPE = "DOG_ROBOT";

  static HashMap<String, Robot> robotsMap = new HashMap<String, Robot>();

  static Robot getRobot(String type) {
    if (robotsMap.containsKey(type)) {
      return robotsMap.get(type);
    }

    switch (type) {
      case HUMAN_ROBOT_TYPE: {
        Sprite humanSprite = new Sprite();
        Robot robot = new Robot(HUMAN_ROBOT_TYPE, humanSprite);

        robotsMap.put(type, robot);
        return robot;
      }
      case DOG_ROBOT_TYPE: {
        Sprite humanSprite = new Sprite();
        Robot robot = new Robot(DOG_ROBOT_TYPE, humanSprite);

        robotsMap.put(type, robot);
        return robot;
      }
      default:
        return null;
    }
  }
}

class Main {
  void main() {
    Robot humanRobot1 = RobotFactory.getRobot(RobotFactory.HUMAN_ROBOT_TYPE);
    humanRobot1.display(1, 1);

    Robot humanRobot2 = RobotFactory.getRobot(RobotFactory.HUMAN_ROBOT_TYPE);
    humanRobot2.display(1, 1);

    Robot dogRobot2 = RobotFactory.getRobot(RobotFactory.DOG_ROBOT_TYPE);
    dogRobot2.display(1, 1);
  }
}

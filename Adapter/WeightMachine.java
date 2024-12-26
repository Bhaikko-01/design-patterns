package Adapter;

public interface WeightMachine {
  public double getWeightInPounds();
}

class WeightMachineForBabies implements WeightMachine {
  public double getWeightInPounds() {
    return 10;
  }
}

interface WeightMachineAdapter {
  public double getWeightInKgs();
}

class WeightMachineAdapterImpl implements WeightMachineAdapter {
  WeightMachine weightMachine;

  WeightMachineAdapterImpl(WeightMachine weightMachine) {
    this.weightMachine = weightMachine;
  }

  public double getWeightInKgs() {
    double weightInPounds = weightMachine.getWeightInPounds();

    return weightInPounds * 0.45;
  }
}

class Main {
  void main() {
    WeightMachineAdapter weightMachineAdapter = new WeightMachineAdapterImpl(new WeightMachineForBabies());

    System.out.println(weightMachineAdapter.getWeightInKgs());
  }
}

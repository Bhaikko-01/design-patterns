package Strategy;

/**
 * Design a Vehicle system where two sub classes can have same functionality
 * which does not exist in parent class
 */

// Defining strategies which will have shareable code among children
interface DriveStrategy {
	void drive();
}

class NormalDriveStrategy implements DriveStrategy {
	public void drive() {
		// Business Logic for Normal Driving
	};
}

class SpecialDriveStrategy implements DriveStrategy {
	public void drive() {
		// Business Logic for Special Driving
	};
}

class Vehicle {
	DriveStrategy driveStrategy;

	Vehicle(DriveStrategy _ds) {
		this.driveStrategy = _ds;
	}

	void drive() {
		this.driveStrategy.drive();
	}
}

class OffRoadVehicle extends Vehicle {
	OffRoadVehicle() {
		super(new SpecialDriveStrategy());
	}
}

class NormalVehicle extends Vehicle {
	NormalVehicle() {
		super(new NormalDriveStrategy());
	}

}

class Main {
	// Similary third base class of Vehicle class can be created which can share
	// code with other children of Vehicle
	void main() {
		OffRoadVehicle offroadVehicle = new OffRoadVehicle();
		offroadVehicle.drive();

		NormalVehicle normalVehicle = new NormalVehicle();
		normalVehicle.drive();
	}

}

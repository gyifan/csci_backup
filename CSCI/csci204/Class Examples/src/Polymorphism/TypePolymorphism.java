package Polymorphism;

import Abstract.Vehicle;
import Inheritance.Car;
import Inheritance.Sedan;
import Interface.FourWheelDrive;
import Interface.Jeep;

public class TypePolymorphism {

	public void example() {
		// example with inheritance
		Car c = new Sedan(); // Car is the parent of Sedan
		// Sedan s = new Car(); // not allowed
		Sedan s2 = (Sedan) new Car(); // s2 is a Sedan and may have gained features and methods.
		
		// example with interfaces
		FourWheelDrive fwd = new Jeep(); // FourWheelDrive is an interface
		// Any class which implement FourWheelDrive could have been used here
		
		// example with abstract
		Vehicle v = new Abstract.Car(); // The Car extends the abstract Vehicle
		// I only needed the "Abstract." part because I also used the Car from the Inheritance package.
	}
}

package Polymorphism;

import Inheritance.Car;
import Inheritance.Sedan;

public class ArrayPolymorphism {
	
	// The array must be of the parent type but can contain parents or children.
	public void example() {
		Car[] cars = new Car[3];
		cars[0] = new Car();
		cars[1] = new Sedan();
		
		Sedan[] sedans = new Sedan[2];
		sedans[0] = new Sedan();
		// sedans[1] = new Car(); 
		// A child array cannot contain a parent because the children are more than the
		// parents
	}
}

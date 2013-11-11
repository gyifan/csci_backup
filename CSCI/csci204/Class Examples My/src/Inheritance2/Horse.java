package Inheritance2;
import Inheritance.Car;

/*
 * This class demonstrates how protected limits access to 
 * member data. In general, it is bad practice to have 
 * protected member data. Use public or private.
 */
public class Horse {
	public void example() {
		Car c = new Car();	
		// c.mDoors = null; // cannot access protected member data in a different package
	}
}

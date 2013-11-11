package Inheritance;

public class Buggy {
	public void example() {
		Car c = new Car();	
		c.mDoors = null; // can access protected member data in the same package
	}
}
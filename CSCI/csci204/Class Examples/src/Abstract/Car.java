package Abstract;

/*
 * This class extends an abstract class so it must implement all the abstract methods
 */
public class Car extends Vehicle {

	// Car must implement the drive method.
	public void drive() { System.out.println("vroom"); }
	
	public void example() {
		Vehicle v;
		// v = new Vehicle(); // Cannot make an instance of an abstract class
	}
}

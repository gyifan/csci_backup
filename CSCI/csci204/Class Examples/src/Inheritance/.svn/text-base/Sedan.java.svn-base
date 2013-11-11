package Inheritance;


/* 
 * This class inherits all of the member data (instance variables and 
 * static variables) and methods of the Car class. Inheritance covers 
 * what member data the Sedan can access directly. example2 shows how 
 * to access the private member data using accessor and mutator methods.
 */
public class Sedan extends Car {
	public void example() {
			//mEngine = null; // cannot directly access private member data
			mDoors = null; // can access protected member data
			mRadio = null; // can access public member data
	}
	public void example2() {
		makeEngine();
		System.out.println(getPlug());
	}
}

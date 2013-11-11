package Inheritance;

/*
 * A class
 * 
 * See the Sedan in this package and the Convertible in the Inheritance2 package for examples of 
 * inheriting this class.
 */
public class Car {
	private Engine mEngine;
	protected Door[] mDoors;
	public Radio mRadio;
	
	public void makeEngine() { mEngine = new Engine(); }
	public int getPlug() { return mEngine.getPlug(); }
	
	public void example() {
			mEngine = new Engine();
			System.out.println(mEngine.getPlug());
	}
}

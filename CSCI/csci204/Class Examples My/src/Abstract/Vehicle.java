package Abstract;

import Inheritance.Radio;

/*
 * An abstract class
 * 
 * Because this class is abstract, it cannot be instantiated.
 */
public abstract class Vehicle {
  public Radio mRadio; // This will be inherited by child classes
  
  public abstract void drive(); // must be implemented by child classes
  
  public void turnOnRadio() { // Inherited by all child classes
	  mRadio = new Radio();
  }
}

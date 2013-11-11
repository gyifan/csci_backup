/**
 * CSCI 203, Yifan Ge
 * Oct 5, 2010, 10:10:33 AM
 */

/**
 * This class can count numbers.
 * 
 * @author Yifan Ge
 * 
 */
public class Clicker {

	// instance fields

	private int count;

	/**
	 * Constructs a clicker starting at 0.
	 */
	public Clicker() {
		count = 0;
	}

	/**
	 * Adds one to the clicker.
	 */
	public void increment() {
		count = count + 1;
	}

	/**
	 * Resets clicker to 0.
	 */
	public void reset() {
		count = 0;
	}

	/**
	 * Returns the clicker value.
	 * 
	 * @return the clicker value
	 */
	public int getValue() {
		return count;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return "" + count;
	}

	/**
	 * Tests the constructor and methods in Clicker class.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.print("Testing the default constructor: ");
		Clicker c = new Clicker();
		System.out.println(c);
		System.out.println("Expected: 0\n");

		System.out.print("Testing the increment method: ");
		c.increment();
		System.out.println(c);
		System.out.println("Expected: 1\n");

		System.out.print("Testing the reset method: ");
		c.reset();
		System.out.println(c);
		System.out.println("Expected: 0\n");

		System.out.print("Testing the getters: ");
		System.out.println(c.getValue());
		System.out.println("Expected: 0\n");

		System.out.print("Testing the toString method: ");
		System.out.println(c.toString());
		System.out.println("Expected: 0\n");
	}
}

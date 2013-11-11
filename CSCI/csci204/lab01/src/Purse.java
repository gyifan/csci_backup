/**
 * CSCI 204, Yifan Ge
 * Assiangment lab01
 * Created: &{date}, 10:43:29 AM
 */

/**
 * This class represents a coin purse
 * 
 * @author Yifan Ge
 * 
 */
public class Purse {

	// instance fields

	int numNickels;
	int numDimes;
	int numQuaters;

	/**
	 * Constructs a Purse object.
	 */
	public Purse() {
		numNickels = 0;
		numDimes = 0;
		numQuaters = 0;
	}

	/**
	 * Adds nickels to the purse.
	 * 
	 * @param numOfAdd
	 *            the number of nickels to add
	 */
	public void addNickels(int numOfAdd) {
		numNickels += numOfAdd;
	}

	/**
	 * Adds dimes to the purse
	 * 
	 * @param numOfAdd
	 *            the number of dimes to add
	 */
	public void addDimes(int numOfAdd) {
		numDimes += numOfAdd;
	}

	/**
	 * Adds quarters to the purse.
	 * 
	 * @param numOfAdd
	 *            the number of quarters to add
	 */
	public void addQuarters(int numOfAdd) {
		numQuaters += numOfAdd;
	}

	/**
	 * Gets the total number of coins in the purse.
	 * 
	 * @return the total number of coins in the purse
	 */
	public double getTotal() {
		return 0.05 * numNickels + 0.1 * numDimes + 0.25 * numQuaters;
	}

	/**
	 * Tests the constructor and methods.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Purse myPurse = new Purse();
		myPurse.addNickels(3);
		myPurse.addDimes(1);
		myPurse.addQuarters(2);
		double totalValue = myPurse.getTotal();
		System.out.print(" The total is $");
		System.out.println(totalValue);

	}
}

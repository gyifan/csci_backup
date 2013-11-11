/**
 * BankAccount.java
 * 
 * 
 * Created: Spring 2005 for CSCI 204 Modified: Spring 2006 Fall 2006 We now
 * actually implement the full class, rather than a skeleton.
 * 
 * @author csci 204 instructor, modified by Xiannong Meng, Shane Markstrum
 * @version 1.3
 */
public class BankAccount {
	private double balance;
	private String name;
	private int accountNumber;

	/**
	 * Creates a new instance of BankAccount. Default constructor.
	 * 
	 */
	public BankAccount() {
		balance = 0.0;
		accountNumber = -1;
		name = "";
	}

	/**
	 * Creates a new instance of BankAccount. Alternate constructor.
	 * 
	 * @param amount
	 *            is the amount in the initial account
	 * @param accountOwner
	 *            is the name of the account owner
	 * 
	 */
	public BankAccount(double amount, String accountOwner) {
		balance = amount;
		name = accountOwner;
	}

	/**
	 * 
	 * Returns the current balance of the account
	 * 
	 * @return the account balance
	 */
	public double getBalance() {
		return balance;
	}

	/**
	 * 
	 * Returns the owner of the account
	 * 
	 * @return the owner name of the account
	 */
	public String getName() {
		return name;
	}

	/**
	 * 
	 * Deducts the amount specified by the parameter from the account.
	 * 
	 * @param amount
	 *            is the amount to withdraw
	 */
	public void withdraw(double amount) {
		if (amount <= balance)
			balance -= amount;
	}

	/**
	 * 
	 * Adds the amount specified by the parameter from the account.
	 * 
	 * @param amount
	 *            the amount to deposit
	 * 
	 */
	public void deposit(double amount) {
		balance += amount;
	}

	/**
	 * 
	 * Sets the account number to be the specified value.
	 * 
	 * @param accountNumber
	 *            the desired account number
	 * 
	 */
	public void setAccountNumber(int accountNumber) {
		this.accountNumber = accountNumber;
	}

	/**
	 * 
	 * Gets the account number.
	 * 
	 * @return the account number
	 * 
	 */
	public int getAccountNumber() {
		return accountNumber;
	}

	/**
	 * Prints the a confirmation message to the user which includes the provided
	 * address.
	 * 
	 * @param addr
	 */
	public void requestStatement(Address addr) {
		System.out.print("Name: " + name + "\nBalance: " + balance + "\n"
				+ addr);
	}

	/**
	 * Tests the BankAccount class
	 * 
	 * @param argv
	 *            command line arguments
	 */
	public static void main(String[] argv) {

		BankAccount myAccountA = new BankAccount(100, "Steve Jobs");
		BankAccount myAccountB = new BankAccount(50, "Bill Gates");

		System.out.println(" Test getName(): It should be Bill Gates...");
		System.out.println(" The test result is: " + myAccountB.getName());
		System.out.println(" Test getBalance(): The balance should be 100... ");
		System.out.println(" The test result is: " + myAccountA.getBalance());
		System.out.println(" Test deposit(): deposit 1000.45 into account A");
		myAccountA.deposit(1000.45);
		System.out.println(" Test getBalance() after deposit: "
				+ " The result should be 1100.45... ");
		System.out.println(" The test result is " + myAccountA.getBalance());
		System.out.println(" Test withdraw(): withdraw 345.67 from account A");
		myAccountA.withdraw(345.67);
		System.out.println(" Test getBalance() after withdraw: "
				+ " The result should be 754.78... ");
		System.out.println(" The test result is " + myAccountA.getBalance());
	}

	// Add a new method requestStatement that takes an Address and prints
	// the address and a conformation message to the user.

}

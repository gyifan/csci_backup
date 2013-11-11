/**
 * CSCI 203, Yifan Ge
 * Sep 28, 2010, 11:26:41 AM
 */

/**
 * @author ygg001
 * 
 */

public class SavingsAccount {

	// instance fields (instance variables)

	private double interestRate;
	private double balance;

	/**
	 * Constructs a bank account with a zero interestRate
	 * 
	 */
	public SavingsAccount() {
		interestRate = 0;
	}

	/**
	 * Constructs a bank account with a given balance and interestRate
	 * 
	 * @param iniBalance
	 *            the initial balance
	 * @param intRate
	 *            the initial interest Rate
	 */
	public SavingsAccount(double iniBalance, double intRate) {
		balance = iniBalance;
		interestRate = intRate;
	}

	/**
	 * Deposits money into the bank account
	 * 
	 * @param amount
	 *            the amount to deposit
	 */
	public void deposit(double amount) {
		balance = balance + amount;
	}

	/**
	 * Withdraws money from the bank account
	 * 
	 * @param amount
	 *            the amount to withdraw
	 */
	public void withdraw(double amount) {
		balance = balance - amount;
	}

	public void addInterest() {
		double interest = balance * interestRate / 100.0;
		balance = balance + interest;
	}

	/**
	 * Gets the current balance of the bank account
	 * 
	 * @return the current balance
	 */
	public double getBalance() {
		return balance;
	}
}
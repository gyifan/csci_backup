/**
 * CSCI 203, Yifan Ge
 * Sep 28, 2010, 11:50:17 AM
 */

/**
 * @author ygg001
 * 
 */
public class SavingsAccountTester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SavingsAccount account = new SavingsAccount(1000, 10);
		account.addInterest();
		account.addInterest();
		account.addInterest();
		account.addInterest();
		account.addInterest();

		System.out.println("Balance:  " + account.getBalance());
		System.out.println("Expected: 1610.51");

	}

}

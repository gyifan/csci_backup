import javax.swing.JOptionPane;

/**
 * CSCI 203, Yifan Ge
 * Nov 19, 2010, 6:09:40 PM
 */

/**
 * This Class uses array for bankAccount
 * 
 * @author Yifan Ge
 * 
 */
public class Bank {

	/**
	 * Puts accounts in an array and print them with the account with largest
	 * amount
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		BankAccount[] accounts = new BankAccount[100];
		// System.out.println(accounts[0]);
		// accounts[0] = new BankAccount("Account[0]", 100);
		// System.out.println(accounts[0].getName());
		// System.out.println(accounts[0]);
		int element = 0;
		String accountAmount = null;
		String accountName = JOptionPane
				.showInputDialog("Please enter the name of the account: ");
		if (accountName != null) {
			accountAmount = JOptionPane
					.showInputDialog("Please enter the initial amount of money: ");
		}
		while (accountName != null && accountAmount != null) {
			accounts[element] = new BankAccount(accountName, Double
					.parseDouble(accountAmount));
			System.out.println(accounts[element]);
			accountName = JOptionPane
					.showInputDialog("Please enter the name of the account: ");
			if (accountName != null) {
				accountAmount = JOptionPane
						.showInputDialog("Please enter the initial amount of money: ");
			}
			element++;
		}
		int largestAccount = 0;
		for (int i = 0; i < element; i++) {
			if (accounts[largestAccount].getBalance() < accounts[i]
					.getBalance())
				largestAccount = i;
		}
		System.out.println("The Account with the largest balance: "
				+ accounts[largestAccount]);
	}
}

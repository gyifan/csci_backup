/**
 * The BankAccount class simulates a simple bank account.
 *
 * @author Dan Hyde
 *
 */
public class BankAccount {
    private double balance;
    private String name;

    /**
     * Sets the starting balance to 0.0 and name to "UNKNOWN".
     */
    public BankAccount() {
        balance = 0.0;
        name = "UNKNOWN";
    }

    /**
     * Sets the starting balance and name to the values passed as arguments.
     *
     * @param startBalance
     *            The starting balance.
     * @param inName
     *            The name for the bank account
     */

    public BankAccount(String inName, double startBalance) {
        balance = startBalance;
        name = inName;
    }

    /**
     * Deposits amount into the account.
     *
     * @param amount
     *            The amount to add to the balance field.
     */
    public void deposit(double amount) {
        balance += amount;
    }

    /**
     * Withdraws amount from the account.
     *
     * @param amount
     *            The amount to subtract from the balance field.
     */

    public void withdraw(double amount) {
        balance -= amount;
    }

    /**
     * Sets the account balance.
     *
     * @param inBalance
     *            The value to store in the balance field.
     */

    public void setBalance(double inBalance) {
        balance = inBalance;
    }

    /**
     * Gets the account balance.
     *
     * @return The value in the balance field.
     */
    public double getBalance() {
        return balance;
    }

    /**
     * Gets the account owner's name.
     *
     * @return the name of the owner
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the owner's name of the account.
     *
     * @param newName
     *            the new name of the owner
     */
    public void setName(String newName) {
        name = newName;
    }

    /**
     * Return String representation of BankAccount object.
     *
     * @see java.lang.Object#toString()
     */
    public String toString() {
        return "Name: " + name + ", Balance: $"
                + String.format("%.2f", balance);
    }

    /**
     * Test the BankAccount class.
     *
     * @param args unused
     */
    public static void main(String[] args) {

        System.out
                .println("Testing the BankAccount default constructor and toString");
        BankAccount account1 = new BankAccount();
        System.out.println("account1: " + account1);
        System.out.println("Expected: Name: UNKNOWN, Balance: $0.00");
        System.out.println();

        System.out.println("Testing the BankAccount 2 parameter constructor");
        BankAccount account2 = new BankAccount("Harry Potter", 980);
        System.out.println("account2: " + account2);
        System.out.println("Expected: Name: Harry Potter, Balance: $980.00");
        System.out.println();

        System.out.println("Testing the setters and getters");
        BankAccount account3 = new BankAccount();
        account3.setName("Ron Weasley");
        account3.setBalance(9.17);
        System.out.println("account3: " + account3.getName() + ":"
                + account3.getBalance());
        System.out.println("Expected: Ron Weasley:9.17");
        System.out.println();

        System.out.println("Testing the withdraw and deposit methods");
        double loan = 20.20;
        account2.withdraw(loan);
        account3.deposit(loan);
        System.out.println("account2: " + account2);
        System.out.println("Expected: Name: Harry Potter, Balance: $959.80");
        System.out.println("account3: " + account3);
        System.out.println("Expected: Name: Ron Weasley, Balance: $29.37");
        System.out.println();
    }
}

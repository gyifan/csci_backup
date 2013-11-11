/**
 * A cash register totals up sales and computes change due.
 */
public class CashRegister implements Comparable<CashRegister> {
	private double purchase;
	private double payment;
	private String name;

	/**
	 * Constructs a cash register with no money in it.
	 * 
	 * @param name
	 *            the name of the register
	 */
	public CashRegister(String name) {
		purchase = 0;
		payment = 0;
		this.name = name;
	}

	/**
	 * Records the sale of an item.
	 * 
	 * @param amount
	 *            the price of the item. Precondition: amount >= 0
	 */
	public void recordPurchase(double amount) {
		if (amount < 0.0)
			throw new IllegalArgumentException();
		purchase += amount;
	}

	/**
	 * Enters the payment received from the customer; should be called once for
	 * each monetary unit type
	 * 
	 * @param unitCount
	 *            the number of monetary units
	 * @param type
	 *            the type of the monetary units in the payment
	 */
	public void enterPayment(int unitCount, Money type) {
		if (unitCount < 0)
			throw new IllegalArgumentException();
		payment += unitCount * type.getValue();
	}

	/**
	 * Gets the purchase
	 * 
	 * @return the purchase
	 */
	public double getPurchase() {
		return purchase;
	}

	/**
	 * Sets the purchase
	 * 
	 * @param purchase
	 *            the purchase to set
	 */
	public void setPurchase(double purchase) {
		this.purchase = purchase;
	}

	/**
	 * Gets the payment
	 * 
	 * @return the payment
	 */
	public double getPayment() {
		return payment;
	}

	/**
	 * Sets the payment
	 * 
	 * @param payment
	 *            the payment to set
	 */
	public void setPayment(double payment) {
		this.payment = payment;
	}

	/**
	 * Computes the change due and resets the machine for the next customer.
	 * 
	 * @return the change due to the customer
	 */
	public double giveChange() {
		double change = payment - purchase;
		purchase = 0;
		payment = 0;
		return change;
	}

	/**
	 * Gets the name
	 * 
	 * @return the name
	 */
	public String getName() {
		return name;
	}

	/**
	 * Sets the name
	 * 
	 * @param name
	 *            the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * Compares the lexicographic ordering of the names of the two registers.
	 * 
	 * @param anotherRegister
	 * @return the lexicographic order of the names
	 */
	public int compareTo(CashRegister anotherRegister) {
		return name.compareTo(anotherRegister.getName());
	}

	/**
	 * Checks if the two cash register are equal
	 * 
	 * @param anotherRegister
	 * @return whether the two cash register is equal
	 */
	public boolean equals(CashRegister anotherRegister) {
		return (payment == anotherRegister.getPayment())
				&& (purchase == anotherRegister.getPurchase())
				&& (name.equals(anotherRegister.getName()));
	}
}

/**
 * Person.java
 *
 * @author Xiannong Meng
 * @version 1.0, 01/13/06
 * @version 2.0 2008-01-26 Rick Zaccone
 *
 */
public class Person {
    private String name;
    private Address address;
    private String phoneNumber;
    private String id;
    private BankAccount bankAccount;

    /**
     * Initialze a Person
     *
     * @param name
     *            the account owner's name
     * @param address
     *            the account owner's address
     * @param phoneNumber
     *            phone number
     * @param id
     *            account id
     * @param amount
     *            initial balance
     *
     */
    public Person(String name, Address address, String phoneNumber, String id,
            double amount) {
        this.name = name;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.id = id;
        bankAccount = new BankAccount(amount, this.name);
    }

    /**
     * Returns the address field
     *
     * @return the address
     */
    public Address getAddress() {
        return address;
    }

    /**
     * Gets the person's phone number
     *
     * @return a phone number
     */
    public String getPhoneNumber() {
        return phoneNumber;
    }

    /**
     * Get's the person's bank account id.
     *
     * @return an id
     */
    public String getId() {
        return id;
    }

    /**
     * Gets the person's balance.
     *
     * @return the bank account balance
     */
    public double queryBalance() {
        return bankAccount.getBalance();
    }

    /**
     * Deposits money in the person's bank account
     *
     * @param amount
     *            the amount to deposit
     */
    public void depositMoney(double amount) {
        bankAccount.deposit(amount);
    }

    /**
     * Changes a person's address
     *
     * @param newAddress
     *            the new address
     */
    public void changeAddress(Address newAddress) {
        address.setStreet(newAddress.getStreet());
        address.setCity(newAddress.getCity());
        address.setState(newAddress.getState());
        address.setZipCode(newAddress.getZipCode());
    }

    /**
     * Sets the person's id.
     *
     * @param newID
     *            the new id
     */
    public void setId(String newID) {
        id = newID;
    }

    /**
     * Sets the person's phone number
     *
     * @param phoneNumber
     *            the new phone number
     */
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    /**
     * Tests the person class
     *
     * @param argv
     *            command line arguments
     */
    public static void main(String[] argv) {
        Address myAddr = new Address("123 Sesame Street", "Park City", "PA",
                "17837");
        Person myPerson = new Person("Joe Smith", myAddr, "577-1214",
                "1234567", 100);

        System.out.println(" testing the address ... ");
        System.out.println(myAddr);
        System.out.println(" testing getPhoneNumber ... ");
        System.out.println(" the number is " + myPerson.getPhoneNumber());
        System.out.println(" testing getId ...");
        System.out.println(" the id is " + myPerson.getId());
        System.out.println(" testing queryBalace ...");
        System.out
                .println(" the amount of money is " + myPerson.queryBalance());
        System.out.println(" testing depositMoney ... ");
        System.out.println(" putting money into the bank ...");
        myPerson.depositMoney(200);
        System.exit(0);
    }
}

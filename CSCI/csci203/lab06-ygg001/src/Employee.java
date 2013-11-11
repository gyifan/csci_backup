/**
 * CSCI 203, Yifan Ge
 * Oct 5, 2010, 11:02:32 AM
 */

/**
 * This class contains the constructor and methods for calculate employees'
 * salaries
 * 
 * @author Yifan Ge
 * 
 */
public class Employee {

	// instance fields

	private String employeeName;
	private double salary;

	/**
	 * Contructs an Employee object.
	 * 
	 * @param employeeName
	 *            the employee's name
	 * @param currentSalary
	 *            the employee's current salary
	 */
	public Employee(String employeeName, double currentSalary) {
		this.employeeName = employeeName;
		salary = currentSalary;
	}

	/**
	 * Gets the employee's name.
	 * 
	 * @return the employee's name
	 */
	public String getName() {
		return employeeName;
	}

	/**
	 * Gets the employee's current salary.
	 * 
	 * @return the employee's current salary.
	 */
	public double getSalary() {
		return salary;
	}

	/**
	 * Raises the employee's salary by a certain percentage.
	 * 
	 * @param byPercent
	 *            the percentage of the raise
	 */
	public void raiseSalary(double byPercent) {
		salary = salary * (1.0 + byPercent / 100.0);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return employeeName + "'s salary is $" + salary;
	}

	/**
	 * Tests the constructor and methods.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.print("Testing the constructor: ");
		Employee harryPotter = new Employee("Harry Potter", 1000.00);
		Employee ronWeasley = new Employee("Ron Weasley", 200.00);
		System.out.println(harryPotter.toString() + "; "
				+ ronWeasley.toString() + ".");
		System.out
				.println("Expected: Harry Potter's salary is $1000.00; Ron Weasley's salary is $200.00.\n");

		System.out.print("Testing the getters: ");
		System.out.println("The salary of " + harryPotter.getName() + " is $"
				+ harryPotter.getSalary() + "; " + "the salary of "
				+ ronWeasley.getName() + " is " + ronWeasley.getSalary() + ".");
		System.out
				.println("Expected: The salary of Harry Potter is $1000.00; the salary of Ron Weasley is $200.00.\n");

		System.out.print("Testing raiseSalary method: ");
		harryPotter.raiseSalary(10);
		ronWeasley.raiseSalary(5);
		System.out.println(harryPotter.toString() + "; "
				+ ronWeasley.toString() + ".");
		System.out
				.println("Expected: Harry Potter's salary is $1100.00; Ron Weasley's salary is $210.00.\n");
	}
}

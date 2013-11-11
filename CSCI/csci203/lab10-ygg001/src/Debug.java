import java.util.Scanner;

/**
 * Program to practice finding logic errors.
 * 
 * @author Dan Hyde
 * 
 */
public class Debug {

	/**
	 * Allows the user to enter a value for n then sums the values from 1 to n.
	 * It compiles and runs BUT it contains logic errors!
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		int n = 0;
		int k = 1;
		int sum = 0;

		System.out.print("Enter value for n: ");
		n = keyboard.nextInt();

		// System.out.println("n = " + n);
		while (k <= n) {
			sum = sum + k;
			// System.out.println("k= " + k);
			k++;
		}

		System.out.println("The sum of the integers from 1 to " + n + " is "
				+ sum);
	}
}

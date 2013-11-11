import java.util.Scanner;

/**
 * <code>TestFactorial</code> driver class for the Factorial class.
 * 
 * @author <a href="mailto:xmeng@bucknell.edu">Meng Xiannong</a>
 * @author other csci204 instructors.
 * @version 1.1 revised 02/01/2006
 */
public class TestFactorial {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n;
		long fact = 0;
		long odds = 0;
		do {
			try {
				System.out.print("Enter an integer: ");
				n = input.nextInt();
				fact = Factorial.factorial(n);
			} catch (DomainException e) {
				System.out.println(e.getMessage());
				fact = 0;
			}
		} while (fact == 0);

		System.out.println("The factorial is : " + fact);

		do {
			try {
				System.out.print("Enter an integer: ");
				n = input.nextInt();
				odds = Factorial.addOddInts(n);

			} catch (DomainException e) {
				System.out.println(e.getMessage());
				odds = 0;
			}
		} while (odds == 0);
		System.out.println(odds);
	}
}

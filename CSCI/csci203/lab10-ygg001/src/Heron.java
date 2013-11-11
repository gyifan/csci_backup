import java.util.Scanner;

/**
 * CSCI 203, Yifan Ge
 * Nov 10, 2010, 10:50:58 PM
 */

/**
 * This class approximates the value of a square root
 * 
 * @author Yifan Ge
 * 
 */
public class Heron {
	private static final double EPSILON = 1E-6;

	/**
	 * Approximates the value of a square root
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Please enter a number: ");
		double a = input.nextDouble();
		double x = 1.0;
		double nextGeneratedGuess = (x + a / x) / 2;
		while (!(Math.abs(x - nextGeneratedGuess) < EPSILON)) {
			x = nextGeneratedGuess;
			nextGeneratedGuess = (x + a / x) / 2;
		}
		System.out.printf(
				"The approximation of the square root of %.1f is %.7f.", a, x);
	}
}

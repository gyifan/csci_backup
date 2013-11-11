/**
 * CSCI 203, Yifan Ge
 * Oct 12, 2010, 10:21:03 AM
 */

/**
 * This class does some test with Mathematics class.
 * 
 * @author Yifan Ge
 * 
 */
public class TestMath {

	/**
	 * Tests Mathematics class
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {

		// Exercise 1

		int i = 987654321 * 1000;
		System.out.println("i value is " + i);
		System.out.println("Expected value is 987654321000");

		double x = 987654321.0 * 1000.0;
		System.out.println("x value is " + x);
		System.out.println("Expected value is 987654321000.0\n");

		// Exercise 2

		double f = 4.35 * 100.0;
		System.out.println("f value is " + f);
		System.out.println("Expected value is 435.0\n");

		// Exercise 3

		int j = 435;
		double y = j;
		System.out.println("y value is " + y);
		System.out.println("Expected value is 435.0\n");

		// Exercise 4

		i = (int) f;
		System.out.println("i value is " + i);
		System.out.println("Expected value is 435\n");

		// Exercise 5

		double squareRoot2 = Math.sqrt(2);
		double squareOfSquareRoot2 = Math.pow(squareRoot2, 2);
		System.out.println("the square of squareroot 2 is "
				+ squareOfSquareRoot2);
		System.out.println("Expected value is 2\n");

		long roundF = Math.round(f);
		System.out.println("The rounded value of f is " + roundF);
		System.out.println("Expected value is 435\n");

		// Exercise 6

		int testPrintf = 1234567;
		System.out.printf("Testing printf: %,d\n", testPrintf);
		System.out.println("Expected:       1,234,567");
	}
}

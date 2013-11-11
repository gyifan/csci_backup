// Program to practice with programming errors

public class ErrorTest2 {
	public static void main(String[] args) {

		// A string constant MUST have DOUBLE quotes.

		String s1 = "CSCI 203 ";
		String s2 = "is fun!";

		System.out.print(s1);
		System.out.println(s2);

		// The + means concatenation

		String s3 = s1 + s2;

		System.out.println(s3);

		// Notice two uses of + sign

		int a = 1 + 2;

		System.out.println("a is " + a);

		// Use a built-in function for raising a number to a power.
		// Math.pow(2.0, 4.0); should return 16.0

		double b = Math.sqrt(2.0);
		// double b = Math.pow(2.0, 4.0);

		System.out.println("b is " + a);
	}
}

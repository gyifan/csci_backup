package Exceptions;

public class MultipleExceptions2 {
	public static void main(String[] args) {
		// Another way to trap multiple exceptions at once
		try {
			// comment out the first bad line to see the second one run
			int x = 2 / 0;
			int[] array = new int[-3];
		} catch (ArithmeticException e) {
			System.out.println("ArithmeticException");
		} catch (NegativeArraySizeException e) {
			System.out.println("NegativeArraySizeException");
		}
	}
}

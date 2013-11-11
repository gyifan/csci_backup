package Exceptions;

public class MultipleExceptions {
	public static void main(String[] args) {
		// Trapping multiple exceptions at once
		try {
			// int x = 2 / 0;
			int[] array = new int[-3];
		} catch (Exception e) {
			// NegativeArraySizeException or ArithmeticException
			System.out.println(e);
		}
	}
}

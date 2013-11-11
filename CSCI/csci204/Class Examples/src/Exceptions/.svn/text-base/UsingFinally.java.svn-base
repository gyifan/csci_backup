package Exceptions;

public class UsingFinally {
	public static void main(String[] args) {
		// Running a block afterwards reguardless of exceptions
		try {
			// The top one is handled here and then finally runs

			// Comment out the top one to see the unhandled one use finally
			// before it is passed onwards

			// Comment out both to still see finally run.
			// int x = 2 / 0;
			int[] array = new int[-3];
		} catch (ArithmeticException e) {
			System.out.println("Handling exception");
		} finally {
			System.out.println("The finally block");
		}
		System.out.println("aarrgghh");
	}
}

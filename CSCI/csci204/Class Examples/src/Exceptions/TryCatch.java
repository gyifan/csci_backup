package Exceptions;

public class TryCatch {
	public static void main(String[] args) {
		// What information can we get out of an exception?
		try {
			int x = 2 / 0; // the old faithful divide by zero error
		} catch (ArithmeticException e) {
			// System.out.println(e.getMessage());
			// / by zero

			// System.out.println(e);
			// java.lang.ArithmeticException: / by zero

			// e.printStackTrace();
			// java.lang.ArithmeticException: / by zero
			// ________at Exceptions.TryCatch.main(TryCatch.java:6)
		}
	}
}

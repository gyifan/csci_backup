/**
 * Project: Lab 09 - Stack
 * File: Infix2PostfixTester.java
 * Author: Shane Markstrum, sm053
 * Date: Nov 2, 2009
 */

/**
 * A testing class for the Infix2Postfix translator.
 * 
 * @author sm053
 * 
 */
public class Infix2PostfixTester {

	/**
	 * Translate infix expressions to postfix expressions.
	 * 
	 * @param args
	 *            the expressions to be converted.
	 */

	public static void main(String args[]) {

		Infix2Postfix translator = new Infix2Postfix();

		// Make sure there is something to convert

		if (args.length < 1) {
			System.err.println("Usage:  Infix2PostFix expr1 [expr2 expr3 ...]");
			return;
		}

		// Convert all provided expressions

		for (String arg : args)
			try {
				System.out.println(arg + " ==> " + translator.translate(arg));
			} catch (IllegalArgumentException e) {
				System.err.println("The expression " + arg
						+ " contains illegal characters!");
			} catch (ParensMismatchException e) {
				System.err.println("The expression " + arg
						+ " contains illegal characters!");
			}
	}
}

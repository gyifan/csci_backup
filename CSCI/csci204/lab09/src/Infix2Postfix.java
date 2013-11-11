/**
 * Project: Lab 09 - Stack
 * File: Infix2Postfix.java
 * Author: Shane Markstrum, sm053
 * Date: Nov 2, 2009
 */

/**
 * This is a simple demonstration program utilizing a stack to convert a
 * restricted class of infix expressions to their postfix equivalent. The class
 * is as follows:
 * 
 * Expressions consist of single-letter variable names ('a' through 'z'),
 * separated by the mathematical operators <tt>'/'</tt>, <tt>'*'</tt>,
 * <tt>'-'</tt>, and <tt>'+'</tt>. Expressions may not contain spaces.
 * 
 * Precedence rules are: High: <tt>'/'</tt>, <tt>'*'</tt> Low: <tt>'+'</tt>,
 * <tt>'-'</tt>
 * 
 * Example expressions: Valid:
 * <table>
 * <td>
 * 
 * <pre>
 * a + b
 * </pre>
 * 
 * </td>
 * <td>
 * 
 * <pre>
 * a + b / c - d * e
 * </pre>
 * 
 * </td>
 * </table>
 * 
 * Invalid:
 * <table>
 * <td>
 * 
 * <pre>
 * a + b
 * </pre>
 * 
 * </td>
 * <td>
 * 
 * <pre>
 * a &circ; b
 * </pre>
 * 
 * </td>
 * <td>
 * 
 * <pre>
 * (a + b) * c
 * </pre>
 * 
 * </td>
 * </table>
 * 
 * @author sm053
 */

public class Infix2Postfix {
	// The opstack of the translator
	private Stack<Character> opStack;

	/**
	 * Creates a new Infix2Postfix translator.
	 */
	public Infix2Postfix() {
		opStack = new Stack<Character>();
	}

	/**
	 * Translates a simple infix arithmetic expression into a postfix notation.
	 * 
	 * @param expression
	 *            The infix expression to translate into postfix notation
	 * @return the translated expression
	 */
	public String translate(String expression) {
		String output = "";
		opStack.clear();
		for (int pos = 0; pos < expression.length(); pos++) {
			char ch = expression.charAt(pos);
			if (isVariable(ch)) { // ch is a variable
				output += ch;
			} else if (isOp(ch)) { // ch is an operator or left parenthesis
				output += handleStandardOp(ch);
			} else if (isEndParenthesis(ch)) { // ch is right parenthesis
				output += handleEndParenthesis();
			} else { // ch is an illegal character
				opStack.clear();
				throw new IllegalArgumentException();
			}
		}
		output += emptyAndPrintStack(); // flush the operators
		return output;
	}

	/**
	 * Pops all operators of the same or greater precedence of the provided
	 * operator from the stack and pushes the given operator.
	 * 
	 * @param ch
	 *            The operator to add to the stack
	 * @return the popped operators
	 */
	private String handleStandardOp(char ch) {
		String pops = popWithHigherPrecedence(ch);
		opStack.push(ch);
		return pops;
	}

	private String handleEndParenthesis() {
		String pops = "";

		if (opStack.isEmpty())
			throw new ParensMismatchException();

		if (opStack.peek() == '(')
			opStack.pop();

		else {
			pops += opStack.pop();
			handleEndParenthesis();
		}

		return pops;
	}

	/**
	 * Pops operators that have precedence >= op.
	 * 
	 * @param op
	 *            the operator to compare with stack operators.
	 * @return the popped operators
	 */
	private String popWithHigherPrecedence(char op) {
		String pops = "";
		while (!opStack.isEmpty() && topHasHigherPrecedence(op))
			pops += opStack.pop();
		return pops;
	}

	/**
	 * Determines if the operator on the stack top has precedence greater than
	 * or equal to an operator.
	 * 
	 * @param op
	 *            the operator to compare with the stack top.
	 * @return true if the stack top has precedence greater than or equal to an
	 *         operator, false otherwise.
	 */
	private boolean topHasHigherPrecedence(char op) {
		return comparePrecedence(op) <= 0;
	}

	/**
	 * Empties the stack while printing each elements as it is removed
	 * 
	 * @param opStack
	 *            the stack to empty
	 * @return the remaining elements on the stack
	 */
	private String emptyAndPrintStack() {
		String pops = "";
		while (!opStack.isEmpty()) {
			if (opStack.peek() == '(')
				throw new ParensMismatchException();
			pops += opStack.pop();
		}
		return pops;
	}

	/**
	 * Compare the precedence of the given operator with the operator on top of
	 * the stack. Returns a positive number if the precedence of the given
	 * operator is greater, 0 if it is equal, and a negative number if it is
	 * less.
	 * 
	 * @param op
	 *            the operator to compare
	 * @return returns a positive number if the precedence of the given operator
	 *         is greater than the operator on top of the stack, 0 if the
	 *         precedences are the same, and -1 if the precedence of the given
	 *         operator is less.
	 */
	private int comparePrecedence(char op) {
		char top = opStack.peek();
		int opGroup = 0;
		int topGroup = 0;

		// Convert precedences into numbers to make this easy. Multiplicative
		// operators are assigned 1, additive operators are assigned 0.

		if (op == '*' || op == '/')
			opGroup = 1;

		if (top == '*' || top == '/')
			topGroup = 1;

		if (top == '(')
			topGroup = -1;

		if (op == '(')
			opGroup = 2;

		return opGroup - topGroup;
	}

	/*
	 * Helper methods for determining input types
	 */

	/**
	 * Checks to see if a character is a variable name
	 * 
	 * @param ch
	 *            the character to check
	 * @return true if it is a variable, false otherwise.
	 */
	private static boolean isVariable(char ch) {
		return ch >= 'a' && ch <= 'z';
	}

	/**
	 * Checks to see if a character is a valid operation
	 * 
	 * @param ch
	 *            the character to check
	 * @return true if it is a valid operation character, false otherwise
	 */
	private static boolean isOp(char ch) {
		return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(';
	}

	private static boolean isEndParenthesis(char ch) {
		return ch == ')';
	}
}

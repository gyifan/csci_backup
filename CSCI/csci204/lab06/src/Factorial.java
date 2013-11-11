/**
 * <code>Factorial</code> provides the method <code>factorial</code> to compute
 * n! for a given n.
 * 
 * @author <a href="mailto:xmeng@smtp.bucknell.edu">Meng Xiannong</a>
 * @author other csci204 instructors
 * @version 1.1 revised 02/01/2006
 */
public class Factorial {
	// "long" is for very large integers
	/**
	 * Calculates the factorial of the number
	 * 
	 * @param n
	 *            the number
	 * @return the factorial of the number
	 * @throws DomainException
	 */
	public static long factorial(long n) throws DomainException {
		if (n < 0)
			throw new DomainException(
					"The given value is less than 0. Out of Domain.");
		if (n == 0)
			return 1;
		else
			return n * factorial(n - 1);
	}

	/**
	 * Calculates the sum of odd numbers that is less or equal to the given
	 * number.
	 * 
	 * @param n
	 *            the number
	 * @return the sum
	 * @throws DomainException
	 */
	public static long addOddInts(int n) throws DomainException {
		if (n < 1)
			throw new DomainException(
					"The given value is less than 1. Out of Domain.");
		if (n == 1)
			return 1;
		else if (n % 2 == 1)
			return n + addOddInts(n - 1);
		else
			return addOddInts(n - 1);
	}
}

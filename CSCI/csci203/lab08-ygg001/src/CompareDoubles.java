/**
 * CSCI 203, Yifan Ge
 * Oct 26, 2010, 10:07:47 AM
 */

/**
 * This class compares doubles
 * 
 * @author GE
 * 
 */
public class CompareDoubles {
	private static double EPSILON = 1.0E-14;

	/**
	 * Compares two doubles
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		double d = 4.35;
		double f = d - 0.2;
		if ((d - f) == 0.2) {
			System.out.println("Comparing doubles obeys Math laws!");
		} else {
			System.out.println("Comparing doubles does not obey Math laws!");
		}
		System.out.println("d - f: " + (d - f));
		System.out.println("Expected: 0.2\n");
		if (areClose(d - f, 0.2)) {
			System.out.println("The doubles are close!");
		} else {
			System.out.println("The doubles are not close!");
		}
		System.out.println("Expected: The doubles are close!");
	}

	/**
	 * Checks if two doubles are close
	 * 
	 * @param x
	 *            the first double
	 * @param y
	 *            the second double
	 * @return true if they are close, false if they aren't
	 */
	public static boolean areClose(double x, double y) {
		return Math.abs(x - y) <= EPSILON;
	}

}

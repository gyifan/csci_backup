/**
 * A program with errors for CSCI 204 Lab03 Java Debugger
 * 
 * Created: Fri Jan 28 10:31:05 2005 Modified: Tues Feb 02 2010
 * 
 * @author <a href="mailto:hyde@eg.bucknell.edu">Dr. Daniel C. Hyde</a>
 * @author <a href="mailto:sm053@bucknell.edu">Prof. Shane Markstrum</a>
 * @version 2.0
 */
public class TestPoint {

	/**
	 * Prints the point's value and distance from (0, 0)
	 * 
	 * @param p
	 *            a <code>Point</code> value
	 */
	private static void print(Point p) {
		System.out.println("Point: " + p.toString());
		System.out.println("Distance from (0, 0) is " + p.distance());
	}

	/**
	 * Starts execution.
	 * 
	 * @param args
	 *            a <code>String[]</code> used for command line arguments
	 */
	public static final void main(final String[] args) {

		Point pTest = new Point();
		Point[] pArray = new Point[10];
		Point pInstance = new Point(0.0, 0.0);

		// assign a unique coordinate to each array element
		for (int i = 0; i < pArray.length; i++) {
			pArray[i] = new Point(pInstance.getXComp(), pInstance.getYComp());
			pInstance.setPoint(i + 1, i + 2);
		}

		// Try out a simple print test
		print(pTest);

		// Since point p[0] is initialized to (0.0, 0.0) by the constructor,
		// the distance from (0, 0) should be 0.0...
		print(pArray[0]);

		// Since point p[3] is initialized to (3.0, 4.0),
		// the distance from (0, 0) should be 5.0
		print(pArray[3]);

		System.exit(0);
	}
}

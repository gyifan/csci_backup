import java.awt.Dimension;
import java.awt.Rectangle;

/**
 * CSCI 203, Yifan Ge
 * Sep 21, 2010, 10:43:45 AM
 */

/**
 * @author ygg001
 * 
 */
public class Exercise3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Rectangle rect1 = new Rectangle(4, 6, 2, 3);
		Rectangle rect2 = new Rectangle(10, 2, 4, 8);
		System.out.println("rect1 has location of (" + rect1.getX() + ","
				+ rect1.getY() + ") and width of " + rect1.getWidth()
				+ ", height of " + rect1.getHeight());
		System.out.println("rect2 has location of (" + rect2.getX() + ","
				+ rect2.getY() + ") and width of " + rect2.getWidth()
				+ ", height of " + rect2.getHeight());

		// The returned values are double.

		rect1.translate(50 - 4, 40 - 6);
		System.out.println("rect1 has location of (" + rect1.getX() + ","
				+ rect1.getY() + ") and width of " + rect1.getWidth()
				+ ", height of " + rect1.getHeight());
		System.out
				.println("Expected: rect1 has location of (50.0,40.0) and width of 2.0, height of 3.0");

		Dimension d = new Dimension(1, 10);
		rect2.setSize(d);
		System.out.println("rect2 has location of (" + rect2.getX() + ","
				+ rect2.getY() + ") and width of " + rect2.getWidth()
				+ ", height of " + rect2.getHeight());
		System.out
				.println("Expected: rect1 has location of (10.0,2.0) and width of 1.0, height of 10.0");

	}
}

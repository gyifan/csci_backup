import java.awt.Rectangle;

/**
 * CSCI 203, Yifan Ge
 * Sep 14, 2010, 10:14:25 AM
 */

/**
 * @author ygg001
 * 
 */
public class AreaTester {

	/**
	 * @param args
	 *            Unused
	 */
	public static void main(String[] args) {
		Rectangle rect = new Rectangle(3, 4, 3, 17);
		double area = rect.getWidth() * rect.getHeight();
		System.out.println("Area: " + area);
		System.out.println("Expected: 51.0");
	}
}

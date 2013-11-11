import java.awt.Rectangle;

/**
 * CSCI 203, Yifan Ge
 * Sep 14, 2010, 10:22:43 AM
 */

/**
 * @author ygg001
 * 
 */
public class RectanglePerimeter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Rectangle rect = new Rectangle(3, 4, 3, 17);
		double Perimeter = 2 * (rect.getWidth() + rect.getHeight());
		System.out.println("Perimeter: " + Perimeter);
		System.out.println("Expected: 40.0");
	}
}

import java.awt.geom.Point2D;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 * CSCI 203, Yifan Ge
 * Oct 9, 2010, 4:14:31 PM
 */

/**
 * This class displays a window on the screen.
 * 
 * @author Ge
 * 
 */
public class TriangleViewer {

	/**
	 * Creates and displays a window with input dialogues
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		double p1X = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the x Coordinate for Point 1: "));
		double p1Y = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the y coordinate for Point 1: "));
		double p2X = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the x coordinate for Point 2: "));
		double p2Y = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the y coordinate for Point 2: "));
		double p3X = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the x coordinate for Point 3: "));
		double p3Y = Double
				.parseDouble(JOptionPane
						.showInputDialog("Please enter the y coordinate for Point 3: "));

		JFrame frame = new JFrame("Triangle Viewer");
		int frameWidthExtraSpace = 50;
		int inforAdditionalSpace = 150;
		final int frameWidth = (int) Math.max(p1X, Math.max(p2X, p3X))
				+ frameWidthExtraSpace;
		final int frameHeight = (int) Math.max(p1Y, Math.max(p2Y, p3Y))
				+ inforAdditionalSpace;
		frame.setSize(frameWidth, frameHeight);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Point2D.Double p1 = new Point2D.Double(p1X, p1Y);
		Point2D.Double p2 = new Point2D.Double(p2X, p2Y);
		Point2D.Double p3 = new Point2D.Double(p3X, p3Y);
		Triangle triangle = new Triangle(p1, p2, p3);
		frame.add(new TriangleComponent(triangle));
		frame.setVisible(true);
	}
}

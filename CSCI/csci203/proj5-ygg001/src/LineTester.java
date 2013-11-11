import java.awt.geom.Point2D;

import javax.swing.JOptionPane;

/**
 * CSCI 203, Yifan Ge
 * Oct 25, 2010, 11:23:51 PM
 */

/**
 * Determines whether two lines intersect
 * 
 * @author GE
 * 
 */
public class LineTester {

	/**
	 * Determines whether two lines intersect
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Line line1 = constructTheLine();
		Line line2 = constructTheLine();
		if (line1.intersects(line2))
			JOptionPane.showMessageDialog(null, "These lines intersect.",
					"Results", JOptionPane.INFORMATION_MESSAGE);
		else if (line1.isEqualTo(line2))
			JOptionPane.showMessageDialog(null, "These lines are identical.",
					"Results", JOptionPane.INFORMATION_MESSAGE);
		else
			JOptionPane.showMessageDialog(null, "These lines don't intersect.",
					"Results", JOptionPane.INFORMATION_MESSAGE);
		System.exit(0);
	}

	/**
	 * Receives a line object from the user
	 * 
	 * @return the Line object
	 */
	public static Line constructTheLine() {
		int choice = LineUtils.showLineDialog("Enter a line");
		if (choice == -1) {
			System.exit(0);
			return null;
		} else if (choice == 0) {
			Point2D.Double point = inputPoint();
			double slope = inputSlope();
			return new Line(point, slope);
		} else if (choice == 1) {
			Point2D.Double point1 = inputPoint();
			Point2D.Double point2 = inputPoint();
			return new Line(point1, point2);
		} else if (choice == 2) {
			double slope = inputSlope();
			double intercept = inputIntercept();
			return new Line(slope, intercept);
		} else {
			double intercept = inputIntercept();
			return new Line(intercept);
		}

	}

	/**
	 * Receives an input point from user
	 * 
	 * @return a point
	 */
	public static Point2D.Double inputPoint() {
		String input = JOptionPane.showInputDialog(null,
				"Please enter a point on the line in the form of (x,y)",
				"Input", JOptionPane.INFORMATION_MESSAGE);
		if (input != null)
			return LineUtils.parsePoint(input);
		else {
			System.exit(0);
			return null;
		}

	}

	/**
	 * Receives a slope from user
	 * 
	 * @return the slope
	 */
	public static double inputSlope() {
		String input = JOptionPane.showInputDialog(null,
				"Please enter the slope of the line", "Input",
				JOptionPane.INFORMATION_MESSAGE);
		if (input != null)
			return Double.parseDouble(input);
		else {
			System.exit(0);
			return 0.0;
		}
	}

	/**
	 * Receives the intercept value from the user
	 * 
	 * @return the intercept value
	 */
	public static double inputIntercept() {
		String input = JOptionPane.showInputDialog(null,
				"Please enter the intercept value of the line", "Input",
				JOptionPane.INFORMATION_MESSAGE);
		if (input != null)
			return Double.parseDouble(input);
		else {
			System.exit(0);
			return 0.0;
		}
	}

}

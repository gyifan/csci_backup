import java.awt.geom.Point2D;

import javax.swing.JOptionPane;

/**
 * CSCI 203, Yifan Ge
 * Oct 22, 2010, 1:14:01 PM
 */

/**
 * This class constructs Line object and check if lines are intercepting,
 * parallel, and equal.
 * 
 * @author GE
 * 
 */
public class Line {
	private static final double EPSILON = 1.0E-5;
	// instance fields
	private double slope;
	private double interceptValue;
	private boolean isVertical;

	/**
	 * Constructs a Line object that passes through the point and has the given
	 * slope
	 * 
	 * @param point
	 *            the point
	 * @param slope
	 *            the value of the slope
	 */
	public Line(Point2D.Double point, double slope) {
		this.slope = slope;
		this.isVertical = false;
		this.interceptValue = point.getY() - slope * point.getX();
	}

	/**
	 * Constructs a Line object that passes through both points
	 * 
	 * @param p1
	 *            the point1
	 * @param p2
	 *            the point2
	 */
	public Line(Point2D.Double p1, Point2D.Double p2) {
		if (p1.equals(p2)) {
			JOptionPane.showMessageDialog(null, "Your points are the same!",
					"Error", JOptionPane.ERROR_MESSAGE);
			System.exit(0);
		} else if (areEqual(p1.getX(), p2.getX())) {
			this.isVertical = true;
			this.interceptValue = p1.getX();
		} else {
			this.isVertical = false;
			this.slope = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
			this.interceptValue = p1.getY() - slope * p1.getX();
		}
	}

	/**
	 * Constructs a Line object with the given slope and y-intercept
	 * 
	 * @param slope
	 *            the slope of the line
	 * @param intecept
	 *            the y-intercept of the line
	 */
	public Line(double slope, double intercept) {
		this.slope = slope;
		this.interceptValue = intercept;
		this.isVertical = false;
	}

	/**
	 * Constructs a Line object with the given x-intercept
	 * 
	 * @param intercept
	 *            the x-intercept of the line
	 */
	public Line(double intercept) {
		this.isVertical = true;
		this.interceptValue = intercept;
	}

	/**
	 * Checks if the line intersect with the other
	 * 
	 * @param other
	 *            the other Line object you want to check with
	 * @return true if two lines intersect, false if two lines don't intersect
	 */
	public boolean intersects(Line other) {
		return !this.isParallel(other);
	}

	/**
	 * Checks if the line is equal to the other line
	 * 
	 * @param other
	 *            the other Line object
	 * @return true if two lines are equal, false if two lines aren't equal.
	 */
	public boolean isEqualTo(Line other) {
		return this.isVertical == other.isVertical
				&& areEqual(this.interceptValue, other.interceptValue)
				&& areEqual(this.interceptValue, other.interceptValue);
	}

	/**
	 * Checks if the line is parallel with the other
	 * 
	 * @param other
	 *            the other line object you want to check with
	 * @return true if two lines are parallel, false if two lines aren't
	 *         parallel
	 */
	public boolean isParallel(Line other) {
		if (this.isVertical && other.isVertical)
			return true;
		else if (this.isVertical || other.isVertical)
			return false;
		else if (areEqual(this.slope, other.slope))
			return true;
		else
			return false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		if (this.isVertical && this.interceptValue < 0.0)
			return "vertical:  " + this.isVertical
					+ String.format(", intercept: %.1f", this.interceptValue);
		else if (this.isVertical)
			return "vertical:  " + this.isVertical
					+ String.format(", intercept:  %.1f", this.interceptValue);
		else if (this.interceptValue < 0.0)
			return "vertical: " + this.isVertical
					+ String.format(", intercept: %3.1f", this.interceptValue)
					+ String.format(", slope: %.1f", this.slope);
		else
			return "vertical: " + this.isVertical
					+ String.format(", intercept:  %3.1f", this.interceptValue)
					+ String.format(", slope: %.1f", this.slope);
	}

	/**
	 * Determines the equality of two double variables
	 * 
	 * @param value1
	 *            variable 1
	 * @param value2
	 *            variable 2
	 * @return true if two doubles are equal, false if two doubles are unequal
	 */
	private boolean areEqual(double value1, double value2) {
		return Math.abs(value1 - value2) <= EPSILON;
	}

	/**
	 * Tests the Line class
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Point2D.Double p1 = new Point2D.Double(1.0, 1.0);
		double slope = 0.5;
		Line line1 = new Line(p1, slope);
		System.out.println("line1: " + line1);
		Point2D.Double p2 = new Point2D.Double(1.0, 2.0);
		Line line2 = new Line(p1, p2);
		System.out.println("line2: " + line2);
		double yIntercept = -1.0;
		Line line3 = new Line(slope, yIntercept);
		System.out.println("line3: " + line3);
		double xIntercept = 1.0;
		Line line4 = new Line(xIntercept);
		System.out.println("line4: " + line4);
		p1 = new Point2D.Double(1.0, 1.0);
		slope = 0.0;
		Line line5 = new Line(p1, slope);
		System.out.println("line5: " + line5);
		xIntercept = 3.0;
		Line line6 = new Line(xIntercept);
		System.out.println("line6: " + line6);

		System.out.println("\n***Testing equals***");

		System.out.println("\nTest 1:   " + line1.isEqualTo(line2));
		System.out.println("Expected: false");

		System.out.println("\nTest 2:   " + line2.isEqualTo(line4));
		System.out.println("Expected: true");

		System.out.println("\n***Testing intersects***");

		System.out.println("\nTest 3:   " + line1.intersects(line2));
		System.out.println("Expected: true");

		System.out.println("\nTest 4:   " + line1.intersects(line3));
		System.out.println("Expected: false");

		System.out.println("\nTest 5:   " + line5.intersects(line6));
		System.out.println("Expected: true");

		System.out.println("\n***Testing isParallel***");

		System.out.println("\nTest 6:   " + line1.isParallel(line3));
		System.out.println("Expected: true");

		System.out.println("\nTest 7:   " + line2.isParallel(line4));
		System.out.println("Expected: true");

		System.out.println("\nTest 8:   " + line1.isParallel(line2));
		System.out.println("Expected: false");

		System.out.println("\nTest 9:   " + line5.isParallel(line6));
		System.out.println("Expected: false");

	}
}

/**
 * Point class for CS203 Lab work
 */
public class Point {

	// fields (also known as instance variables)

	private double xCoord;
	private double yCoord;

	/**
	 * Constructs and initializes a point at the origin (0,0) of the coordinate
	 * space.
	 */
	public Point() {
		xCoord = 0;
		yCoord = 0;
	}

	/**
	 * Constructs and initializes a point at the specified (x,y) location in the
	 * coordinate space.
	 * 
	 * @param x
	 *            the x-coordinate of the point
	 * @param y
	 *            the y-coordinate of the point
	 */
	public Point(double x, double y) {
		xCoord = x;
		yCoord = y;
	}

	/**
	 * Sets the x coordinate of the point.
	 * 
	 * @param x
	 *            the new x coordinate of the point.
	 */
	public void setXCoord(double x) {
		xCoord = x;
	}

	/**
	 * Sets the y coordinate of the point.
	 * 
	 * @param y
	 *            the new y coordinate of the point.
	 */
	public void setYCoord(double y) {
		yCoord = y;
	}

	/**
	 * Sets the location of the point to the specified location.
	 * 
	 * @param xthe
	 *            x coordinate of the new location
	 * @param ythe
	 *            y coordinate of the new location
	 */
	public void setLocation(double x, double y) {
		xCoord = x;
		yCoord = y;
	}

	/**
	 * Gets the x coordinate of the point.
	 * 
	 * @return the x coordinate of the point
	 */
	public double getXCoord() {
		return xCoord;
	}

	/**
	 * Gets the y coordinate of the point.
	 * 
	 * @return the y coordinate of the point
	 */
	public double getYCoord() {
		return yCoord;
	}

	/*
	 * Returns a string representation of this point and its location in the
	 * (x,y) coordinate plane.
	 * 
	 * @return a string representation of this point
	 */
	public String toString() {
		return "(" + xCoord + ", " + yCoord + ")";
	}

	/**
	 * Returns the distance from this pint to a specified point.
	 * 
	 * @param aPoint
	 *            the specified point to be measure against this point
	 * @return the distance between this point and the specified point.
	 */
	public double distance(Point aPoint) {
		double xDiff = xCoord - aPoint.getXCoord();
		double yDiff = yCoord - aPoint.getYCoord();
		double disDiff = Math.sqrt(xDiff * xDiff + yDiff * yDiff);
		return disDiff;
	}

	/**
	 * Tests the methods in this class.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		System.out.print("Testing the default constructor: ");
		Point p = new Point();
		Point p1 = new Point(2.0, 3.0);
		Point p2 = new Point(4.0, 5.0);
		System.out.println(p);
		System.out.println("Expected: (0.0, 0.0)\n");

		System.out.print("Test the setters: ");
		p.setXCoord(-3.5);
		p.setYCoord(1.0);
		System.out.println(p);
		System.out.println("Expected: (-3.5, 1.0)\n");

		System.out.print("Test the setLocation method: ");
		p.setLocation(0.3, 5.3);
		System.out.println(p);
		System.out.println("Expected: (0.3, 5.3)\n");

		System.out.print("Test the getters: ");
		System.out.println("(" + p.getXCoord() + ", " + p.getYCoord() + ")");
		System.out.println("Expected: (-3.5, 1.0)\n");

		Point p3 = new Point(0.0, 0.0);
		Point p4 = new Point(3.0, 4.0);
		System.out.println("Testing the distance method");
		System.out.println("Distance from " + p3 + "to" + p4 + ": "
				+ p3.distance(p4));
		System.out.println("Expected: 5.0\n");

		p3.setLocation(0.0, 0.0);
		p4.setLocation(5.0, 12.0);
		System.out.println("Another test of the distance method");
		System.out.println("Distance from " + p3 + "to" + p4 + ": "
				+ p3.distance(p4));
		System.out.println("Expected: 13.0\n");

		System.out.print("Test the initialization constructor: ");
		p = new Point(2.3, 4.5);
		System.out.println(p);
		System.out.println("Expected: (2.3, 4.5)\n");

		System.out.println("p= " + p + ", p1= " + p1 + ", p2= " + p2);

	}
}

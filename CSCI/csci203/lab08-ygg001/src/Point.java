/**
 * Point class for CS203 Lab work
 */
public class Point {

	// fields (aka instance variables)

	private int x;
	private int y;

	/**
	 * Constructs and initializes a point at the origin (0,0) of the coordinate
	 * space.
	 */
	public Point() {
		this.x = 0;
		this.y = 0;
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
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	/**
	 * Sets the x coordinate of the point.
	 * 
	 * @param x
	 *            the new x coordinate of the point.
	 */
	public void setX(int x) {
		this.x = x;
	}

	/**
	 * Sets the y coordinate of the point.
	 * 
	 * @param y
	 *            the new y coordinate of the point
	 */
	public void setY(int y) {
		this.y = y;
	}

	/**
	 * Gets the x coordinate of the point.
	 * 
	 * @return the x coordinate of the point
	 */
	public int getX() {
		return this.x;
	}

	/**
	 * Gets the y coordinate of the point.
	 * 
	 * @return the y coordinate of the point
	 */
	public int getY() {
		return this.y;
	}

	/*
	 * Returns a string representation of this point and its location in the
	 * (x,y) coordinate plane.
	 * 
	 * @return a string representation of this point
	 */
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}

	/**
	 * Compares if the x and y coordinates of the two points are equal.
	 * 
	 * @param p
	 *            a point to compare with the receiver point
	 * @return true if the two points have same values
	 */
	public boolean isEqualTo(Point p) {
		return (this.x == p.getX()) && (this.y == p.getY());
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
		System.out.println(p);
		System.out.println("Expected: (0, 0)\n");

		System.out.print("Test the setters: ");
		p.setX(-3);
		p.setY(1);
		System.out.println(p);
		System.out.println("Expected: (-3, 1)\n");

		System.out.print("Test the getters: ");
		System.out.println("(" + p.getX() + ", " + p.getY() + ")");
		System.out.println("Expected: (-3, 1)\n");

		System.out.print("Test the initialization constructor: ");
		p = new Point(2, 4);
		System.out.println(p);
		System.out.println("Expected: (2, 4)\n");

		System.out.print("Test the equals method: ");
		Point p2 = new Point(2, 4);
		System.out.println(p.isEqualTo(p2));
		System.out.println("Expected: true\n");

		System.out.print("Test the equals method: ");
		p2 = new Point(3, 4);
		System.out.println(p.isEqualTo(p2));
		System.out.println("Expected: false\n");

		Point p3 = new Point(1, 3);
		Point p4 = new Point(1, 3);
		if (p3 == p4)
			System.out.println("Using ==, they are equal!\n");
		else
			System.out.println("Using ==, they are not equal!\n");

		if (p3.isEqualTo(p4))
			System.out.println("Using isEqualTo method, they are equal!\n");
		else
			System.out.println("Using isEqualTo method, they are not equal!\n");

		p3 = p4;
		if (p3 == p4)
			System.out.println("Using ==, they are equal!\n");
		else
			System.out.println("Using ==, they are not equal!\n");

		if (p3.isEqualTo(p4))
			System.out.println("Using isEqualTo method, they are equal!\n");
		else
			System.out.println("Using isEqualTo method, they are not equal!\n");

		p4 = null;
		if (p4 == null)
			System.out.println("p4 is equal to null\n");
		else
			System.out.println("p4 is not equal to null\n");

		System.out.println(p4.getX());
	}
}

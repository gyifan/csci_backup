import java.awt.geom.Point2D;

/**
 * CSCI 203, Yifan Ge
 * Oct 8, 2010, 6:28:29 PM
 */

/**
 * This class creates a triangle and compute the lengths of all sides, the
 * perimeter, the area, and the angle of all corners.
 * 
 * @author Ge
 * 
 */
public class Triangle {

	// instance fields
	private Point2D.Double p1 = new Point2D.Double();
	private Point2D.Double p2 = new Point2D.Double();
	private Point2D.Double p3 = new Point2D.Double();
	private double a;
	private double b;
	private double c;

	/**
	 * Constructs a Triangle object.
	 * 
	 * @param point1
	 *            the first point of the triangle
	 * @param point2
	 *            the second point of the triangle
	 * @param point3
	 *            the fourth point of the triangle
	 */
	public Triangle(Point2D.Double point1, Point2D.Double point2,
			Point2D.Double point3) {
		p1 = point1;
		p2 = point2;
		p3 = point3;
		a = Math.sqrt(Math.pow(p1.getX() - p2.getX(), 2)
				+ Math.pow(p1.getY() - p2.getY(), 2));
		b = Math.sqrt(Math.pow(p2.getX() - p3.getX(), 2)
				+ Math.pow(p2.getY() - p3.getY(), 2));
		c = Math.sqrt(Math.pow(p1.getX() - p3.getX(), 2)
				+ Math.pow(p1.getY() - p3.getY(), 2));
	}

	/**
	 * Gets the coordinates of point 1
	 * 
	 * @return the coordinates of point 1
	 */
	public Point2D.Double getP1() {
		return p1;
	}

	/**
	 * Gets the coordinates of point 2
	 * 
	 * @return the coordinates of point 2
	 */
	public Point2D.Double getP2() {
		return p2;
	}

	/**
	 * Gets the coordinates of point 3
	 * 
	 * @return the coordinates of point 3
	 */
	public Point2D.Double getP3() {
		return p3;
	}

	/**
	 * Gets the side length between point 1 and point 2
	 * 
	 * @return the length between point 1 and point 2
	 */
	public double getSideLengthA() {
		return a;
	}

	/**
	 * Gets the side length between point 2 and point 3
	 * 
	 * @return the length between point 2 and point 3
	 */
	public double getSideLengthB() {
		return b;
	}

	/**
	 * Gets the side length between point 1 and point 3
	 * 
	 * @return the length between point 1 and point 3
	 */
	public double getSideLengthC() {
		return c;
	}

	/**
	 * Gets the perimeter of the triangle
	 * 
	 * @return the perimeter of the triangle
	 */
	public double getPerimeter() {
		double perimeter = a + b + c;
		return perimeter;
	}

	/**
	 * Gets the area of the triangle
	 * 
	 * @return the area of the triangle
	 */
	public double getArea() {
		double semiPerimeter = this.getPerimeter() / 2;
		double area = Math.sqrt(semiPerimeter * (semiPerimeter - a)
				* (semiPerimeter - b) * (semiPerimeter - c));
		return area;
	}

	/**
	 * Gets the angle in degrees of the corner at point 1
	 * 
	 * @return the angle in degrees of the corner at point 1
	 */
	public double getAngleP1() {
		double radiansP1 = Math.acos((a * a + c * c - b * b) / (2.0 * a * c));
		double degreeP1 = Math.toDegrees(radiansP1);
		return degreeP1;
	}

	/**
	 * Gets the angle in degrees of the corner at point 2
	 * 
	 * @return the angle in degrees of the corner at point 2
	 */
	public double getAngleP2() {
		double radiansP2 = Math.acos((a * a + b * b - c * c) / (2.0 * a * b));
		double degreeP2 = Math.toDegrees(radiansP2);
		return degreeP2;
	}

	/**
	 * Gets the angle in degrees of the corner at point 3
	 * 
	 * @return the angle in degrees of the corner at point 3
	 */
	public double getAngleP3() {
		double radiansP3 = Math.acos((b * b + c * c - a * a) / (2.0 * b * c));
		double degreeP3 = Math.toDegrees(radiansP3);
		return degreeP3;
	}

}

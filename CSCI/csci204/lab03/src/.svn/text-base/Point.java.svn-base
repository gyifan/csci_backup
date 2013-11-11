/**
 * Point class models a point on a plane
 * 
 * 
 * Created: Fri Jan 28 10:35:54 2005 Modified: Tues Feb 02 2010
 * 
 * @author <a href="mailto:hyde@eg.bucknell.edu">Dr. Daniel C. Hyde</a>
 * @author <a href="mailto:sm053@bucknell.edu">Prof. Shane Markstrum</a>
 * @version 2.0
 */
public class Point {

	/**
	 * The x coordinates of the point
	 */
	private Double xComp;
	/**
	 * The y coordinates of the point
	 */
	private Double yComp;

	/**
	 * <b>Constructs a point object with x coordinate of 0.0, y coordinate of
	 * 0.0.</b>
	 * 
	 */
	public Point() {
		xComp = 0.0;
		yComp = 0.0;
	}

	/**
	 * <b>Constructs a point object with given coordinates.</b>
	 * 
	 * @param inX
	 *            X coordinate
	 * @param inY
	 *            Y coordinate
	 */
	public Point(double inX, double inY) {
		xComp = inX;
		yComp = inY;
	}

	/**
	 * <b>Sets the coordinates of the point.</b>
	 * 
	 * @param inX
	 *            X coordinate
	 * @param inY
	 *            Y coordinate
	 */
	public void setPoint(double inX, double inY) {
		xComp = inX;
		yComp = inY;
	}

	/**
	 * <b>Calculates the distance between the point and (0.0, 0.0) point.</b>
	 * 
	 * @return the distance
	 */
	public double distance() {
		return Math.sqrt((xComp - 0.0) * (xComp - 0.0) + (yComp - 0.0)
				* (yComp - 0.0));
	}

	/**
	 * <b>Gets the x coordinate of the point.</b>
	 * 
	 * @return x coordinate
	 */
	public double getXComp() {
		return xComp;
	}

	/**
	 * <b>Gets the y coordinate of the point.</b>
	 * 
	 * @return y coordinate
	 */
	public double getYComp() {
		return yComp;
	}

	/**
	 * <b>Presents the object as string object in the format of (x, y).</b>
	 */
	@Override
	public String toString() {
		return "(" + xComp.toString() + ", " + yComp.toString() + ")";
	}

}

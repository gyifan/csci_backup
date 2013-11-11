/**
 * CSCI 203, Yifan Ge
 * Sep 28, 2010, 11:15:42 AM
 */

/**
 * @author ygg001
 * 
 */
public class DistanceFinder {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Point p1 = new Point(0.0, 0.0);
		Point p2 = new Point(0.0, 4.0);
		Point p3 = new Point(3.0, 0.0);

		double totDis = p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
		System.out.println("Point 1: (" + p1.getXCoord() + "," + p1.getYCoord()
				+ ")");
		System.out.println("Point 1: (" + p2.getXCoord() + "," + p2.getYCoord()
				+ ")");
		System.out.println("Point 1: (" + p3.getXCoord() + "," + p3.getYCoord()
				+ ")");
		System.out.println("The total distance is " + totDis + "\n");

		p1.setLocation(3.5, 4.6);
		p2.setLocation(-3.4, 5.7);
		p3.setLocation(9.3, -10.0);

		totDis = p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
		System.out.println("Point 1: (" + p1.getXCoord() + "," + p1.getYCoord()
				+ ")");
		System.out.println("Point 1: (" + p2.getXCoord() + "," + p2.getYCoord()
				+ ")");
		System.out.println("Point 1: (" + p3.getXCoord() + "," + p3.getYCoord()
				+ ")");
		System.out.println("The total distance is " + totDis);
	}

}

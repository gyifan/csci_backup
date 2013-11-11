import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Random;

/**
 * This class represents a sky full of stars.
 * 
 * @author Rick Zaccone
 */
public class Stars {
	private ArrayList<Point2D.Double> stars;

	/**
	 * Constructs a Stars object.
	 */
	public Stars() {
		stars = new ArrayList<Point2D.Double>();

	}

	/**
	 * Adds a star to the list of stars.
	 * 
	 * @param point
	 *            the star to add
	 */
	public void add(Point2D.Double point) {
		stars.add(point);
	}

	/**
	 * Draws the stars.
	 * 
	 * @param g2
	 *            the graphics context
	 */
	public void draw(Graphics2D g2) {
		Random generator = new Random();
		Ellipse2D.Double oneStar;
		double diameter;
		double xCoord;
		double yCoord;
		for (int i = 0; i < stars.size(); i++) {
			diameter = 5 * generator.nextDouble() + 1;
			xCoord = stars.get(i).getX() + diameter / 2;
			yCoord = stars.get(i).getY() + diameter / 2;
			oneStar = new Ellipse2D.Double(xCoord, yCoord, diameter, diameter);
			g2.setColor(Color.WHITE);
			g2.fill(oneStar);
		}

	}
}

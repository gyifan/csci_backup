import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Rectangle;

/**
 * CSCI 203, Yifan Ge
 * Oct 2, 2010, 1:58:32 PM
 */

/**
 * This class includes constructors and methods of Bar Class.
 * 
 * @author GE
 * 
 */
public class Bar {

	// instance fields (instance variables)

	private int y;
	private int width;
	private String title;
	private Color color;

	/**
	 * Constructs a bar object.
	 * 
	 * @param y
	 *            y coordinate of the bar
	 * @param width
	 *            the width of the bar
	 * @param title
	 *            the tile of the bar
	 * @param color
	 *            the color of the bar
	 */
	public Bar(int y, int width, String title, Color color) {
		this.y = y;
		this.width = width;
		this.title = title;
		this.color = color;
	}

	/**
	 * Draws the bar on the canvas.
	 * 
	 * @param canvas2D
	 *            the canvas
	 */
	public void draw(Graphics2D canvas2D) {

		// Draws the bar

		int barX = 0;
		int barY = this.y;
		int barWidth = this.width;
		int barHeight = 50;
		Rectangle bar = new Rectangle(barX, barY, barWidth, barHeight);
		canvas2D.setColor(color);
		canvas2D.fill(bar);
		canvas2D.setColor(Color.BLACK);
		canvas2D.draw(bar);

		// Draws the title for the bar

		int titleX = barX + 5;
		int titleY = barY + 30;
		canvas2D.drawString(title, titleX, titleY);
	}
}

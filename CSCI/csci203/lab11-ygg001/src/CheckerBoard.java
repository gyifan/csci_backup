import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;

/**
 * This class displays a checkerboard with squares, alternating between black
 * and red.
 */
public class CheckerBoard {
	private int numSquares;
	private int size;

	/**
	 * Creates a CheckerBoard object with a given number of squares.
	 * 
	 * @param aNumSquares
	 *            the number of squares in each row
	 * @param aSize
	 *            the size of each square
	 */
	public CheckerBoard(int aNumSquares, int aSize) {
		numSquares = aNumSquares;
		size = aSize;
	}

	/**
	 * Draws the checkerboard.
	 * 
	 * @param g2
	 *            the graphics context
	 */
	public void draw(Graphics2D g2) {
		Rectangle2D.Double rectangle = new Rectangle2D.Double();
		for (int i = 0; i < numSquares; i++) {
			for (int j = 0; j < numSquares; j++) {
				rectangle.setRect(j * size, i * size, size, size);
				if ((i + j) % 2 == 1) {
					g2.setColor(Color.RED);
					g2.fill(rectangle);
				} else {
					g2.setColor(Color.BLACK);
					g2.fill(rectangle);
				}
			}
		}
	}
}

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.JPanel;

/**
 * Canvas draws primitive 2d graphics representing the state of a grid and rover
 * and other objects.
 * 
 * @author Wittie, Cronburg, Markstrum
 * 
 */
public class GuiPanel extends JPanel {

	private static final long serialVersionUID = 2916266015357608030L;

	/**
	 * The (pixel?) size of the grid (width and height).
	 */
	public static int GRIDSIZE = 400;

	/**
	 * The (pixel?) size of a cell (width and height).
	 */
	public static int CELLSIZE = 25;

	/**
	 * The dimensions of the maze canvas.
	 */
	private Dimension canvasSize = new Dimension(GRIDSIZE, GRIDSIZE);

	/**
	 * The dimensions of the drawn maze cells.
	 */
	private Dimension cellSize = new Dimension(CELLSIZE, CELLSIZE);

	public GuiPanel(IRover rover) {
		this.rover = rover;
	}

	/**
	 * The robot object to draw.
	 */
	private IRover rover;

	/**
	 * Draw the grid and all its contents.
	 * 
	 * @see java.awt.Canvas#paint(java.awt.Graphics)
	 */
	@Override
	public void paint(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;

		IRoom room = rover.getRoom();

		// draw the room
		synchronized (room) {

			for (int i = 0; i < Room.SIZE; i++) {
				for (int j = 0; j < Room.SIZE; j++) {
					// Draw white square
					g2.setColor(Color.WHITE);
					g2.fillRect(i * cellSize.width, j * cellSize.height,
							cellSize.width, cellSize.height);

					// draw an object in the room
					if (room.isOccupied(i, j)) {
						Image image = room.getImage(i, j);
						// ok images will be drawn
						if (image != null) {
							g2.drawImage(image, i * cellSize.width, j
									* cellSize.height, this);
						}
						// bad images may be null and will be drawn as a big
						// orange blob
						else {
							g2.setColor(Color.ORANGE);
							g2.fillOval(i * cellSize.width, j * cellSize.width,
									cellSize.width, cellSize.height);
							g2.setColor(Color.BLACK);
							g2.drawOval(i * cellSize.width, j * cellSize.width,
									cellSize.width, cellSize.height);
						}
					}
				}
			}
		}

		// draw the rover. if it is null, draw a big blue blob
		int roverX = rover.getLocation().x * cellSize.width;
		int roverY = rover.getLocation().y * cellSize.height;

		Image image = rover.getImage();
		if (image != null) {
			g2.drawImage(image, roverX, roverY, this);
		} else {
			g2.setColor(Color.BLUE);
			g2.fillOval(roverX, roverY, cellSize.width, cellSize.height);
			g2.setColor(Color.BLACK);
			g2.drawOval(roverX, roverY, cellSize.width, cellSize.height);
		}

	}
}

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

/**
 * Project: Maze Escaping Robots!!!
 * File: MazeCanvas.java
 * Author: Shane Markstrum, sm053
 * Date: Feb 22, 2010
 */

/**
 * MazeCanvas draws primitive 2d graphics representing the state of a maze and
 * robot from the Maze Escaping Robots project.
 * 
 * To use MazeCanvas, the maze and robot must implement the IMaze and IRobot
 * interfaces, respectively.
 * 
 * @author sm053
 * 
 */
public class MazePanel extends JPanel {

	private static final long serialVersionUID = 2916266015357608030L;

	/**
	 * The minimum size for printing the canvas.
	 */
	private static final Dimension MIN_CANVAS_SIZE = new Dimension(401, 401);

	/**
	 * The minimum size to draw a cell.
	 */
	private static final Dimension MIN_CELL_SIZE = new Dimension(10, 10);

	/*
	 * Canvas instance fields
	 */

	/**
	 * The dimensions of the maze canvas.
	 */
	private Dimension canvasSize = MIN_CANVAS_SIZE;

	/**
	 * The dimensions of the drawn maze cells.
	 */
	private Dimension cellSize = new Dimension(10, 10);

	/**
	 * The maze object to draw.
	 */
	private IMaze maze;

	/**
	 * The robot object to draw.
	 */
	private IRobot robot;

	private boolean trackVisiting;

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.Component#getPreferredSize()
	 */
	@Override
	public Dimension getPreferredSize() {
		return canvasSize;
	}

	/**
	 * Sets the stored maze to the one passed as a parameter. Updates the size
	 * of the canvas and cells to accommodate the new maze.
	 * 
	 * <P>
	 * Calls IMaze.getNumCols() and IMaze.getNumRows()
	 * 
	 * @param maze
	 *            the new maze
	 */
	public void setMaze(IMaze maze) {
		this.maze = maze;

		int width;
		int cellwidth;

		if (MIN_CELL_SIZE.width * (maze.getNumCols() + 1) < MIN_CANVAS_SIZE.width) {
			width = MIN_CANVAS_SIZE.width;
			cellwidth = MIN_CANVAS_SIZE.width / (maze.getNumCols() + 1);
		} else {
			width = MIN_CELL_SIZE.width * (maze.getNumCols() + 1);
			cellwidth = MIN_CELL_SIZE.width;
		}
		int height, cellheight;
		if (MIN_CELL_SIZE.height * (maze.getNumRows() + 1) < MIN_CANVAS_SIZE.height) {
			height = MIN_CANVAS_SIZE.height;
			cellheight = MIN_CANVAS_SIZE.height / (maze.getNumRows() + 1);
		} else {
			height = MIN_CELL_SIZE.height * (maze.getNumRows() + 1);
			cellheight = MIN_CELL_SIZE.height;
		}

		int cellSize = (cellwidth < cellheight) ? cellwidth : cellheight;
		this.cellSize = new Dimension(cellSize, cellSize);
		canvasSize = new Dimension(width, height);
	}

	/**
	 * Sets the robot to the parameter object.
	 * 
	 * @param robot
	 *            the new robot
	 */
	public void setRobot(IRobot robot) {
		this.robot = robot;
	}

	/**
	 * Calls IMaze.getNumCols(), IMaze.getNumRows(), IMaze.isWall(int, int),
	 * IMaze.isExit(int, int), IMaze.visited(int, int). Calls
	 * IRobot.getLocation(), IRobot.getDirection().
	 * 
	 * @see java.awt.Canvas#paint(java.awt.Graphics)
	 */
	@Override
	public void paint(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;

		if (maze == null)
			return;

		int xoffset = (canvasSize.width - cellSize.width * maze.getNumCols()) / 2;
		int yoffset = (canvasSize.height - cellSize.height * maze.getNumRows()) / 2;

		// draw the maze
		synchronized (maze) {

			for (int i = 0; i < maze.getNumCols(); i++) {
				for (int j = 0; j < maze.getNumRows(); j++) {
					if (maze.isWall(i, j)) {
						g2.setColor(Color.BLACK); // walls are black
					} else if (maze.isExit(i, j)) {
						g2.setColor(Color.BLUE); // exits are blue
					} else if (trackVisiting) {
						int blueoffset = maze.visited(i, j);
						if (blueoffset > 3)
							blueoffset = 3;

						blueoffset *= 84;
						g2.setColor(new Color(255 - blueoffset,
								255 - blueoffset, 255));// visited halls are
						// blue-er
					} else {
						g2.setColor(Color.WHITE); // halls are white
					}
					g2.fillRect(i * cellSize.width + xoffset, j
							* cellSize.height + yoffset, cellSize.width,
							cellSize.height);
				}
			}
		}

		// draw the robot
		if (robot != null) {
			g2.setColor(Color.GRAY);

			int roboX = robot.getLocation().x * cellSize.width + xoffset;
			int roboY = robot.getLocation().y * cellSize.height + yoffset;

			g2.fillOval(roboX, roboY, cellSize.width, cellSize.height);
			g2.setColor(Color.BLACK);
			g2.drawOval(roboX, roboY, cellSize.width, cellSize.height);
			switch (robot.getDirection()) {
			case EAST:
				g2.drawLine(roboX + cellSize.width / 2, roboY + cellSize.height
						/ 2, roboX + cellSize.width, roboY + cellSize.height
						/ 2);
				break;
			case WEST:
				g2.drawLine(roboX, roboY + cellSize.height / 2, roboX
						+ cellSize.width / 2, roboY + cellSize.height / 2);
				break;
			case NORTH:
				g2.drawLine(roboX + cellSize.width / 2, roboY, roboX
						+ cellSize.width / 2, roboY + cellSize.height / 2);
				break;
			case SOUTH:
				g2.drawLine(roboX + cellSize.width / 2, roboY + cellSize.height
						/ 2, roboX + cellSize.width / 2, roboY
						+ cellSize.height);
				break;
			default:
				break;
			}
		}
	}

	public void trackVisiting(boolean trackVisiting) {
		this.trackVisiting = trackVisiting;

	}
}

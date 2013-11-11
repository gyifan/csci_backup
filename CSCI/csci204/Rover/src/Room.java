import java.awt.Image;
import java.awt.Point;
import java.util.Random;

/**
 * CSCI 204, Yifan Ge
 * Assignment Rover
 * Created: Apr 21, 2011, 4:04:04 PM
 */

/**
 * This class creates a room on the game board by implementing IRoom interface.
 * 
 * @author Yifan Ge
 * 
 */
public class Room implements IRoom {

	// instance fields

	/** The size of the map. */
	public final static int SIZE = 15;

	/** The 2 dimensional array of Image represents the board of the game. */
	private Image[][] board;

	/** The 2 dimensional array of portal stores the information of the portals */
	private Portal[][] portal;

	/**
	 * Constructs a default Room object by define board to be a SIZE*SIZE Image
	 * array.
	 */
	public Room() {
		board = new Image[SIZE][SIZE];
		portal = new Portal[SIZE][SIZE];
	}

	/**
	 * Return the image of the item in the grid at this location. Assumes that
	 * the location is occupied. If the location is not occupied, this will
	 * throw a null pointer exception. If something is wrong with the image, it
	 * may be null. This is an accessor method. Called by the GuiPanel to draw
	 * the room.
	 * 
	 * @param column
	 *            the column number of the box
	 * @param row
	 *            the row number of the box
	 * @see IRoom#getImage(int, int)
	 */
	@Override
	public Image getImage(int column, int row) {
		return board[column][row];
	}

	/**
	 * Returns true if the given space is occupied, false if it is not. It could
	 * be occupied by a portal, item, or ship part. The rover doesn't count as
	 * occupying a space (it floats and it gets drawn separately). This is an
	 * accessor method. Called by the GuiPanel to draw the room.
	 * 
	 * @param column
	 *            the column number of the box
	 * @param row
	 *            the row number of the box
	 * 
	 * @see IRoom#isOccupied(int, int)
	 */
	@Override
	public boolean isOccupied(int column, int row) {
		return board[column][row] != null;
	}

	/**
	 * Sets the image at the desired place on the board.
	 * 
	 * @param column
	 *            the column of the place
	 * @param row
	 *            the row of the place
	 * @param image
	 *            the image
	 */
	public void setImage(int column, int row, Icon icon) {
		if (icon == null)
			board[column][row] = null;
		else
			board[column][row] = icon.getImage();
	}

	/**
	 * Sets the portal at the desired location.
	 * 
	 * @param location
	 *            the location
	 * @param newPortal
	 *            the new portal
	 */
	public void setPortal(Point location, Portal newPortal) {
		portal[location.x][location.y] = newPortal;
	}

	/**
	 * Gets the portal at the location.
	 * 
	 * @param location
	 *            the location
	 * @return the portal
	 */
	public Portal getPortal(Point location) {
		return portal[location.x][location.y];
	}

	/**
	 * Generates a random setting for the current room object. It will contains
	 * some Cakes, Gears, Screws, and Portals.
	 */
	public void generateRandom() {

		// Generates random number of materials.
		Random rand = new Random();
		int numberOfCake = rand.nextInt(5) + 1;
		int numberOfGear = rand.nextInt(5) + 1;
		int numberOfScrew = rand.nextInt(5) + 1;
		int numberOfPortal = rand.nextInt(2) + 1;

		// Adds portals to the room.
		for (int i = 0; i < numberOfPortal; i++) {
			int column = rand.nextInt(SIZE);
			int row = rand.nextInt(SIZE);
			while (board[column][row] != null) {
				column = rand.nextInt(SIZE);
				row = rand.nextInt(SIZE);
			}
			board[column][row] = Icon.PORTAL.getImage();
		}

		// Adds cakes to the room.
		for (int i = 0; i < numberOfCake; i++) {
			int column = rand.nextInt(SIZE);
			int row = rand.nextInt(SIZE);
			while (board[column][row] != null) {
				column = rand.nextInt(SIZE);
				row = rand.nextInt(SIZE);
			}
			board[column][row] = Icon.CAKE.getImage();
		}

		// Adds gears to the room.
		for (int i = 0; i < numberOfGear; i++) {
			int column = rand.nextInt(SIZE);
			int row = rand.nextInt(SIZE);
			while (board[column][row] != null) {
				column = rand.nextInt(SIZE);
				row = rand.nextInt(SIZE);
			}
			board[column][row] = Icon.GEAR.getImage();
		}

		// Adds screws to the room.
		for (int i = 0; i < numberOfScrew; i++) {
			int column = rand.nextInt(SIZE);
			int row = rand.nextInt(SIZE);
			while (board[column][row] != null) {
				column = rand.nextInt(SIZE);
				row = rand.nextInt(SIZE);
			}
			board[column][row] = Icon.SCREW.getImage();
		}
	}

	/**
	 * Sets the a base room, which includes broken parts of the ship.
	 */
	public void setBaseRoom() {
		board[7][7] = Icon.CABIN.getImage();
		board[6][6] = Icon.ENGINE.getImage();
		board[7][6] = Icon.ENGINE.getImage();
		board[8][6] = Icon.ENGINE.getImage();
		board[7][8] = Icon.EXHAUST.getImage();
		board[7][5] = Icon.FIXEDWHEEL.getImage();
		board[6][8] = Icon.FIXEDWHEEL.getImage();
		board[8][8] = Icon.FIXEDWHEEL.getImage();
		generateRandom();
	}
}

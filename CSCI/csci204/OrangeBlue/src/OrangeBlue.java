import java.awt.Color;

/**
 * CSCI 204, Yifan Ge
 * Assiangment OrangeBlue
 * Created: Mar 22, 2011, 9:57:29 PM
 */

/**
 * I'm using two late cards for this project. This class defines the constructor
 * and methods for a orange and blue game. The game needs two people to play.
 * One represents blue, the other represents orange. By clicking on the board,
 * the player can place their color dot on the board. If after placing a dot at
 * one end of a line and creates a surrounding situation (Two same color dot
 * surround some other color dots), the surrounded dots will swap to the other
 * color. The game records the scores for each player and announce "Occupied"
 * when a play try to place dot on an occupied space. It also announce the
 * winner after the game is finished.
 * 
 * @author ygg001
 * 
 */
public class OrangeBlue implements IOrangeBlue {

	// class constants

	/** Integer representation for North direction */
	private static final int NORTH = -1;
	/** Integer representation for South direction */
	private static final int SOUTH = 1;
	/** Integer representation for East direction */
	private static final int EAST = 1;
	/** Integer representation for West direction */
	private static final int WEST = -1;
	/** Integer representation for no direction */
	private static final int NONE = 0;
	/** Default board size */
	private static final int BOARDSIZE = 10;

	// instance fields

	/** The 2D color array that stores the information about the board */
	Color[][] board;
	/** The score for blue */
	int blueScore;
	/** The score for orange */
	int orangeScore;
	/** The color of the current player */
	Color currentColor;
	/** The announcements */
	String announcements;
	/** Whether swap the color */
	boolean isSwap;

	/**
	 * Constructs a default OrangeBlue object.
	 */
	public OrangeBlue() { // O(1)
		board = new Color[BOARDSIZE][BOARDSIZE]; // O(1)
		blueScore = 0; // O(1)
		orangeScore = 0; // O(1)
		currentColor = Color.BLUE; // O(1)
		announcements = ""; // O(1)
		isSwap = false; // O(1)
	}

	/*
	 * (non-Javadoc) Gets the announcement
	 * 
	 * @see IOrangeBlue#getAnnouncements()
	 */
	@Override
	public String getAnnouncements() {
		return announcements; // O(1)
	}

	/*
	 * (non-Javadoc) Gets the blue score.
	 * 
	 * @see IOrangeBlue#getBlueScore()
	 */
	@Override
	public int getBlueScore() {
		return blueScore; // O(1)
	}

	/*
	 * (non-Javadoc) Gets the array of Collor objects.
	 * 
	 * @see IOrangeBlue#getBoard()
	 */
	@Override
	public Color[][] getBoard() {
		return board; // O(1)
	}

	/*
	 * (non-Javadoc) Gets the current color of player.
	 * 
	 * @see IOrangeBlue#getCurrentColor()
	 */
	@Override
	public Color getCurrentColor() {
		return currentColor; // O(1)
	}

	/*
	 * (non-Javadoc) Gets the orange score.
	 * 
	 * @see IOrangeBlue#getOrangeScore()
	 */
	@Override
	public int getOrangeScore() {
		return orangeScore; // O(1)
	}

	/**
	 * Handles the moves. This method gets called after the player played there
	 * move. If the player try to play the dot on occupied block, the
	 * announcement will be changed to "Occupied" and nothing else occur. If the
	 * dot is placed at a vacant block, the dot will be placed and the
	 * handleMove method will call calculate method to change the color of the
	 * dots accordingly. If after the placement, the panel is full. The
	 * announcement will announce the winner who has the most number of dots.
	 * The scores for blue and orange will be changed accordingly.
	 */
	@Override
	public void handleMove(int row, int column) {

		// Checks whether the spot is occupied.
		if (!(board[row][column] == null)) // O(1)
			announcements = "Occupied"; // O(1)
		else {

			// Checks colors in 8 directions recursively
			calculate(column, row, NORTH, NONE);
			compensation(); // O(1)
			calculate(column, row, NORTH, EAST);
			compensation(); // O(1)
			calculate(column, row, NONE, EAST);
			compensation(); // O(1)
			calculate(column, row, SOUTH, EAST);
			compensation(); // O(1)
			calculate(column, row, SOUTH, NONE);
			compensation(); // O(1)
			calculate(column, row, SOUTH, WEST);
			compensation(); // O(1)
			calculate(column, row, NONE, WEST);
			compensation(); // O(1)
			calculate(column, row, NORTH, WEST);
			compensation(); // O(1)

			// records the point for the original spot
			if (currentColor.equals(Color.BLUE)) { // O(1)
				blueScore++; // O(1)
			} else {
				orangeScore++; // O(1)
			}

			// changes to next color
			board[row][column] = currentColor; // O(1)
			currentColor = swapColor(currentColor); // O(1)
			announcements = ""; // O(1)
		}

		// Checks if the game is finished
		if ((blueScore + orangeScore) == (BOARDSIZE * BOARDSIZE)) { // O(1)
			if (blueScore > orangeScore) // O(1)
				announcements = "Blue wins!"; // O(1)
			else if (orangeScore > blueScore) // O(1)
				announcements = "Orange wins!"; // O(1)
			else if (orangeScore == blueScore) // O(1)
				announcements = "Draw!"; // O(1)
		}
	}

	@Override
	public void reset() { // O(1)
		board = new Color[BOARDSIZE][BOARDSIZE]; // O(1)
		blueScore = 0; // O(1)
		orangeScore = 0; // O(1)
		currentColor = Color.BLUE; // O(1)
		announcements = ""; // O(1)
		isSwap = false; // O(1)
	}

	/**
	 * Recursively checks the color of the next dots in desired direction until
	 * it hits an opposite color dot, empty space or boundary. If it hits an
	 * opposite color dot, flips the dots in between the original dot and the
	 * last dot. If it hits boundary or empty space, does nothing. Updates the
	 * score correspondingly.
	 * 
	 * This method is called by handleMove method and calls swapColor method.
	 * 
	 * @param column
	 *            the column of the dot
	 * @param row
	 *            the row of the dot
	 * @param color
	 *            the color of the dot
	 * @param NS
	 *            North/South direction
	 * @param EW
	 *            East/West direction
	 */
	private void calculate(int column, int row, int NS, int EW) {

		// Checks if the next spot is out of bounce - base case #1
		if ((row + NS < 0) || (column + EW > BOARDSIZE - 1)
				|| (row + NS > BOARDSIZE - 1) || (column + EW < 0))
			isSwap = false; // O(1)

		// Checks if the next spot is occupied by different color - base case #2
		else if (board[row + NS][column + EW] == currentColor)
			isSwap = true; // O(1)

		// Checks if the next spot is blank - base case #3
		else if (board[row + NS][column + EW] == null)
			isSwap = false; // O(1)

		// Checks if the next spot is the same color. If it is, recursively call
		// the same method. - recursive case
		else if (board[row + NS][column + EW].equals(swapColor(currentColor)))
			calculate(column + EW, row + NS, NS, EW);

		// Checks if the spot needs to change color. Records scores.
		if (isSwap) { // O(1)
			board[row][column] = currentColor; // O(1)
			if (currentColor.equals(Color.ORANGE)) { // O(1)
				blueScore--; // O(1)
				orangeScore++; // O(1)
			} else {
				blueScore++; // O(1)
				orangeScore--; // O(1)
			}
		}
	}

	/**
	 * Swaps the color of the dot to the other color. This method is called by
	 * calculate method.
	 * 
	 * @param color
	 *            the original color of the dot
	 * @return the color of the dot after swapping
	 */
	private Color swapColor(Color color) { // O(1)
		if (color.equals(Color.BLUE)) // O(1)
			return Color.ORANGE; // O(1)
		else if (color.equals(Color.ORANGE)) // O(1)
			return Color.BLUE; // O(1)
		else
			return color; // O(1)
	}

	/**
	 * Compensates the over counted scores in the calculate method. This method
	 * is called by handleMove method.
	 */
	private void compensation() {
		if (isSwap) { // O(1)
			if (currentColor.equals(Color.BLUE)) { // O(1)
				blueScore--; // O(1)
				orangeScore++; // O(1)
			} else {
				blueScore++; // O(1)
				orangeScore--; // O(1)
			}
			isSwap = false; // O(1)
		}
	}

	/**
	 * Constructs and runs the game. This method construct OrangeBlue object and
	 * OrangeBlueGui Object.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String args[]) { // O(1)
		OrangeBlue game = new OrangeBlue(); // O(1)
		new OrangeBlueGui(game); // O(1)
	}
}

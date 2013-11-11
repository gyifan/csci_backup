import java.util.ArrayList;

/**
 * CSCI 204, Michael Davis, Yifan Ge
 * Assignment GameOfLife
 * Created: Feb 3, 2011, 6:40:02 PM
 */

/**
 * The <code>GameOfLifeBoard</code> class contains methods that directly control
 * the state of cells in the board. These methods are called by the GameOfLife
 * class.
 * 
 * 
 * @author Michael Davis
 * @author Yifan Ge
 */
public class GameOfLifeBoard implements TwoDBoard {
	/**
	 * A 2-D array of cells that correspond to each space of the board.
	 */
	private Cell[][] cells;

	/**
	 * Constructs a GameOfLifeBoard with a 2D array of cells defined by the
	 * supplied board size. This method will be called by GameOfLife in the
	 * '.setBoardSize()' method.
	 * 
	 * @param boardSize
	 *            number of cells per side of the square board
	 */
	public GameOfLifeBoard(int boardSize, ArrayList<Integer> birthConditions,
			ArrayList<Integer> stayAliveConditions) {

		cells = new Cell[boardSize][boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				cells[i][j] = new GameOfLifeCell();
		setBirthConditions(birthConditions);
		setStayAliveConditions(stayAliveConditions);
	}

	/**
	 * Calls the changeState method of GameOfLifeCell. This will toggle the
	 * current state of the target cell, meaning if the cell is alive, it will
	 * die, or if it is dead it will come to life. Supplied coordinates must be
	 * within the boundaries of the board.
	 * 
	 * This method is called in the GameOfLife class.
	 * 
	 * @param x
	 *            x-coordinate of the cell to be changed
	 * @param y
	 *            y-coordinate of the cell to be changed
	 */
	@Override
	public void changeState(int x, int y) {
		cells[x][y].changeState();
	}

	/**
	 * Returns the number of cells per side of the board. This method is called
	 * by the GameOfLifeClass.
	 * 
	 * @return number of cells per side of board
	 */
	@Override
	public int getSize() {
		return cells.length;
	}

	/**
	 * Returns whether the targeted cell, defined by x and y, is alive or dead.
	 * The supplied parameters must be within the boundaries of the board. This
	 * method will call the isAlive() method of the GameOfLifeCell class. This
	 * method is called by the GameOfLife class.
	 * 
	 * @param x
	 *            x-coordinate of the target cell
	 * @param y
	 *            y-coordinate of the target cell
	 * @return will return true if the target cell is alive, false if the cell
	 *         is dead
	 */
	@Override
	public boolean isAlive(int x, int y) {
		return cells[x][y].isAlive();
	}

	/**
	 * Declares the conditions for which a cell will be born.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * This calls the GameOfLifeCell setBirthConditions method.
	 * 
	 * @param conditions
	 *            an ArrayList of numbers representing the number of neighbors
	 *            for which a cell will be born
	 */
	public void setBirthConditions(ArrayList<Integer> conditions) {
		GameOfLifeCell.setBirthConditions(conditions);
	}

	/**
	 * Declares the conditions for which a cell will stay alive.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * This calls the GameOfLifeCell setStayAliveCondtiions method.
	 * 
	 * @param conditions
	 *            an ArrayList of numbers representing the number of neighbors
	 *            for which a cell will stay alive
	 */
	public void setStayAliveConditions(ArrayList<Integer> conditions) {
		GameOfLifeCell.setStayAliveConditions(conditions);
	}

	/**
	 * Returns a 2D-array of boolean values representing the current state of
	 * every cell on the board. A true element in the array represents a living
	 * cell, a false element represents a dead cell. This method uses the
	 * GameOfLifeCell isAlive() method. The GameOfLife class calls this method.
	 * 
	 * @return boolean representation of the game board
	 */
	@Override
	public boolean[][] toArray() {

		boolean[][] booleanBoard = new boolean[cells.length][cells.length];

		for (int i = 0; i < cells.length; i++)
			for (int j = 0; j < cells[i].length; j++)
				booleanBoard[i][j] = cells[i][j].isAlive();

		return booleanBoard;
	}

	/**
	 * Reverts all cells on the board to their previous states.
	 * 
	 * This method is called by the GameOfLife class and calls the undo method
	 * in GameOfLifeCell.
	 */
	public void undo() {
		// Updates each cell on board to the previous state.
		for (int i = 0; i < cells.length; i++)
			for (int j = 0; j < cells[i].length; j++)
				cells[i][j].undo();
	}

	/**
	 * Determines the next state for every cell on the board and changes the
	 * state of the appropriate cells. This method is called by the GameOfLife
	 * class.
	 */
	@Override
	public void update() {

		// Calculates the next life status of each cell on the board.
		for (int i = 0; i < cells.length; i++)
			for (int j = 0; j < cells[i].length; j++) {
				cells[i][j].setNeighbors(getNeighbors(i, j));
				cells[i][j].calculateNextState();
			}

		// Updates each cell on board to the next state.
		for (int i = 0; i < cells.length; i++)
			for (int j = 0; j < cells[i].length; j++)
				cells[i][j].update();
	}

	/**
	 * Returns an ASCII representation of the board's current state. ASCII means
	 * a String that can be printed at the console and looks like the board with
	 * some characters representing live cell and dead cells (X and O or * and a
	 * space). The ASCII drawing will also need characters to represent the grid
	 * that the cells are in (_ and |). The GameOfLife calls this method.
	 * 
	 * @return an ASCII representation of the board
	 */
	public String toString() {
		String repASCII = "";

		// Adds the top line of the grid.
		repASCII += addHorizontalGridLine(cells.length);

		for (int i = 0; i < cells.length; i++) {

			// Starts the second line.
			repASCII += "\n| ";

			// Prints the cells.
			for (int j = 0; j < cells[i].length; j++) {
				if (cells[j][i].isAlive())
					repASCII += "O | ";
				else
					repASCII += "X | ";
			}

			// Enters the next line.
			repASCII += "\n";

			// Prints the separating line.
			repASCII += addHorizontalGridLine(cells[i].length);

		}
		return repASCII;
	}

	/**
	 * Returns a 2D array of cells touching the cell defined by parameters x and
	 * y on the board. This method is meant to supply the parameter for
	 * '.setNeighbors()' in a class that implements the cell interface.
	 * 
	 * @param x
	 *            x-coordinate of cell being examined. Must be within the bounds
	 *            of the board.
	 * @param y
	 *            y-coordinate of cell being examined. Must be within the bounds
	 *            of the board.
	 * @return two dimensional array of Cell objects that are touching the cell
	 *         defined by x and y.
	 */
	private Cell[][] getNeighbors(int x, int y) {

		Cell[][] neighbors = new Cell[3][3];
		int xStart, xStop, yStart, yStop;

		xStart = getStartValue(x);
		xStop = getStopValue(x);
		yStart = getStartValue(y);
		yStop = getStopValue(y);

		// fill neighbors with dead cells to prevent null pointer exceptions
		// from
		// being thrown in the GameOfLife class
		for (int i = 0; i < neighbors.length; i++)
			for (int j = 0; j < neighbors.length; j++)
				neighbors[i][j] = new GameOfLifeCell();

		// replace the appropriate cells from the board.
		for (int i = 0; i < (xStop - xStart); i++) {
			for (int j = 0; j < (yStop - yStart); j++) {
				// If it is the target cell just create a dead cell since it
				// will not be counted (cells[i + xSas a neighbor
				if ((i + xStart) == x && (j + yStart) == y) {
					// will be dead
				} else if (cells[i + xStart][j + yStart].isAlive())
					neighbors[i][j].changeState();
			}
		}

		return neighbors;
	}

	/**
	 * Computes the start value of a loop used to find the neighbors of a target
	 * cell. This method should only be called from within the private
	 * getNeighbors() method.
	 * 
	 * @param coordinate
	 *            x or y coordinate of target cell
	 * @return starting value of the loop
	 */
	private int getStartValue(int coordinate) {
		if (coordinate == 0)
			return coordinate;
		else

			return coordinate - 1;
	}

	/**
	 * Computes the stop value of a loop used to find the neighbors of a target
	 * cell. This method should only be called from within the private
	 * getNeighbors() method.
	 * 
	 * @param coordinate
	 *            x or y coordinate of target cell
	 * @return stopping value of the loop
	 */
	private int getStopValue(int coordinate) {
		if (coordinate == (cells.length - 1))
			return coordinate + 1;
		else
			return coordinate + 2;

	}

	/**
	 * Adds one horizontal line for the grid of the game board.
	 * 
	 * @param numOfCell
	 *            the number of cells in each horizontal line.
	 * @return a line with the length according to the number of the cells.
	 */
	private String addHorizontalGridLine(int numOfCell) {
		String line = "_";
		for (int i = 0; i < numOfCell; i++)
			line += "____";
		return line;
	}
}

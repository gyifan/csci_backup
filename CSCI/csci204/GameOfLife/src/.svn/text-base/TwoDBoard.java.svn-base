import java.util.ArrayList;

/**
 * An interface the defines how to use a board on Conway's Game of Life.
 * <P>
 * Your GameOfLifeBoard class will implement this interface. Your
 * GameOfLifeBoard will have a 2-D Cell array instance field (member data). When
 * you instantiate the Cells in the array, you will call the GameOfLifeCell
 * constructor.
 * 
 * @author sm053
 * 
 */
public interface TwoDBoard {

	/**
	 * Reverts all cells on the board to the state defined in the previous
	 * generation.
	 * 
	 * The GameOfLife calls this method.
	 */
	public void undo();

	/**
	 * Calculates the next state of each cell and updates the game board to the
	 * next generation.
	 * 
	 * The GameOfLife calls this method.
	 */
	public void update();

	/**
	 * Returns an ASCII representation of the board's current state. ASCII means
	 * a String that can be printed at the console and looks like the board with
	 * some characters representing live cell and dead cells (X and O or * and a
	 * space). The ASCII drawing will also need characters to represent the grid
	 * that the cells are in (_ and |). Carefully decide if the cell at location
	 * [0][0] should be printed at the top left or bottom left. Where did the
	 * GUI put this cell?
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * @return an ASCII representation of the board
	 */
	public String toString();

	/**
	 * Returns true if the cell at the given coordinate on the board is alive,
	 * otherwise returns false. This method calls a Cell method and returns the
	 * answer.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * @param x
	 *            the x-coordinate of the queried cell
	 * @param y
	 *            the y-coordinate of the queried cell
	 * @return the current liveness condition of the queried cell
	 */
	public boolean isAlive(int x, int y);

	/**
	 * Inverts the state of the cell at the given coordinate on the board. If
	 * the cell was alive, it will now be dead. If it was dead, it will now be
	 * alive. This method calls a Cell method.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * @param x
	 *            the x-coordinate of the queried cell
	 * @param y
	 *            the y-coordinate of the queried cell
	 */
	public void changeState(int x, int y);

	/**
	 * Return the size of the game board. For example, a 15x15 board will return
	 * a size of 15.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * @return the size of the game board
	 */
	public int getSize();

	/**
	 * Creates a two-dimensional array representing the game board. The array
	 * will be full of booleans representing whether each Cell is alive.
	 * 
	 * The GameOfLife calls this method.
	 * 
	 * @return the 2-d array of the game board
	 */
	public boolean[][] toArray();

	/**
	 * Declares the number of neighbors required for a cell to be born after a
	 * step in the simulation of the board.
	 * 
	 * The GameOfLife calls this method. This method also calls
	 * setBirthConditions method in GameOfLifeCell.
	 * 
	 * @param cond
	 *            ArrayList of integers representing the number of neighbors for
	 *            which a cell on the board will be born
	 */
	public void setBirthConditions(ArrayList<Integer> cond);

	/**
	 * Declares the number of neighbors required for a cell to stay alive after
	 * a step in the simulation of the board
	 * 
	 * The GameOfLife calls this method. This method also calls
	 * setStayAliveConditions method in GameOfLifeCell.
	 * 
	 * @param cond
	 *            ArrayList of integers representing the number of neighbors for
	 *            which a cell on the board will stay alive
	 */
	public void setStayAliveConditions(ArrayList<Integer> cond);

}
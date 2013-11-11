/**
 * Project: Game Of Life
 * File: GUIReady.java
 * Author: Shane Markstrum, sm053
 * Date: Jan 29, 2010
 */

/**
 * An interface for implementations of variants of Conway's Game of Life.
 * <P>
 * Your GameOfLife class will implement this interface. Your GameOfLife class
 * will have a TwoDBoard instance field (member data). When you instantiate the
 * TwoDBoard, you will call the GameOfLifeBoard constructor.
 * 
 * @author sm053
 * 
 */
public interface Game {

	/**
	 * Reverts all cells to their states defined in the previous generation.
	 */
	void undoBoard();

	/**
	 * Updates the board to the next generation.
	 * 
	 * The GameOfLifeGUI calls this method.
	 */
	void updateBoard();

	/**
	 * Returns the maximum generations to be run for the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the maximum generations to run
	 */
	int getMaxGenerations();

	/**
	 * Sets the maximum generations to be run for the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param maxGens
	 *            the maximum generations to run
	 */
	void setMaxGenerations(int maxGens);

	/**
	 * Returns the number of generations that have been run for the game
	 * instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the number of generations run for the game
	 */
	int getCurrentGeneration();

	/**
	 * Returns the initial probability of life for a cell in the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the initial probability of life for a cell
	 */
	double getInitialProbability();

	/**
	 * Sets the initial probability of life for a cell for a game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param initProb
	 *            the initial probability of life for a cell
	 */
	void setInitialProbability(double initProb);

	/**
	 * Returns the current size of the board for the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the current size of the game board
	 */
	int getBoardSize();

	/**
	 * Sets the size of the game board for when the game instance is
	 * re-initialized.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param boardSize
	 *            the size of future game boards
	 */
	void setBoardSize(int boardSize);

	/**
	 * Returns a reference to the current game board. True indicates a live
	 * cell.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the current game board
	 */
	boolean[][] getGameBoard();

	/**
	 * Sets the game board to the same state as the provided 2-d array. True
	 * indicates a live cell.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param gameBoard
	 *            the state to set the board.
	 */
	void setGameBoard(boolean[][] gameBoard);

	/**
	 * Using the stored values of the board size and initial probability of
	 * life, creates a new game board. Also resets the current number of
	 * generations counter to zero.
	 * 
	 * The GameOfLifeGUI calls this method.
	 */
	void reinitialize();

	/**
	 * Adds the provided number of generations to the maximum number of
	 * generations for the game.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param numGens
	 *            the number of generations to extend the game.
	 */
	void extendGame(int numGens);

	/**
	 * Returns true if the game finishing conditions are met. Otherwise, returns
	 * false.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the current liveness status of the game
	 */
	boolean isFinished();

	/**
	 * Sets the allowed number of neighbors that will result in a cell being
	 * born.
	 * 
	 * @param conditions
	 *            the number of neighbors that will result in a cell being born
	 * @return true if the conditions were stored correctly
	 */
	boolean setBirthConditions(String conditions);

	/**
	 * Sets the allowed number of neighbors that will result in a cell staying
	 * alive.
	 * 
	 * @param conditions
	 *            the number of neighbors that will result in a cell staying
	 *            alive in a generation
	 * @return true if the conditions were stored correctly
	 */
	boolean setStayAliveConditions(String conditions);
}

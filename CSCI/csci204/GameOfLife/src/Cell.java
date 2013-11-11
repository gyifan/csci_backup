/**
 * CSCI 204, Shane Markstrum
 * Assignment: P1
 * Created: Sep 4, 2009, 2:06:03 PM
 */

/**
 * An interface representing a Cell in Conway's Game of Life.
 * 
 * Your GameOfLifeCell will implement this interface.
 * 
 * @author sm053
 * 
 */
public interface Cell {

	/*
	 * Hint: A Cell might also need to determine whether it is initially dead or
	 * alive.
	 */

	/**
	 * Sets the neighbors of the Cell.
	 * 
	 * The GameOfLifeBoard calls this method.
	 * 
	 * @param neighbors
	 */
	public void setNeighbors(Cell[][] neighbors);

	/**
	 * Updates the state of the Cell to the previous generation.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public void undo();

	/**
	 * Updates the state of the Cell to the next generation.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public void update();

	/**
	 * Calculates the state of the Cell for the next generation.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public void calculateNextState();

	/**
	 * Returns the current status of the Cell.
	 * 
	 * The GameOfLifeBoard calls this method.
	 * 
	 * @return the Cell's status
	 */
	public boolean isAlive();

	/**
	 * Changes the state of the cell. If it was alive, it is now dead. If it was
	 * dead, it is now alive.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public void changeState();
}

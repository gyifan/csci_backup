import java.awt.Point;

/**
 * Project: Maze Escaping Robots!!!
 * File: IRobot.java
 * Author: Shane Markstrum, sm053
 * Date: Oct 8, 2009
 */

/**
 * A robot interface for use with the MazeVizualizer GUI.
 * 
 * @author sm053
 * 
 */
public interface IRobot {

	/**
	 * Returns the current number of moves that the robot has made.
	 * 
	 * @return the robot's move count
	 */
	public int getMoveCount();

	/**
	 * Returns the current location of the robot as a coordinate: column (x) and
	 * row (y).
	 * 
	 * @return the current location of the robot
	 */
	public Point getLocation();

	/**
	 * Returns the current direction that the robot is facing. Direction can be
	 * interpreted via the direction constants.
	 * 
	 * @return the direction the robot is currently facing.
	 */
	public Mark getDirection();

	/**
	 * Puts robot at the entrance to a maze and resets its move counter.
	 * 
	 * @param m
	 *            the new maze
	 */
	public void enter(IMaze m);

	/**
	 * Moves robot until ending conditions are met.
	 * 
	 */
	public void runToEnd();

	/**
	 * Move the robot a single move.
	 */
	public void step();

}

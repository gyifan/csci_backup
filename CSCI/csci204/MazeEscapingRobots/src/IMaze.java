import java.awt.Point;

/**
 * Project: Maze Escaping Robots!!!
 * File: IMaze.java
 * Author: Shane Markstrum, sm053
 * Author: Lea Wittie, lwittie
 * Date: Oct 8, 2009
 * Updated: Feb 9, 2011
 */

/**
 * A maze interface for use with the MazeVizualizer GUI. The Maze class must
 * implement this interface.
 * 
 * @author sm053
 * @author lwittie
 * 
 */
public interface IMaze {

	/**
	 * Returns the number of columns found in the maze.
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @return number of columns
	 */
	public int getNumCols();

	/**
	 * Returns the number of rows found in the maze.
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @return number of rows
	 */
	public int getNumRows();

	/**
	 * Returns the name of the file from which the maze was constructed.
	 * <P>
	 * Called by MazeVisualizer methods
	 * 
	 * @return the maze's filename
	 */
	public String getFilename();

	/**
	 * Returns the location of the maze's entrance.
	 * 
	 * @return the location of the maze's entrance.
	 */
	public Point getStartingPoint();

	/**
	 * Determines whether the provided coordinates are a wall in the maze or
	 * not. The x coordinate determines the column (starting at 0 on the left),
	 * while the y coordinate determines the row (starting at 0 on the top).
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @param x
	 *            the column
	 * @param y
	 *            the row
	 * @return whether the coordinates indicate a wall
	 */
	public boolean isWall(int x, int y);

	/**
	 * Determines whether the provided coordinates are an exit in the maze or
	 * not. The x coordinate determines the column (starting at 0 on the left),
	 * while the y coordinate determines the row (starting at 0 on the top).
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @param x
	 *            the column
	 * @param y
	 *            the row
	 * @return whether the coordinates indicate a maze exit
	 */
	public boolean isExit(int x, int y);

	/**
	 * Count how many times the provided coordinates are a hallway that has been
	 * visited. The x coordinate determines the column (starting at 0 on the
	 * left), while the y coordinate determines the row (starting at 0 on the
	 * top).
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @param x
	 *            the column
	 * @param y
	 *            the row
	 * @return how many times the coordinates indicated have been visited
	 */
	public int visited(int x, int y);

	/**
	 * Reset all hallways to be unvisited.
	 * <P>
	 * Called by MazeVisualizer methods
	 */
	public void resetVisited();

	/**
	 * Increments the visitation record at the given location by one.
	 * 
	 * Called by Robot class and its subclasses.
	 * 
	 * @param location
	 *            the desired location
	 */
	public void recordVisitation(Point location);
}

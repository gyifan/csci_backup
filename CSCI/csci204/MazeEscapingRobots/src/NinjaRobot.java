/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Mar 1, 2011, 12:40:28 AM
 */

import java.awt.Point;

/**
 * This class is a NinjaRobot that inherits from the abstract Robot class. It
 * has all the same instance data and methods as every other Robot. It
 * implements the abstract method <code>calculateNext()</code> based on choosing
 * the least visited path and teleporting itself 4 steps forward every 20
 * steps.If the 4th block is a wall, Ninja robot will be blocked by the wall and
 * arrives at the 3rd block.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public class NinjaRobot extends Robot {

	// Class Constants

	/** Integer representation for the front neighbor */
	private static final int FRONT = 0;

	/** Integer representation for the right neighbor */
	private static final int RIGHT = 1;

	/** Integer representation for the left neighbor */
	private static final int LEFT = 2;

	/** Integer representation for the back neighbor */
	private static final int BACK = 3;

	/** Default visit count value for walls */
	private static final int WALL = 100;

	/** Defines how many spaces the robot will teleport */
	private static final int TELEPORTABILITY = 20;

	// Instance Fields

	/**
	 * Array of integers that holds the information of its neighbors' visit
	 * count
	 */
	private int[] neighborVisitCounts;

	/**
	 * Construct a memory Robot by calling the parent constructor and
	 * initializing local member data.
	 */
	public NinjaRobot() {
		super();
		neighborVisitCounts = new int[4];
	}

	/*
	 * (non-Javadoc)
	 * 
	 * Determines the next move of the Ninja robot. The Ninja robot always
	 * choose the path with the lowest visit count and teleport itself every 20
	 * moves.
	 * 
	 * Called by the robot class.
	 * 
	 * It calls isWall and recordVisitation in Imaze class. It also calls
	 * getDirectionLeftOf, getDirectionRightOf in Robot class and
	 * getNextDirection, calculateLowestCounts, teleport methods from its own
	 * class.
	 * 
	 * @see Robot#calculateNext()
	 */
	@Override
	public void calculateNext() {
		if (moveCounter % 20 == 10) {
			teleport();
		} else {
			updateNeighbors();

			// Checks if the robot faces a wall.
			if (maze.isWall(frontPoint.x, frontPoint.y)) {
				neighborVisitCounts[FRONT] = WALL;
				if (maze.isWall(rightPoint.x, rightPoint.y))
					nextDirection = getDirectionLeftOf(direction);
				else if (maze.isWall(leftPoint.x, leftPoint.y))
					nextDirection = getDirectionRightOf(direction);
				else {
					nextDirection = getNextDirection(calculateLowestCounts());
				}
			} else {

				// When the robot is not facing wall, checks if its neighbors
				// are
				// walls.
				if (maze.isWall(rightPoint.x, rightPoint.y))
					neighborVisitCounts[RIGHT] = WALL;
				if (maze.isWall(leftPoint.x, leftPoint.y))
					neighborVisitCounts[LEFT] = WALL;
				if (maze.isWall(backPoint.x, backPoint.y))
					neighborVisitCounts[BACK] = WALL;
				if (calculateLowestCounts() == FRONT) {
					nextLocation = frontPoint;
					maze.recordVisitation(location);
				} else
					nextDirection = getNextDirection(calculateLowestCounts());
			}
		}
	}

	/**
	 * Updates the information of the robot neighbors.
	 * 
	 * Called by calculateNext method and calls getPointInFrontOf,
	 * getPointAtBackOf, getDirectionRightOf, and getDirectionLeftOf method in
	 * Robot class.
	 */
	private void updateNeighbors() {
		frontPoint = getPointInFrontOf(location, direction);
		rightPoint = getPointInFrontOf(location, getDirectionRightOf(direction));
		leftPoint = getPointInFrontOf(location, getDirectionLeftOf(direction));
		backPoint = getPointAtBackOf(location, direction);

		neighborVisitCounts[FRONT] = maze.visited(frontPoint.x, frontPoint.y);
		neighborVisitCounts[RIGHT] = maze.visited(rightPoint.x, rightPoint.y);
		neighborVisitCounts[LEFT] = maze.visited(leftPoint.x, leftPoint.y);
		neighborVisitCounts[BACK] = maze.visited(backPoint.x, backPoint.y);
	}

	/**
	 * Calculates and returns the location of the neighbor with the lowest visit
	 * count.
	 * 
	 * Called by calculateNext method.
	 * 
	 * @return the integer representation of location of the least visited
	 *         neighbor.
	 */
	private int calculateLowestCounts() {
		int lowestCounts = WALL;
		int position = FRONT;
		for (int i = 0; i < 4; i++) {
			if (lowestCounts > neighborVisitCounts[i]) {
				lowestCounts = neighborVisitCounts[i];
				position = i;
			}
		}
		return position;
	}

	/**
	 * Gets the next direction for the robot, which will help the robot to face
	 * to the least visited location.
	 * 
	 * Called by calculateNext method and calls getDirectionLeftOf and
	 * getDirectionRightOf methods in robot class. jump over the wall
	 * 
	 * @param position
	 *            the least visited location
	 * @return The next direction
	 */
	private Mark getNextDirection(int position) {
		if (position == LEFT)
			return getDirectionLeftOf(direction);
		else
			return getDirectionRightOf(direction);

	}

	/**
	 * Teleport the robot to its designed location based on its teleportability.
	 * 
	 * Calls getTeleportPoint method and is called by calculateNext method.
	 */
	private void teleport() {
		nextLocation = getTeleportPoint();
	}

	/**
	 * Calculates the location to teleport. If that location is a wall, it will
	 * be the first non-wall location. Also the location has to stay inside the
	 * maze.
	 * 
	 * Calls isWall, getNumCols, and getNumRows from maze class; is called by
	 * teleport method.
	 * 
	 * @return the point of the location to teleport
	 */
	private Point getTeleportPoint() {
		Point p = location;
		if (direction == Mark.NORTH) {
			p = new Point(location.x, location.y - TELEPORTABILITY);
			if (p.y < 0)
				p.setLocation(location.x, 0);
			while (maze.isWall(p.x, p.y))
				p.setLocation(p.x, p.y + 1);
		} else if (direction == Mark.EAST) {
			p = new Point(location.x + TELEPORTABILITY, location.y);
			if (p.x > maze.getNumCols() - 1)
				p.setLocation(maze.getNumCols() - 1, location.y);
			while (maze.isWall(p.x, p.y))
				p.setLocation(p.x - 1, p.y);
		} else if (direction == Mark.SOUTH) {
			p = new Point(location.x, location.y + TELEPORTABILITY);
			if (p.y > maze.getNumRows() - 1)
				p.setLocation(location.x, maze.getNumRows() - 1);
			while (maze.isWall(p.x, p.y))
				p.setLocation(p.x, p.y - 1);
		} else if (direction == Mark.WEST) {
			p = new Point(location.x - TELEPORTABILITY, location.y);
			if (p.x < 0)
				p.setLocation(0, location.y);
			while (maze.isWall(p.x, p.y))
				p.setLocation(p.x + 1, p.y);
		}
		return p;
	}
}

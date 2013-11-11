/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Feb 20, 2011, 1:38:41 PM
 * Updated: Mar 08, 2011, 4:59:00 PM
 * Version: 1.0
 */

/*
 * PROBLEM STATEMENT:
 * The purpose of this assignment is to implement using Java the game of
 * "Maze Escaping Robots!!!"  This includes writing classes to define the
 * actual maze and the different kinds of robots able to navigate the maze.
 * The GUI for this assignment has been provided, but we must ensure the
 * implementation of all the classes and methods needed for the GUI to operate.
 * From a user's point of view, he or she will be able to load different mazes
 * and robots and allow the robot to traverse the paths of the maze, either
 * continuously or step by step.
 * 
 * TECHNICAL DESCRIPTION:
 * This program needs to use 2D arrays to keep track of all the information
 * regarding the maze and any knowledge a robot may be able to acquire as
 * it proceeds through the maze.  This program also uses the concept of
 * inheritance through the implementation of an abstract robot class, which
 * defines a generic robot, so that all the specialized robots can "inherit"
 * from this class.  Exception handling is also needed to manage errors and
 * to define what happens to the game once the robot exits the maze or has
 * taken to many moves.
 */

import java.awt.Point;

/**
 * This abstract Robot class defines the generic characteristics of a Robot
 * object. This includes member data and methods that are common to any robot
 * trying to escape from a maze.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public abstract class Robot implements IRobot {

	// class constants

	/** The maximum number of moves before the robot gives up. */
	private static final int MAX_MOVE = 10000;

	// instance data

	/** Records the number of move the robot has performed. */
	public int moveCounter;

	/** Holds the current placement of the robot. */
	public Point location;

	/** Determines where the robot is pointing. */
	public Mark direction;

	/** Holds the next spot where the robot will move. */
	public Point nextLocation;

	/** Determines the next direction that the robot will be pointing. */
	public Mark nextDirection;

	/** Holds the location for the point on the right of the robot */
	public Point rightPoint;

	/** Holds the location for the point on the left of the robot */
	public Point leftPoint;

	/** Holds the location for the point in the front of the robot */
	public Point frontPoint;

	/** Holds the location for the point behind the robot */
	public Point backPoint;

	/** Stores the information about the maze that robot is current in. */
	public IMaze maze;

	// constructors

	/**
	 * Constructs a default Robot object and initializes everything to zero or
	 * to null.
	 */
	public Robot() {
		moveCounter = 0;
		location = null;
		direction = null;
		nextLocation = null;
		nextDirection = null;
	}

	// methods

	/**
	 * Puts robot at the entrance to a maze and resets its move counter.
	 * 
	 * Calls the getStartingPoint and isWall methods in Maze class.
	 * 
	 * Called by MazeVizualizer class
	 * 
	 * @param m
	 *            the new maze
	 */
	public void enter(IMaze m) {
		location = m.getStartingPoint();
		maze = m;
		moveCounter = 0;
		if (!m.isWall(location.x, location.y - 1))
			direction = Mark.NORTH;
		else if (!m.isWall(location.x + 1, location.y))
			direction = Mark.EAST;
		else if (!m.isWall(location.x, location.y + 1))
			direction = Mark.SOUTH;
		else if (!m.isWall(location.x - 1, location.y))
			direction = Mark.WEST;
		nextDirection = direction;
		nextLocation = location;
		calculateNext();
	}

	/**
	 * Returns the current direction that the robot is facing. Direction can be
	 * interpreted via the direction constants.
	 * 
	 * Called by MazePanel
	 * 
	 * @return the direction the robot is currently facing.
	 */
	public Mark getDirection() {
		return direction;
	}

	/**
	 * Returns the current location of the robot as a coordinate: column (x) and
	 * row (y).
	 * 
	 * Called by MazePanel
	 * 
	 * @return the current location of the robot
	 */
	public Point getLocation() {
		return location;
	}

	/**
	 * Returns the current number of moves that the robot has made.
	 * 
	 * Called by MazeVizualizer
	 * 
	 * @return the robot's move count
	 */
	public int getMoveCount() {
		return moveCounter;
	}

	/**
	 * Moves robot until ending conditions are met.
	 * 
	 * Called by MazeVizualizer and calls step method.
	 * 
	 * Calls the step method.
	 * 
	 */
	public void runToEnd() {
		while (true)
			step();
	}

	/**
	 * Moves the robot a single move. This method throws a RobotEscapeException
	 * if the robot has made too many moves or has escaped.
	 * 
	 * Called by MazeVizualizer and calls calculateNext method.
	 * 
	 */
	public void step() {
		nextLocation = location;
		nextDirection = direction;

		calculateNext();

		location = nextLocation;
		direction = nextDirection;

		moveCounter++;
		if (moveCounter > MAX_MOVE) {
			throw new RobotEscapeException("The robot moved " + moveCounter
					+ " steps and is hopelessly lost.");
		} else if (maze.isExit(location.x, location.y)) {
			throw new RobotEscapeException(
					"The robot has successfully escaped within " + moveCounter
							+ " steps.");
		}
	}

	/**
	 * Calculates and returns the direction left of the Robot based on four
	 * cases.
	 * 
	 * Called by robot subclasses
	 * 
	 * @param m
	 *            the current direction of the Robot
	 * @return the direction left of the Robot
	 */
	public Mark getDirectionLeftOf(Mark m) {
		if (m == Mark.NORTH) {
			return Mark.WEST;
		} else if (m == Mark.WEST) {
			return Mark.SOUTH;
		} else if (m == Mark.SOUTH) {
			return Mark.EAST;
		} else if (m == Mark.EAST) {
			return Mark.NORTH;
		} else {
			throw new IllegalStateException(
					"I don't really know what you're trying to do here...");
		}
	}

	/**
	 * Calculates and returns the direction right of the Robot based on four
	 * cases.
	 * 
	 * Called by robot subclasses
	 * 
	 * @param m
	 *            the current direction of the Robot
	 * @return the direction right of the Robot
	 */
	public Mark getDirectionRightOf(Mark m) {
		if (m == Mark.NORTH) {
			return Mark.EAST;
		} else if (m == Mark.WEST) {
			return Mark.NORTH;
		} else if (m == Mark.SOUTH) {
			return Mark.WEST;
		} else if (m == Mark.EAST) {
			return Mark.SOUTH;
		} else {
			throw new IllegalStateException(
					"I don't really know what you're trying to do here...");
		}
	}

	/**
	 * Calculates and returns the point in the maze in front of the Robot.
	 * 
	 * Called by robot subclasses
	 * 
	 * @param p
	 *            the current location of the Robot
	 * @param m
	 *            the current direction of the Robot
	 * @return the point in front of the Robot
	 */
	public Point getPointInFrontOf(Point p, Mark m) {
		if (m == Mark.NORTH) {
			return new Point(p.x, p.y - 1);
		} else if (m == Mark.SOUTH) {
			return new Point(p.x, p.y + 1);
		} else if (m == Mark.EAST) {
			return new Point(p.x + 1, p.y);
		} else if (m == Mark.WEST) {
			return new Point(p.x - 1, p.y);
		} else {
			throw new IllegalStateException(
					"The robot can't exist in the state specified in the provided Mark.");
		}
	}

	/**
	 * Calculates and returns the point in the maze behind the robot.
	 * 
	 * Called by robot subclasses
	 * 
	 * @param p
	 *            the current location of the robot
	 * @param m
	 *            the current direction of the robot
	 * @return
	 */
	public Point getPointAtBackOf(Point p, Mark m) {
		if (m == Mark.NORTH)
			return new Point(p.x, p.y + 1);
		else if (m == Mark.SOUTH)
			return new Point(p.x, p.y - 1);
		else if (m == Mark.EAST)
			return new Point(p.x - 1, p.y);
		else if (m == Mark.WEST)
			return new Point(p.x + 1, p.y);
		else
			throw new IllegalStateException(
					"The robot can't exist in the state specified in the provided Mark.");
	}

	// abstract methods

	/**
	 * Calculates the next location and next direction of the robot and updates
	 * the member data. To move the robot in some way, the code inside
	 * <code>calculateNext()</code> should update the <code>nextLocation</code>
	 * and <code>nextDirection</code> instance fields.
	 * 
	 * Called by step method.
	 * 
	 */
	public abstract void calculateNext();

}

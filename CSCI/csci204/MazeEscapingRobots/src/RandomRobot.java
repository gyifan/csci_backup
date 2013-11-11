/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Feb 20, 2011, 1:40:08 PM
 */

import java.awt.Point;

/**
 * This class is a RandomRobot that inherits from the Robot class. It has all
 * the same instance data and methods as any other Robot, but it implements the
 * abstract method <code>calculateNext()</code> in a unique manner which entails
 * random behavior.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public class RandomRobot extends Robot {

	/**
	 * Constructs a RandomRobot by only calling the parent constructor.
	 */
	public RandomRobot() {
		super();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * This uses a pretty simple algorithm to move the robot through the maze.
	 * If there's no wall in front of the robot, he can move forward, turn left,
	 * or turn right. If there is a wall in front of the robot, he can only turn
	 * left or right. As you may have guessed, the robot randomly chooses
	 * between his options. If the robot is facing a wall, the random robot will
	 * have equal chance of turning right or left. If the robot is not facing a
	 * wall, the random robot will have 50% chance to take a step forward and
	 * 25% for both turning right and left.
	 * 
	 * Calls isWall and recordVisitation method from Imaze class.
	 * 
	 * @see Robot#calculateNext()
	 */
	public void calculateNext() {
		Point nextPoint = getPointInFrontOf(this.location, this.direction);

		if (this.maze.isWall(nextPoint.x, nextPoint.y)) {
			// the point in front of us is a wall, we need to turn

			if (Math.random() >= 0.5) { // turn left
				this.nextDirection = getDirectionLeftOf(this.direction);
			} else {
				this.nextDirection = getDirectionRightOf(this.direction);
			}
		} else {
			int choice = (int) (4 * Math.random());
			if (choice <= 1) {
				this.nextLocation = nextPoint;
				maze.recordVisitation(location);
			} else if (choice == 2) { // turn left
				this.nextDirection = getDirectionLeftOf(this.direction);
			} else if (choice == 3) {
				this.nextDirection = getDirectionRightOf(this.direction);
			}
		}
	}

}

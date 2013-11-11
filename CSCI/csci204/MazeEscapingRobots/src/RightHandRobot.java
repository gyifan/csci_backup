/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Feb 20, 2011, 1:43:42 PM
 */

/**
 * This class is a RightHandRobot that inherits from the abstract Robot class.
 * It has all the same instance data and methods as every other Robot. It
 * implements the abstract method <code>calculateNext()</code> based on always
 * wanting to keep its right side next to a wall.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public class RightHandRobot extends Robot {

	/** Determines whether the Robot has its hand on a wall yet. */
	private boolean isOnWall;

	/**
	 * Constructs a RightHandRobot by calling the parent constructor and
	 * initializing isOnWall to false.
	 */
	public RightHandRobot() {
		super();
		isOnWall = false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * Determines the next move of the RightHandRobot. If there is no wall to
	 * the right, it must has passed the wall, so it will turn right and be
	 * ready to move forward next turn. If there is a wall in front, it must
	 * turn left to keep its right hand on the wall. If none of these cases
	 * apply, it will just move forward (with its right hand on the wall). It
	 * will also just move forward until it touches a wall if it does not spawn
	 * already touching a wall.
	 * 
	 * @see Robot#calculateNext()
	 */
	@Override
	public void calculateNext() {
		frontPoint = getPointInFrontOf(location, direction);
		rightPoint = getPointInFrontOf(location, getDirectionRightOf(direction));

		if (moveCounter == 0 && maze.isWall(rightPoint.x, rightPoint.y)) {
			// checks for a wall on the right from the onset
			isOnWall = true;
		}

		if (isOnWall) {
			if (!maze.isWall(rightPoint.x, rightPoint.y)) {
				// passed wall and needs to turn right
				nextDirection = getDirectionRightOf(direction);
				isOnWall = false;
			} else if (maze.isWall(frontPoint.x, frontPoint.y)) {
				// the point in front of us is a wall, we need to turn left
				nextDirection = getDirectionLeftOf(direction);
			} else {
				// just moves forward
				nextLocation = frontPoint;
				maze.recordVisitation(location);
			}
		} else {
			if (maze.isWall(rightPoint.x, rightPoint.y)) {
				// check to see if its right hand is on a wall
				isOnWall = true;
				if (maze.isWall(frontPoint.x, frontPoint.y))
					nextDirection = getDirectionLeftOf(direction);
				else {
					nextLocation = frontPoint;
					maze.recordVisitation(location);
				}
			} else if (maze.isWall(frontPoint.x, frontPoint.y)) {
				// check to see if it reached a wall
				isOnWall = true;
				nextDirection = getDirectionLeftOf(direction);
				maze.recordVisitation(location);
			} else {
				// move forward
				nextLocation = frontPoint;
				maze.recordVisitation(location);
			}
		}
	}

}

/**
 * Project: 
 * File: RobotEscapeException.java
 * Author: Shane Markstrum, sm053
 * Date: Sep 30, 2009
 */

/**
 * @author sm053
 * 
 *         This exception should be thrown when the robot has made too many
 *         moves and is hopelessly lost or is standing on an EXIT mark and has
 *         thus escaped the maze. This exception is thrown by Robot.java and
 *         caught by MazeVisualizer.java.
 */
public class RobotEscapeException extends RuntimeException {

	private static final long serialVersionUID = -1803914538117492318L;

	private String msg;

	public RobotEscapeException(String msg) {
		this.msg = msg;
	}

	public String getMessage() {
		return msg;
	}
}

/**
 * CSCI 204, Rick Zaccone with ideas from Todd Neller and Scott Russell
 * Mar 14, 2008, 3:28:26 PM
 */

/**
 * @author zaccone
 * 
 */
public enum Mark {
	/*
	 * See Big Java 4 page 194 for information on enums. This enum uses advanced
	 * features of Java.
	 * 
	 * The possible marks are named WALL, EMPTY, etc.. Each of these calls the
	 * Mark constructor with a character so that it is an instance of a Mark
	 * object.
	 * 
	 * Your code will access the possible Marks as such: Mark m = Mark.WALL;
	 */
	WALL('*'), EMPTY(' '), START('S'), EXIT('X'), // Maze markings
	NORTH('^'), EAST('>'), SOUTH('v'), WEST('<'), // Robot markings
	ERROR('?');

	/** The character that the mark stands for */
	private char marker;

	/**
	 * Constructor to make a Mark object from a character. Only the enum
	 * Mark.java calls this constructor. (Do not call this constructor
	 * yourself).
	 * 
	 * @param marker
	 *            the character to store
	 */
	Mark(char marker) {
		this.marker = marker;
	}

	/**
	 * Gets the maze mark as a character. Used by the Maze to comprehend
	 * markings in a maze file and to toString a Maze.
	 * <P>
	 * Use this as such: Mark.NORTH.getChar(); or mark.getChar();
	 * 
	 * @return the marker as a character
	 */
	public char getChar() {
		return marker;
	}

}

/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Feb 20, 2011, 1:04:36 PM
 */

import java.awt.Point;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This class represents a 2D maze. It takes a ".txt." file when an instance of
 * the class is instantiated and converts it into a 2D array which then defines
 * the maze. It also contains methods that return information concerning the
 * maze.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public class Maze implements IMaze {

	// instance data

	/** The 2 dimensional array of characters to represent the maze. */
	private char[][] maze;

	/** The file that stores the information of the maze. */
	private File mazeFile;

	/** The record of how many times the robot visited each location. */
	private int[][] visitCounters;

	/** The Point at which the robot begins the maze. */
	private Point startingPoint;

	// constructor

	/**
	 * Constructs a maze object by reading information from a File object. It
	 * uses the Scanner class to read the file and stores the information in the
	 * instant fields. The algorithm is using scanner to store lines to an
	 * ArrayList and then uses charAt() method in String class to store each
	 * character to the 2-D character array.
	 * 
	 * MazePanel calls this method.
	 * 
	 * @param fileName
	 *            the name of the file.
	 * @throws IOException
	 */
	public Maze(String fileName) throws IOException {
		// regenerate random maze every time it is loaded
		if (fileName.equals("random.txt"))
			new RandomMazeGenerator();

		mazeFile = new File(fileName);
		System.out.println("Loading maze from " + mazeFile.getName());
		ArrayList<String> lines = new ArrayList<String>();
		Scanner in = new Scanner(mazeFile);
		while (in.hasNextLine())
			lines.add(in.nextLine());
		maze = new char[lines.size()][lines.get(0).length()];
		System.out.printf("Maze height is %d and width is %d\n", lines.size(),
				lines.get(0).length());
		for (int row = 0; row < maze.length; row++) {
			for (int col = 0; col < maze[row].length; col++) {
				maze[row][col] = lines.get(row).charAt(col);
				if (maze[row][col] == 'S') {
					System.out.printf("Starting point is %d, %d\n", col, row);
					startingPoint = new Point(col, row);
				}
			}
		}
		visitCounters = new int[maze.length][maze[0].length];
		System.out.println(visitCounters.length + "" + visitCounters[0].length);
	}

	// methods

	/**
	 * Returns the name of the file from which the maze was constructed.
	 * <P>
	 * Called by MazeVisualizer methods
	 * 
	 * @return the maze's filename
	 */
	public String getFilename() {
		return mazeFile.getName();
	}

	/**
	 * Returns the number of columns found in the maze.
	 * <P>
	 * Called by MazePanel methods index
	 * 
	 * @return number of columns
	 */
	public int getNumCols() {
		return maze[0].length;
	}

	/**
	 * Returns the number of rows found in the maze.
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @return number of rows
	 */
	public int getNumRows() {
		return maze.length;
	}

	/**
	 * Returns the location of the maze's entrance.
	 * 
	 * This method is called by Robot method.
	 * 
	 * @return the location of the maze's entrance.
	 */
	public Point getStartingPoint() {
		return startingPoint;
	}

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
	public boolean isExit(int x, int y) {
		try {
			return maze[y][x] == 'X';
		} catch (ArrayIndexOutOfBoundsException ex) {
			return false;
		}
	}

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
	public boolean isWall(int x, int y) {
		try {
			return maze[y][x] == '*';
		} catch (ArrayIndexOutOfBoundsException ex) {
			return false;
		}
	}

	/**
	 * Resets all hallways to be unvisited.
	 * <P>
	 * Called by MazeVisualizer methods
	 */
	public void resetVisited() {
		for (int row = 0; row < visitCounters.length; row++) {
			for (int col = 0; col < visitCounters[row].length; col++) {
				visitCounters[row][col] = 0;
			}
		}

	}

	/**
	 * Counts how many times the provided coordinates are a hallway that has
	 * been visited. The x coordinate determines the column (starting at 0 on
	 * the left), while the y coordinate determines the row (starting at 0 on
	 * the top).
	 * <P>
	 * Called by MazePanel methods
	 * 
	 * @param x
	 *            the column
	 * @param y
	 *            the row
	 * @return how many times the coordinates indicated have been visited
	 */
	public int visited(int x, int y) {
		return visitCounters[y][x];
	}

	/**
	 * Increments the visitCounter for the given point.
	 * 
	 * Called by robot classes.
	 * 
	 * @param position
	 *            the point that robot visited
	 */
	public void recordVisitation(Point position) {
		visitCounters[position.y][position.x]++;
	}

	/**
	 * Converts the maze object to a string. The wall is represented by
	 * asterisks(*). "X" and "S" represent the exit and starting point,
	 * respectively.
	 * 
	 * @return the string that represents the maze object
	 */
	public String toString() {
		String mazeString = "";
		for (int row = 0; row < maze.length; row++) {
			for (int col = 0; col < maze[row].length; col++) {
				mazeString += maze[row][col];
			}
			mazeString += "\n";
		}
		return mazeString;
	}

}

/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 */

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * This Class will generate a random maze based on given class constants and
 * pseudo-random numbers. There will always be a start and an exit, and there
 * will always be a path between the two.
 * 
 * @author klt018
 * 
 */
public class RandomMazeGenerator {

	// class constants

	/** Number of rows to the maze. */
	private final int ROWS = 20;

	/** Number of columns to the maze. */
	private final int COLS = 20;

	/** Probability of a wall spawning randomly. */
	private final double WALL_PROB = 0.5;

	// instance datum

	/** 2-D array for holding the maze. */
	private char[][] maze;

	// constructor

	/**
	 * Generates a new random maze.
	 * 
	 * @throws IOException
	 */
	public RandomMazeGenerator() throws IOException {
		maze = new char[ROWS][COLS];
		generate();
		print();
	}

	// methods

	/**
	 * Fills the 2-D array with a randomly created maze.
	 */
	private void generate() {
		// fill with all walls
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++)
				maze[i][j] = '*';
		}

		// randomly place spaces within the border of the maze
		for (int i = 1; i < ROWS - 1; i++) {
			for (int j = 1; j < COLS - 1; j++) {
				if (Math.random() > WALL_PROB)
					maze[i][j] = ' ';
			}
		}

		// ensures a path to the exit
		int i = 1, j = 1;
		while ((i < ROWS - 2) | (j < COLS - 2)) {
			if ((Math.random() < 0.5) && (i < ROWS - 2))
				i++;
			else if (j < COLS - 2)
				j++;
			maze[i][j] = ' ';
		}

		// always have a start and exit
		maze[1][1] = 'S';
		maze[ROWS - 1][COLS - 2] = 'X';
	}

	/**
	 * Writes the 2-D array to a text file for later use by the
	 * <code>Maze</code> class.
	 * 
	 * @throws IOException
	 */
	private void print() throws IOException {
		FileWriter writer = new FileWriter(new File("random.txt"));

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++)
				writer.append(maze[i][j]);
			writer.append("\n");
		}

		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new RandomMazeGenerator();
	}

}

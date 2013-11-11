/**
 * CSCI 204, Yifan Ge, Kevin Thomas, Davis Gallinghouse
 * Assignment MazeEscapingRobots
 * Created: Feb 26, 2011, 1:02:12 PM
 */

import java.io.IOException;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the Maze class by testing its constructor and methods.
 * 
 * @author Yifan Ge
 * @author Kevin Thomas
 * @author Davis Gallinghouse
 * 
 */
public class MazeTest {

	private Maze test;

	/**
	 * Instantiates a Maze object every time a test is run.
	 * 
	 * @throws IOException
	 */
	@Before
	public void setUp() throws IOException {
		test = new Maze("maze1.txt");
	}

	/**
	 * Expects an IOException to be thrown when instantiating a Maze object with
	 * a file which does not exist.
	 * 
	 * @throws IOException
	 */
	@Test(expected = IOException.class)
	public void testConstructor() throws IOException {
		test = new Maze("maze0.txt");
	}

	/**
	 * Uses the instance of the Maze class to test all the methods it needs to
	 * use. We expect no exceptions.
	 */
	@Test
	public void testMethods() {
		System.out.println(test.getNumCols() + " " + test.getNumRows()
				+ test.getFilename() + " " + test.getStartingPoint());
		System.out.println(test);
	}

	/**
	 * Removes reference from instance variable to instantiated object.
	 */
	@After
	public void tearDown() {
		test = null;
	}

}

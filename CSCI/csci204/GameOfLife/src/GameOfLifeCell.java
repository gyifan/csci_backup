import java.util.ArrayList;

/**
 * CSCI 204, Yifan Ge
 * Assignment GameOfLife
 * Created: Feb 3, 2011, 2:00:28 AM
 */

/**
 * This class implement the Cell class. By creating objects that has the
 * property of life, this class has constructor and method to retreat the life
 * property of the cell object and update this property for the next generation
 * depending on the status of its neighbors.
 * 
 * @author Yifan Ge
 * @author Michael Davis
 * 
 */
public class GameOfLifeCell implements Cell {
	/**
	 * ArrayList containing the numbers of neighbors required for a cell to be
	 * born.
	 */
	private static ArrayList<Integer> birthConditions;

	/**
	 * ArrayList containing the numbers of neighbors required for a cell to stay
	 * alive.
	 */
	private static ArrayList<Integer> stayAliveConditions;

	/**
	 * The life status of cells. Cells can be alive or dead.
	 */
	private boolean life;

	/**
	 * The number of living neighbors.
	 */
	private int numOfLifeNeighbors;

	/**
	 * The life status of cell in the next generation.
	 */
	private boolean nextLife;

	/**
	 * The previous life states of the cell.
	 */
	private ArrayList<Boolean> previousLives = new ArrayList<Boolean>();

	/**
	 * Constructs a cell object with specific birthConditions and
	 * stayAliveConditions, which sets the cell to be dead for this and the
	 * following generation, number of living neighbors to 0.
	 */
	public GameOfLifeCell() {
		life = false;
		nextLife = false;
		numOfLifeNeighbors = 0;
	}

	/**
	 * Sets the number of alive neighbors. The GameOfLifeBoard calls this
	 * method.
	 * 
	 * @param neighbors
	 *            the 2-D array of cells surrounding the cell.
	 */
	@Override
	public void setNeighbors(Cell[][] neighbors) {
		numOfLifeNeighbors = 0;

		for (int i = 0; i < neighbors.length; i++) {
			for (int j = 0; j < neighbors[i].length; j++) {
				if (neighbors[i][j].isAlive())
					numOfLifeNeighbors++;
			}
		}
	}

	/**
	 * Declares the conditions for which a cell will be born.
	 * 
	 * The GameOfLifeBoard calls this method.
	 * 
	 * @param conditions
	 *            an ArrayList of numbers representing the number of neighbors
	 *            for which a cell will stay alive
	 */
	public static void setBirthConditions(ArrayList<Integer> conditions) {
		birthConditions = conditions;
	}

	/**
	 * Declares the conditions for which a cell will stay alive.
	 * 
	 * The GameOfLifeBoard calls this method.
	 * 
	 * @param conditions
	 *            an ArrayList of numbers representing the number of neighbors
	 *            for which a cell will stay alive
	 */
	public static void setStayAliveConditions(ArrayList<Integer> conditions) {
		stayAliveConditions = conditions;
	}

	/**
	 * Returns the conditions for which a cell will be born.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public static ArrayList<Integer> getBirthConditions() {
		return birthConditions;
	}

	/**
	 * Returns the conditions for which a cell will stay alive.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public static ArrayList<Integer> getStayAliveConditions() {
		return stayAliveConditions;
	}

	/**
	 * Updates the state of the cell to the previous state. This method uses
	 * previousLives as a stack.
	 * 
	 * The GameOfLifeBoard calls this method.
	 */
	public void undo() {
		if (previousLives.size() > 0) {
			nextLife = life;
			life = previousLives.remove(previousLives.size() - 1);
		}
	}

	/**
	 * Updates the state of the Cell to the next generation. The GameOfLifeBoard
	 * calls this method.
	 */
	@Override
	public void update() {
		previousLives.add(life);
		life = nextLife;

	}

	/**
	 * Calculates the state of the Cell for the next generation. The
	 * GameOfLifeBoard calls this method.
	 */
	@Override
	public void calculateNextState() {

		// Condition 1: the Cell is alive. The cell will survive the next
		// generation if and only if it has an amount of neighbors defined in
		// stayAliveConditions
		if (this.life) {
			int i = 0;
			do {
				if (stayAliveConditions == null)
					nextLife = false;
				else if (numOfLifeNeighbors == stayAliveConditions.get(i))
					nextLife = true;
				else
					nextLife = false;
				i++;
			} while (!nextLife && stayAliveConditions != null
					&& i < stayAliveConditions.size());
		}
		// Condition 2: the Cell is dead. The cell will become alive if it has
		// an amount of neighbors matching those defined in the birthConditions
		// arrayList
		else {
			int i = 0;
			do {
				if (birthConditions == null)
					nextLife = false;
				else if (numOfLifeNeighbors == birthConditions.get(i))
					nextLife = true;
				else
					nextLife = false;
				i++;
			} while (!nextLife && birthConditions != null
					&& i < birthConditions.size());
		}
	}

	/**
	 * Returns the current life status of the Cell.
	 * 
	 * The GameOfLifeBoard calls this method.
	 * 
	 * @return the Cell's life status
	 */
	@Override
	public boolean isAlive() {
		return life;
	}

	/**
	 * Changes the state of the cell. If it was alive, it is now dead. If it was
	 * dead, it is now alive.The GameOfLifeBoard calls this method.
	 */
	@Override
	public void changeState() {
		life = !life;
	}

}

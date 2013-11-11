import java.util.ArrayList;

/**
 * CSCI 204, Michael Davis, Yifan Ge
 * Assignment GameOfLife
 * Created: Feb 2, 2011, 6:49:36 PM
 */

/**
 * @author Michael Davis
 * @author Yifan Ge
 */

/**
 * Problem Statement: Design three classes that will implement the provided
 * interfaces to run Conway's Game of Life. This program will generate a GUI
 * with a 2-D cell board. It will also contain fields allowing a user to set the
 * probability of life, board size, number of generations. The buttons to
 * control the GUI are play, stop, reset, and next generation.
 */
public class GameOfLife implements Game {

	/**
	 * Birth conditions for the Conway's Game of Life variant.
	 */
	public static final String LIFE_BIRTH = "3";

	/**
	 * Stay alive conditions for the Conway's Game of Life variant.
	 */
	public static final String LIFE_STAYALIVE = "2,3";

	/**
	 * Birth conditions for the Highlife Game of Life variant.
	 */
	public static final String HIGHLIFE_BIRTH = "3,6";

	/**
	 * Stay alive conditions for the Highlife Game of Life variant.
	 */
	public static final String HIGHLIFE_STAYALIVE = "2,3";

	/**
	 * Birth conditions for the Seeds Game of Life variant.
	 */
	public static final String SEEDS_BIRTH = "2";

	/**
	 * Stay alive conditions for the Seeds Game of Life variant.
	 */
	public static final String SEEDS_STAYALIVE = "";

	/**
	 * Birth conditions for the Day and Night variant.
	 */
	public static final String DAYNIGHT_BIRTH = "3,6,7,8";
	/**
	 * Stay alive conditions for the Day and Night variant.
	 */
	public static final String DAYNIGHT_STAYALIVE = "3,4,6,7,8";
	/**
	 * Birth conditions for the Replicator variant.
	 */
	public static final String REPLICATOR_BIRTH = "1,3,5,7";
	/**
	 * Stay alive conditions for the Replicator variant.
	 */
	public static final String REPLICATOR_STAYALIVE = "1,3,5,7";
	/**
	 * Birth conditions for the Serviettes variant.
	 */
	public static final String SERVIETTES_BIRTH = "2,3,4";
	/**
	 * Stay alive conditions for the Serviettes variant.
	 */
	public static final String SERVIETTES_STAYALIVE = "";
	/**
	 * Birth conditions for the Life No Death variant.
	 */
	public static final String LIFENODEATH_BIRTH = "3";
	/**
	 * Stay alive conditions for the Life No Death variant.
	 */
	public static final String LIFENODEATH_STAYALIVE = "0,1,2,3,4,5,6,7,8";
	/**
	 * Birth conditions for the Walled Cities variant.
	 */
	public static final String WALLEDCITY_BIRTH = "4,5,6,7,8";
	/**
	 * Stay alive conditions for the Walled Cities variant.
	 */
	public static final String WALLEDCITY_STAYALIVE = "2,3,4,5";
	/**
	 * Birth conditions for the Diamoeba variant.
	 */
	public static final String DIAMOEBA_BIRTH = "3,5,6,7,8";
	/**
	 * Stay alive conditions for the Diamoeba variant.
	 */
	public static final String DIAMOEBA_STAYALIVE = "5,6,7,8";

	/**
	 * The maximum number of neighbors a cell may have.
	 */
	private static final int MAX_NUM_NEIGHBORS = 8;

	/**
	 * The minimum board size.
	 */
	public static final int MIN_BOARD_SIZE = 5;

	/**
	 * The default board size.
	 */
	public static final int DEFAULT_BOARD_SIZE = 50;

	/**
	 * The maximum board size.
	 */
	public static final int MAX_BOARD_SIZE = 100;

	/**
	 * The 2-D cells board of the game.
	 */
	private TwoDBoard board;

	/**
	 * The maximum number of generations the game will run.
	 */
	private int maximumGenerations;

	/**
	 * The current number of generations the game has run.
	 */
	private int currentGenerations;

	/**
	 * The initial probability of life for a cell.
	 */
	private double initialProbability;

	/**
	 * The birth conditions for a cell in this instance of GameOfLife.
	 */
	private ArrayList<Integer> birthConditions;

	/**
	 * The stay alive conditions for a cell in this instance of GameOfLife.
	 */
	private ArrayList<Integer> stayAliveConditions;

	/**
	 * Constructs a GameOfLife object with default member data.
	 */
	public GameOfLife() {
		setBoardSize(DEFAULT_BOARD_SIZE);
		setBirthConditions("");
		setStayAliveConditions("");
		maximumGenerations = 0;
		currentGenerations = 0;
		initialProbability = 0;
	}

	/**
	 * Adds the provided number of generations to the maximum number of
	 * generations for the game.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param numGens
	 *            the number of generations to extend the game.
	 */
	@Override
	public void extendGame(int numGens) {
		// allow for subtraction of generations but prevent invalid max
		if (numGens < (maximumGenerations - currentGenerations))
			maximumGenerations += numGens;
	}

	/**
	 * Sets the size of the game board for when the game instance is
	 * re-initialized.
	 * 
	 * This method calls the GameOfLifeBoard .getSize() method.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param boardSize
	 *            the size of future game boards
	 */
	@Override
	public int getBoardSize() {
		return board.getSize();
	}

	/**
	 * Returns the number of generations that have been run for the game
	 * instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the number of generations run for the game
	 */
	@Override
	public int getCurrentGeneration() {
		return currentGenerations;
	}

	/**
	 * Returns a reference to the current game board. True indicates a live
	 * cell.
	 * 
	 * This method calls the GameOfLifeBoard .toArray() method.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the current game board
	 */
	@Override
	public boolean[][] getGameBoard() {
		return board.toArray();
	}

	/**
	 * Returns the initial probability of life for a cell in the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the initial probability of life for a cell
	 */
	@Override
	public double getInitialProbability() {
		return initialProbability;
	}

	/**
	 * Returns the maximum generations to be run for the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the maximum generations to run
	 */
	@Override
	public int getMaxGenerations() {
		return maximumGenerations;
	}

	/**
	 * Returns true if the game finishing conditions are met. Otherwise, returns
	 * false.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @return the current liveness status of the game
	 */
	@Override
	public boolean isFinished() {
		if (currentGenerations < maximumGenerations) {
			return false;
		}
		return true;
	}

	/**
	 * Using the stored values of the board size and initial probability of
	 * life, creates a new game board. Also resets the current number of
	 * generations counter to zero.
	 * 
	 * This method calls the GameOfLifeBoard .changeState() method.
	 * 
	 * The GameOfLifeGUI calls this method.
	 */
	@Override
	public void reinitialize() {
		double randomProbability;
		currentGenerations = 0;
		// set all cells to dead
		setBoardSize(getBoardSize());

		for (int i = 0; i < getBoardSize(); i++)
			for (int j = 0; j < getBoardSize(); j++) {
				randomProbability = Math.random();
				// cell will be alive
				if (randomProbability <= initialProbability) {
					board.changeState(i, j);
				}
			}
	}

	/**
	 * Sets the birth conditions for a cell on the board. Birth conditions must
	 * be supplied in the format of a list of integers separated by commas.
	 * 
	 * This method is called in the GameOfLifeGUI.
	 * 
	 * This method calls the .conditionsAreValid() method.
	 * 
	 * @param conditions
	 *            s string representation of the birth conditions of a cell on
	 *            the board
	 * @return true if the birthConditions were set to the supplied value.
	 */
	public boolean setBirthConditions(String conditions) {

		if (areValidConditions(conditions)) {
			birthConditions = convertConditionsToData(conditions);
			board.setBirthConditions(birthConditions);
			return true;
		} else {
			birthConditions = convertConditionsToData("");
			board.setBirthConditions(birthConditions);
			return false;
		}
	}

	/**
	 * Sets the stay alive conditions for a cell on the board. Stay alive
	 * conditions must be supplied in the format of a list of integers separated
	 * by commas.
	 * 
	 * This method is called in the GameOfLifeGUI.
	 * 
	 * This method calls the .conditionsAreValid() method.
	 * 
	 * @param conditions
	 *            string representation of the stay alive conditions of a cell
	 *            on the board
	 * @return true if the stayAliveConditions were set to the supplied value.
	 */
	public boolean setStayAliveConditions(String conditions) {

		if (areValidConditions(conditions)) {
			stayAliveConditions = convertConditionsToData(conditions);
			board.setStayAliveConditions(stayAliveConditions);
			return true;
		}
		stayAliveConditions = convertConditionsToData("");
		board.setStayAliveConditions(stayAliveConditions);
		return false;
	}

	/**
	 * Returns true if the supplied conditions are valid.
	 * 
	 * This method should only be called by setBirthConditions and
	 * setStayAliveConditions.
	 * 
	 * @param conditions
	 *            string representation of either the stay alive or birth
	 *            conditions
	 * @return true if the supplied conditions are valid for stay alive or birth
	 *         conditions
	 */
	private boolean areValidConditions(String conditions) {
		conditions = conditions.trim();

		if (conditions.equals(""))
			return true;

		// this is a dirty work-around but fixes bug where user could not enter
		// null as a valid input while using the old code...

		if (convertConditionsToData(conditions) == null)
			return false;
		return true;

	}

	/**
	 * Determines whether the user input for birth or stay alive conditions are
	 * valid. This method is expecting to receive the conditions in the form of
	 * integers separated by commas.
	 * 
	 * This method should only be called by the setStayAliveConditions and the
	 * setBirthConditions methods.
	 * 
	 * @param conditions
	 * @return an array of integers where each element is a number of neighbors
	 *         that had been specified in the conditions passed to this method.
	 *         If the conditions were invalid, null is returned.
	 */
	private ArrayList<Integer> convertConditionsToData(String conditions) {
		int commaIndex;
		ArrayList<Integer> cond = new ArrayList<Integer>();
		String condString = conditions;// .trim();

		try {
			while (condString.indexOf(",") != -1) {
				commaIndex = condString.indexOf(",");
				cond.add(Integer.parseInt(condString.substring(0, commaIndex)));
				// chop off the front of the string after pulling off the number
				condString = condString.substring(commaIndex + 1, condString
						.length());
			}

			cond.add(Integer.parseInt(condString));// add the final value
			// check for illogical neighbor values
			for (int i = 0; i < cond.size(); i++) {
				if (cond.get(i) > MAX_NUM_NEIGHBORS || cond.get(i) < 0)
					return null;
			}

			return cond;
		} catch (Exception e) {
			return null;
		}
	}

	/**
	 * Sets the size of the game board for when the game instance is
	 * re-initialized.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param boardSize
	 *            the size of future game boards
	 */
	@Override
	public void setBoardSize(int boardSize) {
		if (boardSize < MIN_BOARD_SIZE)
			board = new GameOfLifeBoard(MIN_BOARD_SIZE, birthConditions,
					stayAliveConditions);
		else if (boardSize > MAX_BOARD_SIZE)
			board = new GameOfLifeBoard(MAX_BOARD_SIZE, birthConditions,
					stayAliveConditions);
		else
			board = new GameOfLifeBoard(boardSize, birthConditions,
					stayAliveConditions);
	}

	/**
	 * Sets the game board to the same state as the provided 2-d array. True
	 * indicates a live cell.
	 * 
	 * This method calls the GameOfLifeBoard .isAlive() and .changeState()
	 * methods.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param gameBoard
	 *            the state to set the board.
	 */
	@Override
	public void setGameBoard(boolean[][] gameBoard) {
		for (int i = 0; i < gameBoard.length; i++) {
			for (int j = 0; j < gameBoard[i].length; j++) {
				// case: gameboard alive but currently dead, come to life
				if (gameBoard[i][j] == true && !board.isAlive(i, j))
					board.changeState(i, j);

				// case: gameboard is dead, currently alive, die
				else if (gameBoard[i][j] == false && board.isAlive(i, j))
					board.changeState(i, j);
			}
		}
	}

	/**
	 * Sets the initial probability of life for a cell for a game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param initProb
	 *            the initial probability of life for a cell
	 */
	@Override
	public void setInitialProbability(double initProb) {
		if (initProb > 1)
			initialProbability = 1;
		else if (initProb < 0)
			initialProbability = 0;
		else
			initialProbability = initProb;

	}

	/**
	 * Sets the maximum generations to be run for the game instance.
	 * 
	 * The GameOfLifeGUI calls this method.
	 * 
	 * @param maxGens
	 *            the maximum generations to run
	 */
	@Override
	public void setMaxGenerations(int maxGens) {
		if (maxGens > 0) {
			maximumGenerations = maxGens;
		} else
			maximumGenerations = 0;
	}

	/**
	 * Returns the board to the state in the previous generation.
	 * 
	 * This method is called by the GameOfLifeGUI.
	 * 
	 * This method Calls the GameOfLifeBoard .undo() method.
	 */
	public void undoBoard() {
		if (currentGenerations > 0) {
			currentGenerations--;
			board.undo();
		}
	}

	/**
	 * Updates the board to the next generation.
	 * 
	 * This method calls the GameOfLifeBoard .update() method.
	 * 
	 * The GameOfLifeGUI calls this method.
	 */
	@Override
	public void updateBoard() {
		currentGenerations++;
		board.update();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return board.toString();
	}

}

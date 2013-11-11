import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.JTextField;

/**
 * Project: Game of Life
 * File: GameOfLifeGUI.java
 * Author: Shane Markstrum, sm053
 * Date: Feb 5, 2010
 * 
 */

/**
 * This is a generic GUI for use with running variations on Conway's Game of
 * Life. The Game of Life is a turn-based "game" or deterministic life
 * simulation that algorithmically updates the live/dead status of a cell on the
 * game's board based on the current status of the cell's neighbors. This GUI
 * displays the a game via a graphical grid where dead cells are represented as
 * empty squares and live cells are represented as blue squares. The GUI
 * provides text based input for determining the size of the game board, the
 * initial probability of a cell being alive at the beginning of the game, and
 * the maximum number of generations to run before ending the game. If no input
 * is provided for the maximum number of generations, then the game uses the
 * maximal integer value.
 * 
 * The GUI also allows the user to interact with the game. It provides buttons
 * which can be used to reset the game board based on the values provided in the
 * text fields, to print out an ASCII version of a game to the console (for a
 * board no larger than 15x15), to increment the game by one generation, and to
 * automatically step generations until the maximum is reached or the user tells
 * the game to stop. The user can interact directly with the game by clicking on
 * a cell to change its state from alive to dead, or vice-versa.
 * 
 * Do not edit this class.
 * 
 * @author sm053
 * 
 *         Edited by @author Michael Davis
 * 
 */
public class GameOfLifeGUI implements ActionListener, MouseListener {

	/**
	 * A list of all possible game variants.
	 */
	private String[] gameVariants = { "Custom", "Life", "Highlife", "Seeds",
			"Day & Night", "Replicator", "Serviettes", "Life Without Death",
			"Walled Cities", "Diamoeba" };

	/**
	 * The drop down menu used to select the game variants.
	 */
	private JComboBox dropDownMenu;

	/**
	 * The text field containing the birth conditions for a cell.
	 */
	private JTextField birthConditionsField;

	/**
	 * The text field containing the stay alive conditions for a cell.
	 */
	private JTextField stayAliveConditionsField;

	/**
	 * The text field containing the maximum generations value.
	 */
	private JTextField maxGenField;

	/**
	 * The text field containing the board size value.
	 */
	private JTextField boardSizeField;

	/**
	 * The text field containing the initial life probability value.
	 */
	private JTextField initProbField;

	/**
	 * The text field containing the current generation number.
	 */
	private JTextField currGenField;

	/**
	 * The current Game of Life variant instance being displayed.
	 */
	private Game game;

	/**
	 * The button for stepping the game backwards by one generation.
	 */
	private JButton previousButton;

	/**
	 * The button for stepping the game by one generation.
	 */
	private JButton nextButton;

	/**
	 * The button for automatically stepping through the game until the maximum
	 * generation is reached.
	 */
	private JButton playButton;

	/**
	 * A timer to be used to automatically step through the generations of the
	 * current game instance.
	 */
	private Timer playTimer = new Timer();

	/**
	 * The button for printing the current game board to the console.
	 */
	private JButton printButton;

	/**
	 * The interactive grid displaying the game board.
	 */
	private TwoDPanel boardCanvas;

	/**
	 * The content pane for the GUI.
	 */
	private JPanel mainPane;

	/**
	 * Indicates whether the play button had been pushed
	 */
	private boolean playMode;

	/**
	 * Creates a new GUI for a variant on Conway's Game of Life.
	 * 
	 * @param game
	 *            an instance of the game variant to be played
	 */
	private GameOfLifeGUI(Game game) {
		this.game = game;
		playMode = false;
		// Create the button JPanel

		// Create row 0: previous
		JPanel buttonPane0 = new JPanel();
		buttonPane0.setLayout(new BoxLayout(buttonPane0, BoxLayout.LINE_AXIS));

		// Create the previous button and register actions
		previousButton = new JButton("Previous");
		buttonPane0.add(previousButton);
		previousButton.setAlignmentX(Component.LEFT_ALIGNMENT);
		previousButton.setActionCommand("previous");
		previousButton.addActionListener(this);
		previousButton.setMnemonic(java.awt.event.KeyEvent.VK_BACK_SPACE);

		buttonPane0.add(Box.createHorizontalGlue());

		// Create row 1: Play / Print
		JPanel buttonPane1 = new JPanel();
		buttonPane1.setLayout(new BoxLayout(buttonPane1, BoxLayout.LINE_AXIS));

		// Create the Play button and register actions
		playButton = new JButton("Play");
		playButton.setAlignmentX(Component.LEFT_ALIGNMENT);
		buttonPane1.add(playButton);
		playButton.setActionCommand("play");
		playButton.addActionListener(this);
		playButton.setMnemonic(java.awt.event.KeyEvent.VK_SPACE);

		buttonPane1.add(Box.createHorizontalGlue());

		// Create the Print button and register actions
		printButton = new JButton("Print");
		buttonPane1.add(printButton);
		printButton.setActionCommand("print");
		printButton.addActionListener(this);

		// Create row 2: Next / Reset
		// Create the Next button and register actions
		JPanel buttonPane2 = new JPanel();
		buttonPane2.setLayout(new BoxLayout(buttonPane2, BoxLayout.LINE_AXIS));
		nextButton = new JButton("Next");
		buttonPane2.add(nextButton);

		buttonPane2.add(Box.createHorizontalGlue());

		// Create the Reset button and register actions
		JButton startButton = new JButton("Reset");
		buttonPane2.add(startButton);
		nextButton.setActionCommand("next");
		startButton.setActionCommand("start");
		startButton.setMnemonic(java.awt.event.KeyEvent.VK_ESCAPE);
		nextButton.setMnemonic(java.awt.event.KeyEvent.VK_ENTER);
		nextButton.addActionListener(this);
		startButton.addActionListener(this);

		// Combine button panels into buttonPane
		JPanel buttonPane = new JPanel();
		buttonPane.setLayout(new BoxLayout(buttonPane, BoxLayout.PAGE_AXIS));
		buttonPane.add(buttonPane0);
		buttonPane.add(getSeparator());
		buttonPane.add(buttonPane1);
		buttonPane.add(getSeparator());
		buttonPane.add(buttonPane2);

		// Create the options JPanel

		/*
		 * Create the current generation label and text field in order to set
		 * the appropriate height of the text options panel.
		 */
		JLabel currGenLabel = new JLabel("Current Generation");
		currGenField = new JTextField(String.valueOf(game
				.getCurrentGeneration()), 8);
		currGenField.setEditable(false);

		final int numberOfOptions = 7;

		final int setHeight = numberOfOptions
				* (currGenField.getPreferredSize().height
						+ currGenLabel.getPreferredSize().height + getSeparator()
						.getPreferredSize().height * 2);

		// Create the options panel and fix the size to the desired height
		JPanel optionsPane = new JPanel() {
			public Dimension getMinimumSize() {
				return getPreferredSize();
			}

			public Dimension getPreferredSize() {
				return new Dimension(super.getPreferredSize().width, setHeight);
			}

			public Dimension getMaximumSize() {
				return getPreferredSize();
			}
		};
		optionsPane.setLayout(new BoxLayout(optionsPane, BoxLayout.PAGE_AXIS));

		// Create the board size label and text field
		boardSizeField = new JTextField(String.valueOf(game.getBoardSize()), 8);
		addComponentToPanel(optionsPane, new JLabel("Board Size"));
		addComponentToPanel(optionsPane, boardSizeField);

		// Create the initial life probability label and text field
		initProbField = new JTextField(String.valueOf(game
				.getInitialProbability()), 8);
		addComponentToPanel(optionsPane, new JLabel("Prob of Life"));
		addComponentToPanel(optionsPane, initProbField);

		// Create the maximum generations label and text field
		maxGenField = new JTextField(String.valueOf(game.getMaxGenerations()),
				8);
		addComponentToPanel(optionsPane, new JLabel("Max Generations"));
		addComponentToPanel(optionsPane, maxGenField);

		addComponentToPanel(optionsPane, currGenLabel);
		addComponentToPanel(optionsPane, currGenField);

		// Create the birth conditions label and text field
		birthConditionsField = new JTextField(String.valueOf(game
				.getBoardSize()), 8);
		addComponentToPanel(optionsPane, new JLabel("Birth Conditions"));
		addComponentToPanel(optionsPane, birthConditionsField);

		// Create the stay alive conditions label and text field
		stayAliveConditionsField = new JTextField(String.valueOf(game
				.getBoardSize()), 8);
		addComponentToPanel(optionsPane, new JLabel("Stay Conditions"));
		addComponentToPanel(optionsPane, stayAliveConditionsField);

		// Create the drop down menu to select game variants
		dropDownMenu = new JComboBox(gameVariants);
		addComponentToPanel(optionsPane, new JLabel("Game Variants"));
		addComponentToPanel(optionsPane, dropDownMenu);
		dropDownMenu.setSelectedIndex(1);
		dropDownMenu.addActionListener(this);

		// combine button panel and options panel into right-hand-side panel
		final int buttonWidth = nextButton.getPreferredSize().width
				+ startButton.getPreferredSize().width
				+ Box.createHorizontalGlue().getPreferredSize().width + 10;

		JPanel nonDisplayPane = new JPanel();
		nonDisplayPane.setPreferredSize(new Dimension(buttonWidth,
				nonDisplayPane.getHeight()));
		nonDisplayPane.setLayout(new BoxLayout(nonDisplayPane,
				BoxLayout.PAGE_AXIS));
		optionsPane.setAlignmentX(Component.LEFT_ALIGNMENT);
		buttonPane.setAlignmentX(Component.LEFT_ALIGNMENT);
		nonDisplayPane.add(optionsPane);
		nonDisplayPane.add(getSeparator());
		nonDisplayPane.add(Box.createVerticalGlue());
		nonDisplayPane.add(buttonPane);
		nonDisplayPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

		// Create the display grid panel and canvas
		boardCanvas = new TwoDPanel(game.getGameBoard());
		boardCanvas.addMouseListener(this);
		JPanel canvasPane = new JPanel(new BorderLayout());
		// canvasPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		// canvasPane.setPreferredSize(boardCanvas.getPreferredSize());
		canvasPane.add(boardCanvas);
		// canvasPane.setAlignmentX(Component.CENTER_ALIGNMENT);
		// canvasPane.setAlignmentY(Component.CENTER_ALIGNMENT);

		// Create main panel and add the display and nonDisplay panes
		mainPane = new JPanel();
		mainPane.setLayout(new BoxLayout(mainPane, BoxLayout.LINE_AXIS));
		mainPane.add(canvasPane);
		mainPane.add(new JSeparator(JSeparator.VERTICAL));
		mainPane.add(nonDisplayPane);

		initializeOptions();
	}

	/**
	 * This method initializes the text fields, buttons and comboBox at game
	 * start.
	 * 
	 * This method should only be called in GameOfLifeGUI()
	 */
	private void initializeOptions() {
		// initialize maxGenerations field
		maxGenField.setText("100");

		// initialize the text in the fields to the default game values
		loadBirthStayFields(GameOfLife.LIFE_BIRTH, GameOfLife.LIFE_STAYALIVE);

		disableBirthStayFields();

		// initialize the state of the next and play buttons based on game state
		nextButton.setEnabled(false);
		playButton.setEnabled(false);
		previousButton.setEnabled(false);

	}

	/**
	 * Adds the given awt/swing component to the provided panel with a buffer
	 * beneath the component.
	 * 
	 * @param pane
	 *            the panel to be modified
	 * @param comp
	 *            the component to be added
	 */
	private void addComponentToPanel(JPanel pane, JComponent comp) {
		pane.add(comp);
		comp.setAlignmentX(Component.LEFT_ALIGNMENT);
		pane.add(getSeparator());
	}

	/**
	 * Creates a new game instance based on the parameters in the options field
	 * and resets the display to use this new game instance.
	 * 
	 * This method is dependent on constants found in the GameOfLife class.
	 */
	private void reset() {
		stop();
		setMaxGenerations();
		setBirthConditions();
		setStayAliveConditions();

		// pull new board size out of the board size text field
		try {
			int boardSize = Integer.parseInt(boardSizeField.getText());
			if (boardSize > GameOfLife.MAX_BOARD_SIZE) {
				boardSize = GameOfLife.MAX_BOARD_SIZE;
			} else if (boardSize < GameOfLife.MIN_BOARD_SIZE) {
				boardSize = GameOfLife.MIN_BOARD_SIZE;
			}
			game.setBoardSize(boardSize);
			boardSizeField.setText(Integer.toString(game.getBoardSize()));

		} catch (NumberFormatException nfe) {
			System.err.println("Invalid input for board size discarded!");
			boardSizeField.setText(Integer.toString(game.getBoardSize()));
		}

		// pull new initial life probability from initial life probability
		// text field
		try {
			double initProb = Double.parseDouble(initProbField.getText());
			if (initProb < 0) {
				initProb = 0;
			} else if (initProb > 1) {
				initProb = 1;
			}
			game.setInitialProbability(initProb);
		} catch (NumberFormatException nfe) {
			System.err
					.println("Invalid input for initial probability discarded!");
			initProbField
					.setText(Double.toString(game.getInitialProbability()));
		}

		// reinitial the game instance with the new parameters
		game.reinitialize();

		// refresh the game board display and generation information
		boardCanvas.setGameBoard(game.getGameBoard());
		boardCanvas.repaint();
		currGenField.setText(String.valueOf(game.getCurrentGeneration()));

		// determine the appropriate state for the play and next buttons
		if (game.getMaxGenerations() > 0) {
			nextButton.setEnabled(true);
			playButton.setEnabled(true);
		} else {
			nextButton.setEnabled(false);
			playButton.setEnabled(false);
		}

		// determine whether the print button should be enabled
		if (game.getBoardSize() > 15) {
			printButton.setEnabled(false);
		} else {
			printButton.setEnabled(true);
		}

		// determine the appropriate state for the previous button
		previousButton.setEnabled(false);
	}

	/**
	 * Steps the game backwards by one generation and refreshes the game board
	 * display.
	 */
	private void previous() {

		game.undoBoard();
		boardCanvas.setGameBoard(game.getGameBoard());
		boardCanvas.repaint();

		if (!game.isFinished()) {
			nextButton.setEnabled(true);
			playButton.setEnabled(true);
		} else {
			nextButton.setEnabled(false);
			playButton.setEnabled(true);
		}

		currGenField.setText(String.valueOf(game.getCurrentGeneration()));
		if (game.getCurrentGeneration() > 0) {
			previousButton.setEnabled(true);
		} else
			previousButton.setEnabled(false);

	}

	/**
	 * Steps the game by one generation and refreshes the game board display.
	 */
	private void next() {
		// if the game is not done, do the next generation
		if (!game.isFinished()) {
			game.updateBoard();
			boardCanvas.setGameBoard(game.getGameBoard());
			boardCanvas.repaint();
		}
		currGenField.setText(String.valueOf(game.getCurrentGeneration()));

		// if game is in play mode
		if (playMode) {
			previousButton.setEnabled(false);
			nextButton.setEnabled(false);
		} else {
			nextButton.setEnabled(true);
			previousButton.setEnabled(true);
		}

		// if the game is over now, disable the next and play buttons
		if (game.isFinished()) {
			nextButton.setEnabled(false);
			playButton.setEnabled(false);
			previousButton.setEnabled(true);
		}
	}

	/**
	 * Starts automatically stepping through the game generations until the user
	 * pushes the Stop button or the game is finished. Display is updated after
	 * each generation.
	 */
	private void play() {
		playMode = true;
		// A new timer task for stepping the game
		TimerTask tt = new TimerTask() {
			public void run() {
				if (!game.isFinished()) {
					// during play
					next();
					if (game.isFinished()) {
						playMode = false;
						stop();
						this.cancel();
					}
				} else {
					playMode = false;
					stop();
					this.cancel();
				}
			}
		};

		// changes button from "Play" to "Stop"
		playButton.setText("Stop");
		playButton.setActionCommand("stop");
		nextButton.setEnabled(false);
		previousButton.setEnabled(true);

		// registers each generation to step at .4 second increments
		playTimer.scheduleAtFixedRate(tt, 0, 400);
	}

	/**
	 * Stops automatically stepping of the game.
	 */
	private void stop() {
		playMode = false;
		// cancel the Timer and make a new one
		playTimer.cancel();
		playTimer = new Timer();

		// change button from "Stop" to "Play"
		playButton.setText("Play");
		playButton.setActionCommand("play");

		// determines the correct state of the next and play buttons
		if (!game.isFinished())
			nextButton.setEnabled(true);
		if (game.isFinished())
			playButton.setEnabled(false);
		if (game.getCurrentGeneration() > 0)
			previousButton.setEnabled(true);
	}

	/**
	 * Sets the game's birth conditions value based on the value of the text
	 * field for the birth conditions.
	 */
	private void setBirthConditions() {

		if (!game.setBirthConditions(birthConditionsField.getText())) {
			System.err.println("Invalid input for birth conditions discarded!");
			loadBirthField("");
		}

	}

	/**
	 * Sets the game's stay alive conditions value based on the value of the
	 * text field for the stay alive conditions.
	 */
	private void setStayAliveConditions() {

		if (!game.setStayAliveConditions(stayAliveConditionsField.getText())) {
			System.err
					.println("Invalid input for stay alive conditions discarded!");
			loadStayField("");
		}

	}

	/**
	 * Sets the game's maximum generation value based on the value of the text
	 * field for the maximum generation.
	 */
	private void setMaxGenerations() {
		try {
			if (!"".equals(maxGenField.getText()))
				game.setMaxGenerations(Integer.parseInt(maxGenField.getText()));
			else
				game.setMaxGenerations(Integer.MAX_VALUE);
		} catch (NumberFormatException nfe) {
			System.err
					.println("Invalid input for maximum generations discarded!");
			maxGenField.setText(Integer.toString(game.getMaxGenerations()));
		}
	}

	/**
	 * Returns the standard separator between Components in the GUI.
	 * 
	 * @return a blank rigid area 5 pixels wide.
	 */
	private static Component getSeparator() {
		return Box.createRigidArea(new Dimension(0, 5));
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event-dispatching thread.
	 */
	private static void createAndShowGUI(Game game) {
		// Create and set up the window.
		JFrame frame = new JFrame("Games Of Life");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);

		// Create and set up the content pane.
		GameOfLifeGUI gol = new GameOfLifeGUI(game);
		gol.mainPane.setOpaque(true);
		frame.setContentPane(gol.mainPane);

		// Display the window.
		frame.pack();
		frame.setVisible(true);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		String command = e.getActionCommand();

		if ("comboBoxChanged".equals(command)) {
			JComboBox comboBox = (JComboBox) e.getSource();
			String variantName = (String) comboBox.getSelectedItem();

			if (variantName.equals(gameVariants[0])) {
				// this is Custom
				enableBirthStayFields();
				loadBirthStayFields("", "");
			} else if (variantName.equals(gameVariants[1])) {
				// this is Conway's
				loadBirthStayFields(GameOfLife.LIFE_BIRTH,
						GameOfLife.LIFE_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[2])) {
				// this is Highlife
				loadBirthStayFields(GameOfLife.HIGHLIFE_BIRTH,
						GameOfLife.HIGHLIFE_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[3])) {
				// this is Seeds
				loadBirthStayFields(GameOfLife.SEEDS_BIRTH,
						GameOfLife.SEEDS_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[4])) {
				// this is Day & Night
				loadBirthStayFields(GameOfLife.DAYNIGHT_BIRTH,
						GameOfLife.DAYNIGHT_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[5])) {
				// this is Replicator
				loadBirthStayFields(GameOfLife.REPLICATOR_BIRTH,
						GameOfLife.REPLICATOR_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[6])) {
				// this is Serviettes
				loadBirthStayFields(GameOfLife.SERVIETTES_BIRTH,
						GameOfLife.SERVIETTES_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[7])) {
				// this is Life No Death
				loadBirthStayFields(GameOfLife.LIFENODEATH_BIRTH,
						GameOfLife.LIFENODEATH_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[8])) {
				// this is Walled Cities
				loadBirthStayFields(GameOfLife.WALLEDCITY_BIRTH,
						GameOfLife.WALLEDCITY_STAYALIVE);
				disableBirthStayFields();
			} else if (variantName.equals(gameVariants[9])) {
				// this is Diamoeba
				loadBirthStayFields(GameOfLife.DIAMOEBA_BIRTH,
						GameOfLife.DIAMOEBA_STAYALIVE);
				disableBirthStayFields();
			}
		} else {
			if ("start".equals(command))
				reset();
			else if ("previous".equals(command))
				previous();
			else if ("next".equals(command))
				next();
			else if ("play".equals(command))
				play();
			else if ("stop".equals(command))
				stop();
			else if ("print".equals(command))
				System.out.println(game);
		}

		boardCanvas.repaint();
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.event.MouseListener#mouseClicked(java.awt.event.MouseEvent)
	 */
	@Override
	public void mouseClicked(MouseEvent e) {

		if (e.getSource().equals(boardCanvas)) {
			int cell_i = ((e.getPoint().x - boardCanvas.getX()) / boardCanvas
					.cellSize());
			int cell_j = (e.getPoint().y - boardCanvas.getY())
					/ boardCanvas.cellSize();

			// prevent out-of-bounds exceptions
			if (cell_i < 0)
				cell_i = 0;
			// else if (cell_i >= boardCanvas.getX() + boardCanvas.getWidth())
			// cell_i = game.getBoardSize() - 1;

			if (cell_j < 0)
				cell_j = 0;
			// else if (cell_j >= boardCanvas.getY() + boardCanvas.getHeight())
			// cell_j = game.getBoardSize() - 1;
			try {
				boolean[][] currBoard = game.getGameBoard();
				currBoard[cell_i][cell_j] = !currBoard[cell_i][cell_j];
				game.setGameBoard(currBoard);
			} catch (Exception exception) {

			}

			try {
				if (game.isFinished()) {
					if ("".equals(maxGenField.getText())) {
						game.setMaxGenerations(Integer.MAX_VALUE);
					} else {
						game.extendGame(Integer.valueOf(maxGenField.getText()));
						maxGenField.setText(Integer.toString(game
								.getMaxGenerations()));
					}
				}
			} catch (NumberFormatException nfe) {
				System.err
						.println("Invalid input in maximum generations field discarded!");
				maxGenField.setText(Integer.toString(game.getMaxGenerations()));
			}

			if (!nextButton.isEnabled() && !game.isFinished()) {
				nextButton.setEnabled(true);
				playButton.setEnabled(true);
			}

			// if (!previousButton.isEnabled() && game.getCurrentGeneration() >
			// 0)
			// previousButton.setEnabled(true);

			boardCanvas.setGameBoard(game.getGameBoard());
			boardCanvas.repaint();
		}

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.event.MouseListener#mouseEntered(java.awt.event.MouseEvent)
	 */
	@Override
	public void mouseEntered(MouseEvent e) {
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.event.MouseListener#mouseExited(java.awt.event.MouseEvent)
	 */
	@Override
	public void mouseExited(MouseEvent e) {
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.event.MouseListener#mousePressed(java.awt.event.MouseEvent)
	 */
	@Override
	public void mousePressed(MouseEvent e) {
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * java.awt.event.MouseListener#mouseReleased(java.awt.event.MouseEvent)
	 */
	@Override
	public void mouseReleased(MouseEvent e) {
	}

	/**
	 * Properly sets up the GUI for the game instance.
	 * 
	 * @param game
	 *            the game instance to be displayed in the GUI
	 */
	public static void run(final Game game) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				GameOfLifeGUI.createAndShowGUI(game);
			}
		});
	}

	/**
	 * Enters text for the user into the proper fields.
	 * 
	 * This method should only be called by actionPerformed().
	 * 
	 * @param birthConditions
	 *            the birth conditions for each cell on the board
	 * @param stayAliveConditions
	 *            the conditions required for each cell to stay alive on the
	 *            board
	 */
	private void loadBirthStayFields(String birthConditions,
			String stayAliveConditions) {

		loadBirthField(birthConditions);
		loadStayField(stayAliveConditions);
	}

	/**
	 * Enters text into the birth conditions field.
	 * 
	 * @param birthConditions
	 *            conditions for a cell to be born on the board
	 */
	private void loadBirthField(String birthConditions) {
		birthConditionsField.setText(birthConditions);
	}

	/**
	 * Enters text into the stay alive conditions field
	 * 
	 * @param stayConditions
	 *            conditions for a cell to stay alive on the board
	 */
	private void loadStayField(String stayAliveConditions) {
		stayAliveConditionsField.setText(stayAliveConditions);
	}

	/**
	 * Enables the birth and stay fields so the user can modify them.
	 */
	private void enableBirthStayFields() {
		birthConditionsField.setEnabled(true);
		stayAliveConditionsField.setEnabled(true);
	}

	/**
	 * Disables the birth and stay condition fields so the user cannot modify
	 * them.
	 */
	private void disableBirthStayFields() {
		birthConditionsField.setEnabled(false);
		stayAliveConditionsField.setEnabled(false);
	}

	public static void main(String[] args) {
		GameOfLife game = new GameOfLife(); // call default constructor
		run(game);
	}

}

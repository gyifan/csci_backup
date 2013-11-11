import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JSeparator;
import javax.swing.JTextField;

/**
 * Project: Maze Escaping Robots!!! 
 * File: MazeVizualizer.java
 * Author: Shane Markstrum, sm053
 * Date: Oct 1, 2009
 */

/**
 * A GUI for the Maze Escaping Robots project. Provides primitive feedback on
 * the current state of the robot's journey. Also provides a minimal amount of
 * interactive buttons.
 * 
 * To be used, the robots must implement the IRobot interface and the maze must
 * implement the IMaze interface. The robot classes must also be in the default
 * package and be called RandomRobot, RightHandRuleRobot, and MemoryRobot,
 * respectively.
 * 
 * @author sm053
 * 
 */
public class MazeVizualizer implements ActionListener {

	/** The current maze */
	private IMaze maze;

	/** The current robot */
	private IRobot robot;

	/** GUI Component */
	private JFrame frame;
	/** GUI Component */
	private JPanel mainPane;
	/** GUI Component */
	private JTextField mazeField;
	/** GUI Component */
	private JTextField robotField;
	/** GUI Component */
	private JTextField moveField;
	/** GUI Component */
	private JPanel canvasPane;
	/** GUI Component */
	private MazePanel mazePanel;
	/** GUI Component */
	private JButton resetButton;
	/** GUI Component */
	private JButton stepButton;
	/** GUI Component */
	private JButton playButton;
	/** GUI Component */
	private Timer playTimer = new Timer();
	/** GUI Component */
	private JButton endButton;
	/** GUI Component */
	private String defaultDir = System.getProperty("user.dir");

	private JCheckBox visitedField;

	/**
	 * A text field with a fixed height. It will not stretch when the window is
	 * resized.
	 * 
	 * @author sm053
	 * 
	 */
	private class FixedHeightTextField extends JTextField {
		private static final long serialVersionUID = 1L;

		public FixedHeightTextField(String s, int chars) {
			super(s, chars);
		}

		public Dimension getMinimumSize() {
			return getPreferredSize();
		}

		public Dimension getMaximumSize() {
			return getPreferredSize();
		}
	}

	/**
	 * Creates and sets up a new GUI for the Maze Escaping Robots project.
	 */
	public MazeVizualizer() {
		frame = new JFrame("Maze Escaping Robots!!!");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);

		// Create the button JPanel

		// Create button row 1:
		// Create the Play button
		JPanel buttonPane1 = new JPanel();
		buttonPane1.setLayout(new BoxLayout(buttonPane1, BoxLayout.LINE_AXIS));
		playButton = new JButton("Play");
		playButton.setActionCommand("play");
		playButton.addActionListener(this);
		buttonPane1.add(playButton);
		buttonPane1.add(Box.createHorizontalGlue());
		endButton = new JButton("End");
		endButton.setActionCommand("end");
		endButton.addActionListener(this);
		buttonPane1.add(endButton);

		// Create button row 2:
		// Create the Step & Next button and register actions
		JPanel buttonPane2 = new JPanel();
		buttonPane2.setLayout(new BoxLayout(buttonPane2, BoxLayout.LINE_AXIS));

		stepButton = new JButton("Step");
		buttonPane2.add(stepButton);
		stepButton.setActionCommand("step");
		stepButton.addActionListener(this);

		buttonPane2.add(Box.createHorizontalGlue());

		resetButton = new JButton("Reset");
		buttonPane2.add(resetButton);
		resetButton.setActionCommand("reset");
		resetButton.setMnemonic(java.awt.event.KeyEvent.VK_ESCAPE);
		resetButton.setEnabled(false);
		resetButton.addActionListener(this);

		JPanel buttonPane = new JPanel();
		buttonPane.setLayout(new BoxLayout(buttonPane, BoxLayout.PAGE_AXIS));
		buttonPane.add(buttonPane1);
		buttonPane.add(getSeparator());
		buttonPane.add(buttonPane2);

		// Create the options JPanel

		// Create the current maze label and text field in order to set
		// the appropriate height of the text options panel.
		JLabel mazeLabel = new JLabel("Current Maze");
		mazeField = new FixedHeightTextField("", 8);
		mazeField.setEditable(false);
		final int setHeight = 4 * (mazeField.getPreferredSize().height
				+ mazeLabel.getPreferredSize().height + getSeparator()
				.getPreferredSize().height * 2);

		// Create the options panel and fix the size to the desired height
		JPanel optionsPane = new JPanel() {
			private static final long serialVersionUID = 1L;

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

		// Add the maze label and text field
		addComponentToPanel(optionsPane, mazeLabel);
		addComponentToPanel(optionsPane, mazeField);

		// Create the robot label and text field
		robotField = new FixedHeightTextField("", 8);
		robotField.setEditable(false);
		addComponentToPanel(optionsPane, new JLabel("Robot"));
		addComponentToPanel(optionsPane, robotField);

		// Create the number of moves label and text field
		moveField = new FixedHeightTextField("0", 8);
		moveField.setEditable(false);
		addComponentToPanel(optionsPane, new JLabel("Number of Moves"));
		addComponentToPanel(optionsPane, moveField);

		// Create the visited option
		visitedField = new JCheckBox();
		addComponentToPanel(optionsPane, new JLabel("Show visited halls?"));
		addComponentToPanel(optionsPane, visitedField);

		optionsPane.add(Box.createVerticalGlue());

		// combine button panel and options panel into right-hand-side panel
		final int buttonWidth = resetButton.getPreferredSize().width
				+ resetButton.getPreferredSize().width
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
		mazePanel = new MazePanel();
		canvasPane = new JPanel(new BorderLayout());
		canvasPane.setPreferredSize(mazePanel.getPreferredSize());
		canvasPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		canvasPane.add(mazePanel);
		canvasPane.setAlignmentX(Component.CENTER_ALIGNMENT);
		canvasPane.setAlignmentY(Component.CENTER_ALIGNMENT);

		// Create main panel and add the display and nonDisplay panes
		mainPane = new JPanel();
		mainPane.setLayout(new BoxLayout(mainPane, BoxLayout.LINE_AXIS));
		mainPane.add(canvasPane);
		mainPane.add(new JSeparator(JSeparator.VERTICAL));
		mainPane.add(nonDisplayPane);

		mainPane.setOpaque(true);
		frame.setContentPane(mainPane);

		// Make Menus
		JMenuBar menu = new JMenuBar();
		JMenu fileMenu = new JMenu("File");
		menu.add(fileMenu);

		JMenuItem loadMaze = new JMenuItem("Load Maze");
		loadMaze.setActionCommand("Open File");
		loadMaze.addActionListener(this);
		JMenuItem quitItem = new JMenuItem("Quit");
		quitItem.setActionCommand("Quit");
		quitItem.addActionListener(this);
		fileMenu.add(loadMaze);
		fileMenu.addSeparator();
		fileMenu.add(quitItem);

		JMenu robotMenu = new JMenu("Robot");
		menu.add(robotMenu);

		ButtonGroup robotChoices = new ButtonGroup();
		JRadioButtonMenuItem robot = new JRadioButtonMenuItem("Random Robot");
		robot.setActionCommand("RandomRobot");
		robot.addActionListener(this);
		robotChoices.add(robot);
		robotMenu.add(robot);
		robot = new JRadioButtonMenuItem("Right Hand Robot");
		robot.addActionListener(this);
		robot.setActionCommand("RightHandRobot");
		robotChoices.add(robot);
		robotMenu.add(robot);
		robot = new JRadioButtonMenuItem("Memory Robot");
		robot.setActionCommand("MemoryRobot");
		robot.addActionListener(this);
		robotChoices.add(robot);
		robotMenu.add(robot);
		robot = new JRadioButtonMenuItem("Ninja Robot");
		robot.addActionListener(this);
		robot.setActionCommand("NinjaRobot");
		robotChoices.add(robot);
		robotMenu.add(robot);

		frame.setJMenuBar(menu);

		disableGameButtons();

		// Pack the window.
		frame.pack();

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
	 * Shows the GUI.
	 */
	public void show() {
		frame.setVisible(true);
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event-dispatching thread.
	 */
	private static void createAndShowGUI() {
		// Create and set up the window.

		// Create and set up the content pane.
		MazeVizualizer mazeViz = new MazeVizualizer();
		mazeViz.show();
	}

	/**
	 * Starts up a GUI for the Maze Escaping Robots project. Run this main
	 * method to see a maze and robot in action.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		MazeVizualizer.run();
	}

	/**
	 * Properly sets up the GUI for the game instance.
	 * 
	 * @param game
	 *            the game instance to be displayed in the GUI
	 */
	public static void run() {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				MazeVizualizer.createAndShowGUI();
			}
		});
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * java.awt.evenr.ActionListener#actionPerformed(java.awt.event.ActionEvent)
	 */
	@Override
	public void actionPerformed(ActionEvent e) {
		// store the command
		final String command = e.getActionCommand();
		if (command == null)
			return;

		// open a maze file
		if ("Open File".equals(command)) {
			JFileChooser fc = new JFileChooser(defaultDir);

			int returnVal = fc.showOpenDialog(frame);

			if (returnVal == JFileChooser.APPROVE_OPTION) {
				File file = fc.getSelectedFile();
				makeMaze(file);
			}
		} else if ("Quit".equals(command)) {
			System.exit(0);
		} else if (command.contains("Robot")) { // load a robot
			makeRobot(command);
		} else if ("reset".equals(command)) { // reset the state
			reset();
		} else if ("step".equals(command)) { // move the robot one step
			step();
		} else if ("play".equals(command)) { // automatically step on a timer
			play();
		} else if ("stop".equals(command)) { // stop automatically stepping
			stop(false);
		} else if ("end".equals(command)) { // finish running the robot
			end();
		}

	}

	/**
	 * Resets the state of the maze and robot.
	 */
	private void reset() {
		if (maze != null) {
			mazeField.setText(maze.getFilename());
			mazePanel.trackVisiting(visitedField.isSelected());
			maze.resetVisited();
		}

		if (robot != null) {
			robot.enter(maze);
			robotField.setText(robot.getClass().getName());
			moveField.setText("" + robot.getMoveCount());
		}

		if (maze != null && robot != null)
			enableButtons();

		mazePanel.repaint();
	}

	/**
	 * Constructs a new Maze. There will be an error in this method until you
	 * create a Maze with a constructor that takes a String filename.
	 */
	private void makeMaze(File file) {
		// Set default directory to directory of chosen maze
		defaultDir = file.getParentFile().getAbsolutePath();

		// Setup the maze
		try {
			maze = new Maze(file.getName());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		mazePanel.setMaze(maze);
		canvasPane.setPreferredSize(mazePanel.getPreferredSize());
		canvasPane.repaint();
		reset();

		frame.pack();
	}

	/**
	 * Constructs a new robot using reflection. The reflection lets us call the
	 * RandomRobot() or RightHandRobot() or MemoryRobot() constructor without
	 * having to see the name of the class.
	 * "Whatever class it is, call that constructor". There will be an error in
	 * this method until you create a Robot class.
	 * 
	 * @param robotClass
	 *            the robot class name
	 */
	private void makeRobot(final String robotClass) {
		try {
			robot = (IRobot) Class.forName(robotClass).getConstructor()
					.newInstance();
			mazePanel.setRobot(robot);

			reset();
		} catch (ClassNotFoundException cnfe) {
			JOptionPane.showMessageDialog(this.frame, robotClass
					+ " not found in default package!", "Error!",
					JOptionPane.ERROR_MESSAGE);
		} catch (Exception e) {
			JOptionPane.showMessageDialog(this.frame, "Error loading "
					+ robotClass + "!\n" + e.getClass(), "Error!",
					JOptionPane.ERROR_MESSAGE);
			e.printStackTrace();
		}
	}

	/**
	 * Move robot by one step. Calls Robot step(), Robot.getMoveCount(), and
	 * RobotEscapeException.getMessage().
	 */
	private void step() {
		String done = null;
		try {
			robot.step();
		} catch (RobotEscapeException ree) {
			done = ree.getMessage();
			stepButton.setEnabled(false);
			stop(true);
		}
		moveField.setText("" + robot.getMoveCount());
		mazePanel.repaint();
		if (done != null)
			JOptionPane.showMessageDialog(frame, done);
	}

	/**
	 * Starts automatically stepping through robot moves until the user pushes
	 * the Stop button or the game is finished. Display is updated after each
	 * generation.
	 */
	private void play() {
		// A new timer task for stepping the game
		TimerTask tt = new TimerTask() {
			public void run() {
				step();
			}
		};

		// changes button from "Play" to "Stop"
		playButton.setText("Stop");
		playButton.setActionCommand("stop");
		stepButton.setEnabled(false);

		// registers each generation to step at .02 second increments
		playTimer.scheduleAtFixedRate(tt, 0, 20);
	}

	/**
	 * Stops automatically stepping of the game.
	 */
	private void stop(boolean finished) {
		// cancel the Timer and make a new one
		playTimer.cancel();
		playTimer = new Timer();

		// change button from "Stop" to "Play"
		playButton.setText("Play");
		playButton.setActionCommand("play");

		// determines the correct state of the next and play buttons
		if (!finished)
			enableGameButtons();
		else
			disableGameButtons();
	}

	/**
	 * Lets robot run until it finishes. Calls
	 */
	private void end() {
		stop(true);
		try {
			robot.runToEnd();
		} catch (RobotEscapeException ree) {
			moveField.setText("" + robot.getMoveCount());
			mazePanel.repaint();
			JOptionPane.showMessageDialog(frame, ree.getMessage());
		}
	}

	/**
	 * Turns on the GUI buttons
	 */
	private void enableButtons() {
		enableGameButtons();
		resetButton.setEnabled(true);
	}

	/**
	 * Turns on the state-dependent buttons
	 */
	private void enableGameButtons() {
		endButton.setEnabled(true);
		playButton.setEnabled(true);
		stepButton.setEnabled(true);
	}

	/**
	 * Turns off the state-dependent buttons
	 */
	private void disableGameButtons() {
		endButton.setEnabled(false);
		playButton.setEnabled(false);
		stepButton.setEnabled(false);
	}

}

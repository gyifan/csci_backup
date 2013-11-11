import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

/**
 * A GUI for the Rover project. Provides primitive feedback on the current state
 * of the robot's journey. Also provides a minimal amount of interactive
 * buttons.
 * <P>
 * Students do not have to edit this class.
 * 
 * @author Wittie, Cronburg, Markstrum
 * 
 */
public class Gui implements ActionListener, KeyListener {

	/** The rover */
	private IRover rover;

	/** GUI Component */
	private JFrame frame;
	/** GUI Component */
	private JTextArea taskField;
	/** GUI Component */
	private JTextArea inventoryField;
	/** GUI Component */
	private JPanel mapPanel;
	/** GUI Component */
	private GuiPanel roomPanel;

	/** GUI Component */
	private JButton returnButton;
	/** GUI Component */
	private JButton leftButton;
	/** GUI Component */
	private JButton rightButton;
	/** GUI Component */
	private JButton upButton;
	/** GUI Component */
	private JButton downButton;
	/** GUI Component */
	private JButton pickUpButton;
	/** GUI Component */
	private JButton performButton;
	/** GUI Component */
	private JButton quitButton;
	/** GUI Component */
	private JButton helpButton;

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
	 * Creates and sets up a new GUI for the project.
	 * 
	 * <PRE>
	 * Task DESCRIPTION                  Inventory ITEM
	 *      INGREDIENT                             ITEM
	 *      INGREDIENT                             ITEM
	 *      INGREDIENT
	 *      
	 *  |--------------------------|           UP
	 *  |                          |      LEFT  RIGHT
	 *  |                          |          DOWN 
	 *  |        SCREEN            |  
	 *  |                          |          Return
	 *  |                          |     PickUp PutDown
	 *  |                          |       Quit Help
	 *  |--------------------------|
	 * </PRE>
	 * 
	 * To do this:
	 * 
	 * <PRE>
	 * |---JFrame-------------------------------------------------------------------|
	 * | |---JPanel----BoxLayout--Horizontal--------------------------------------| |
	 * | | |---JPanel----BoxLayout--Vert-----|  |---JPanel---Box Vert-----------| | |
	 * | | |   JLabel                        |  |   JLabel                      | | |
	 * | | | |---JTextArea------|            |  | |---JTextArea------|          | | |
	 * | | | |   Current Task   |            |  | |   Inventory      |          | | |
	 * | | | |------------------|            |  | |                  |          | | |
	 * | |                                   |  | |                  |          | | |
	 * | | |---JPanel----------------------| |  | |                  |          | | |
	 * | | | |---GuiPanel----------------| | |  | |                  |          | | |
	 * | | | |                           | | |  | |------------------|          | | |
	 * | | | |   The room is here        | | |  |                               | | |
	 * | | | |                           | | |  | |---JPanel--Box-Vert--------| | | |
	 * | | | |                           | | |  | | |--JPanel--Flow--Center-| | | | |
	 * | | | |                           | | |  | | |        JButton        | | | | |
	 * | | | |                           | | |  | | |-----------------------| | | | |
	 * | | | |                           | | |  | | |--JPanel--Flow--Center-| | | | |
	 * | | | |                           | | |  | | |    JButton JButton    | | | | |
	 * | | | |                           | | |  | | |-----------------------| | | | |
	 * | | | |                           | | |  | |         JButton           | | | | 
	 * | | | |                           | | |  | | |--JPanel--Flow--Center-| | | | |
	 * | | | |                           | | |  | | |        JButton        | | | | |
	 * | | | |                           | | |  | | |-----------------------| | | | |
	 * | | | |                           | | |  | | |--JPanel--Flow--Center-| | | | |
	 * | | | |                           | | |  | | |    JButton JButton    | | | | |
	 * | | | |                           | | |  | | |    JButton JButton    | | | | |
	 * | | | |                           | | |  | | |-----------------------| | | | |
	 * | | | |---------------------------| | |  | |---------------------------| | | |
	 * | | |-------------------------------| |  |-------------------------------| | |
	 * | |------------------------------------------------------------------------| |
	 * |----------------------------------------------------------------------------|
	 * </PRE>
	 * 
	 * The excess JPanels around single buttons are to make spacing. Otherwise
	 * buttons on top of each other have no space between them.
	 * <P>
	 * To center the buttons, I told each button to go center itself in its
	 * container. button.setAlignmentX(Component.CENTER_ALIGNMENT);
	 * <P>
	 * Possible layouts include Border (things in the NSWE around a big CENTER)<BR>
	 * Box Aligns thing horizontally or vertically <BR>
	 * Card Aligns things with one per page (flippable pages) <BR>
	 * Flow Aligns things until they stop fitting
	 */
	public Gui() {
		rover = new Rover();

		// The current task
		JPanel taskPanel = new JPanel(new BorderLayout());
		taskPanel.setPreferredSize(new Dimension(100, 100));
		taskPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 0, 0));
		taskPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
		taskPanel.setAlignmentY(Component.CENTER_ALIGNMENT);
		taskField = new JTextArea();
		taskField.setText("Task: ");
		taskField.setEditable(false);
		taskPanel.add(taskField, BorderLayout.CENTER);
		taskPanel.add(new JLabel("Task"), BorderLayout.NORTH);

		// The current room shown from the map
		roomPanel = new GuiPanel(rover);

		// Panel to hold the current room of the map
		mapPanel = new JPanel(new BorderLayout());
		mapPanel.setPreferredSize(new Dimension(GuiPanel.GRIDSIZE + 20,
				GuiPanel.GRIDSIZE + 40)); // width, height
		mapPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 0));
		mapPanel.add(roomPanel, BorderLayout.CENTER);
		mapPanel.add(new JLabel("Map of room"), BorderLayout.NORTH);
		mapPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
		mapPanel.setAlignmentY(Component.CENTER_ALIGNMENT);

		// Left panel to hold the task and map
		JPanel leftPanel = new JPanel();
		leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS)); // vertical
		leftPanel.add(taskPanel);
		leftPanel.add(mapPanel);

		// The inventory
		inventoryField = new JTextArea();
		inventoryField.setText("Inventory: ");
		inventoryField.setEditable(false);

		JPanel invPanel = new JPanel(new BorderLayout());
		invPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		invPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
		invPanel.setAlignmentY(Component.CENTER_ALIGNMENT);
		invPanel.add(inventoryField, BorderLayout.CENTER);
		invPanel.add(new JLabel("Inventory"), BorderLayout.NORTH);

		// Buttons
		// SHOULD THESE BE arrows OR words? (left vs <--)
		rightButton = new JButton("-->");
		leftButton = new JButton("<--");
		upButton = new JButton("^");
		downButton = new JButton("V");
		pickUpButton = new JButton("Pick Up");
		performButton = new JButton("Perform Task");
		quitButton = new JButton("Quit");
		helpButton = new JButton("Help (none)");
		returnButton = new JButton("Show the way back");

		// Action listeners for the buttons
		rightButton.addActionListener(this);
		leftButton.addActionListener(this);
		downButton.addActionListener(this);
		upButton.addActionListener(this);
		pickUpButton.addActionListener(this);
		performButton.addActionListener(this);
		quitButton.addActionListener(this);
		helpButton.addActionListener(this);
		returnButton.addActionListener(this);

		// Panel for up so there is space between inventory and up
		JPanel upPanel = new JPanel();
		upPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		upPanel.add(upButton);
		upButton.setAlignmentX(Component.CENTER_ALIGNMENT);

		// Panel for the left and right buttons
		JPanel leftRightButtonsPanel = new JPanel();
		leftRightButtonsPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		leftRightButtonsPanel.add(leftButton);
		leftRightButtonsPanel.add(rightButton);

		// Panel for return (adds space between down and return
		JPanel returnPanel = new JPanel();
		returnPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
		returnPanel.add(returnButton);
		returnButton.setAlignmentX(Component.CENTER_ALIGNMENT);

		// Panel for the other buttons
		JPanel otherButtonsPanel_1 = new JPanel();
		otherButtonsPanel_1.setLayout(new FlowLayout(FlowLayout.CENTER));
		otherButtonsPanel_1.add(pickUpButton);
		otherButtonsPanel_1.add(performButton);

		// Panel for the other buttons
		JPanel otherButtonsPanel_2 = new JPanel();
		otherButtonsPanel_2.setLayout(new FlowLayout(FlowLayout.CENTER));
		otherButtonsPanel_2.add(quitButton);
		otherButtonsPanel_2.add(helpButton);

		// Panel to hold the buttons
		JPanel buttonPanel = new JPanel();
		buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS)); // vertical
		buttonPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
		buttonPanel.add(upPanel);
		buttonPanel.add(leftRightButtonsPanel);
		buttonPanel.add(downButton);
		downButton.setAlignmentX(Component.CENTER_ALIGNMENT);
		buttonPanel.add(returnPanel);
		buttonPanel.add(otherButtonsPanel_1);
		buttonPanel.add(otherButtonsPanel_2);

		// Right panel to hold the inventory and buttons
		JPanel rightPanel = new JPanel();
		rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.Y_AXIS)); // vertical
		rightPanel.add(invPanel);
		rightPanel.add(buttonPanel);

		// Create main panel to hold the left and right panels
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.X_AXIS)); // horizontal
		mainPanel.add(leftPanel);
		mainPanel.add(rightPanel);
		mainPanel.setOpaque(true);

		// Outer frame
		frame = new JFrame("Lost Rovers");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setContentPane(mainPanel);
		mapPanel.addKeyListener(this);
		frame.pack();

		updateGui();
	}

	/**
	 * Returns the standard separator between Components in the GUI.
	 * 
	 * @return a blank rigid area 5 pixels wide.
	 */
	private static Component getSeparator() {
		return Box.createRigidArea(new Dimension(10, 10));
	}

	/**
	 * Shows the GUI.
	 */
	public void show() {
		frame.setVisible(true);
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			System.out.println("Sleeping Interrupted.");
		}
		mapPanel.requestFocusInWindow();
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event-dispatching thread.
	 */
	private static void createAndShowGUI() {
		Gui mazeViz = new Gui();
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
		Gui.run();
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
				Gui.createAndShowGUI();
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

		if ("Quit".equals(command)) {
			System.exit(0);
		} else if ("Pick Up".equals(command)) {
			rover.pickUp();
		} else if ("Perform Task".equals(command)) {
			rover.performTask();
		} else if ("Show the way back".equals(command)) {
			rover.showTheWayBack();
		} else if ("Help".equals(command)) {
			// stop(false);
		} else if ("-->".equals(command)) {
			rover.goRight();
		} else if ("<--".equals(command)) {
			rover.goLeft();
		} else if ("V".equals(command)) {
			rover.goDown();
		} else if ("^".equals(command)) {
			rover.goUp();
		}

		updateGui();

	}

	/**
	 * ASCII: Up = 38 Down = 40 Left = 37 Right = 39 SPACE = 32
	 */
	public void keyPressed(KeyEvent e) {
		int action = e.getKeyCode();

		if (action == 38) {
			rover.goUp();
		} else if (action == 40) {
			rover.goDown();
		} else if (action == 37) {
			rover.goLeft();
		} else if (action == 39) {
			rover.goRight();
		} else if (action == 32) {
			rover.pickUp();
		}

		updateGui();
	}

	public void keyReleased(KeyEvent e) {
	}

	public void keyTyped(KeyEvent e) {
	}

	private void updateGui() {
		// update contents of inventory, task, and the room
		inventoryField.setText(rover.getInventory());
		taskField.setText(rover.getTask());
		roomPanel.repaint();
		mapPanel.requestFocusInWindow();
	}

}

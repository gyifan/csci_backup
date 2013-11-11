// ShowImage class to demo displaying icons (gifs or jpg) in JLabel
// Reference: "Java: How to Program" Deitel & Deitel, 6th edition, page 518
// By Dan Hyde, February 3, 2005

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

/*
 * This class demonstrates displaying icons (gifs or jpg) in JLabel. Excercise 1
 * & 2.
 * 
 * @author Yifan Ge
 * 
 */
public class ShowImage extends JFrame {
	private static final long serialVersionUID = 1L;
	private JPanel panel;

	// constructor
	public ShowImage() {

		// Get the container associated with the window
		// to hold graphical components
		Container contentPane = getContentPane();

		// create a JPanel to hold the images
		panel = new JPanel();

		// Set the Layout to GridLayout with 1 rows and 2 columns.
		// 10 pixels separate the horizontal and vertical parts
		GridLayout grid = new GridLayout(1, 2, 10, 10);

		// set Layout of panel to be grid.
		panel.setLayout(grid);

		// Initialize graphical components

		// SwingConstants.RIGHT to right justify the text in JLabel
		// Other class constants are LEFT and CENTER
		JLabel label1 = new JLabel("A JLabel with Text", SwingConstants.RIGHT);

		// load a jpg or gif file in same directory
		Icon cat = new ImageIcon(getClass().getResource("cat-lion.jpg"));

		JLabel label2 = new JLabel("label with text and icon", cat,
				SwingConstants.LEFT);
		// can load an animated gif
		Icon garfield = new ImageIcon(getClass().getResource("garfield.gif"));

		JLabel label3 = new JLabel(" ");
		label3.setIcon(garfield);

		panel.add(label2);
		panel.add(label3);

		// Add JLabel and panel to container

		contentPane.add(label1, BorderLayout.NORTH);
		contentPane.add(panel, BorderLayout.CENTER);

		// Set the title on the title bar

		setTitle("ShowImage");

		// Set location of upper left corner of window

		setLocation(500, 250);

		// Set size of window
		setSize(650, 650);

		// When user closes window, the program terminates
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Make the window visible to the user
		setVisible(true);
	}

	public static void main(String[] args) {

		// Create a window as JFrame object

		@SuppressWarnings("unused")
		ShowImage theWindow = new ShowImage();
	}
}

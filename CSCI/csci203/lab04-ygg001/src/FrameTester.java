import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JTextField;

/**
 * CSCI 203, Yifan Ge
 * Sep 21, 2010, 11:09:28 AM
 */

/**
 * @author ygg001
 * 
 */
public class FrameTester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(100, 100);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Add a JTextField component that displays some text on the frame

		JTextField myText = new JTextField("Hello, Yifan!");
		Color hotPink = new Color(255, 105, 180);
		myText.setBackground(hotPink);
		frame.add(myText);

		frame.setVisible(true);
	}

}

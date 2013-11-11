import java.awt.Color;

import javax.swing.JFrame;

/**
 * CSCI 203, Yifan Ge
 * Oct 2, 2010, 1:47:06 PM
 */

/**
 * This class displays a window on the screen.
 * 
 * @author GE
 * 
 */
public class BarChartViewer {

	/**
	 * Creates and displays a window.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		JFrame frame = new JFrame("Bridge Spans");
		final int frameWidth = 500;
		final int frameHeight = 400;
		frame.setSize(frameWidth, frameHeight);
		frame.getContentPane().setBackground(Color.WHITE);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(new BarChartComponent());
		frame.setVisible(true);
	}
}

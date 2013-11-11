import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JComponent;

/**
 * CSCI 203, Yifan Ge
 * Oct 2, 2010, 1:51:47 PM
 */

/**
 * This class creates and displays Bar Chart.
 * 
 * @author GE
 * 
 */
@SuppressWarnings("serial")
public class BarChartComponent extends JComponent {

	/*
	 * (non-Javadoc)
	 * 
	 * @see javax.swing.JComponent#paintComponent(java.awt.Graphics)
	 */
	public void paintComponent(Graphics canvas) {
		Graphics2D canvas2D = (Graphics2D) canvas;

		// Draws the bar for Golden Gate

		int barY = 0;
		int longestSpan = 4200;
		int barWidth = longestSpan / 10;
		String barTitle = "Golden Gate";
		Color barColor = Color.RED;
		Bar goldenGate = new Bar(barY, barWidth, barTitle, barColor);
		goldenGate.draw(canvas2D);

		// Draws the bar for Brooklyn

		barY = barY + 100;
		longestSpan = 1595;
		barWidth = longestSpan / 10;
		barTitle = "Brooklyn";
		barColor = Color.GREEN;
		Bar brooklyn = new Bar(barY, barWidth, barTitle, barColor);
		brooklyn.draw(canvas2D);

		// Draws the bar for Delaware Memorial

		barY = barY + 100;
		longestSpan = 2150;
		barWidth = longestSpan / 10;
		barTitle = "Delaware Memorial";
		barColor = Color.CYAN;
		Bar delawareMemorial = new Bar(barY, barWidth, barTitle, barColor);
		delawareMemorial.draw(canvas2D);

		// Draws the bar for Mackinac

		barY = barY + 100;
		longestSpan = 3800;
		barWidth = longestSpan / 10;
		barTitle = "Mackinac";
		barColor = Color.YELLOW;
		Bar mackinac = new Bar(barY, barWidth, barTitle, barColor);
		mackinac.draw(canvas2D);

	}

}

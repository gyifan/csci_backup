/*
 * Name: Shane Markstrum
 * Date: 3/16/10
 * Section: CSCI203 02
 * Project: 5
 */
import java.awt.geom.Point2D;
import java.util.Scanner;

import javax.swing.JOptionPane;

/**
 * Utilities for the Line and LineTester classes.
 * 
 * @author sm053
 * 
 */
public class LineUtils {

	/**
	 * Shows an input dialog that provides a choice of ways to create a Line.
	 * Results of this method indicate the following choices:
	 * <ul>
	 * <li>-1 = cancel/quit the program
	 * <li>0 = create line based on point/slope constructor
	 * <li>1 = create line based on point/point constructor
	 * <li>2 = create line based on slope/y-intercept constructor
	 * <li>3 = create line based on x-intercept constructor
	 * </ul>
	 * 
	 * @param prompt
	 *            the title of the input dialog window
	 * @return user's choice for line construction
	 */
	public static int showLineDialog(String prompt) {
		Object[] possibleValues = { "Point/slope", "Point/Point",
				"slope/y-intercept", "x-intercept" };
		String selectedValue = (String) JOptionPane.showInputDialog(null,
				"Select an input method", prompt,
				JOptionPane.INFORMATION_MESSAGE, null, possibleValues,
				possibleValues[0]);
		if (selectedValue != null) {
			for (int i = 0; i < possibleValues.length; i++) {
				if (possibleValues[i].equals(selectedValue)) {
					return i;
				}
			}
		}
		return -1;
	}

	/**
	 * Parses a Point2D.Double from a string. Representation expects the form:
	 * (x,y)
	 * 
	 * @param input
	 *            the String representation of the point
	 * @return a Point2D.Double object matching the provided input
	 */
	public static Point2D.Double parsePoint(String input) {
		input = input.replaceAll("\\(|,|\\)", " ");
		Scanner scanString = new Scanner(input);
		double x = scanString.nextDouble();
		double y = scanString.nextDouble();
		return new Point2D.Double(x, y);
	}
}
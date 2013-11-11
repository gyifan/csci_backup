import javax.swing.JOptionPane;

/**
 * CSCI 203, Rick Zaccone
 *
 */

/**
 * Convert Fahrenheit temperatures to Celsius
 * 
 * Illustrate I/O of ints and doubles and arithmetic operations
 * 
 * @author zaccone
 * 
 */
public class FahrCels {

	private static final double CONVERSION_FACTOR = (5.0 / 9.0);
	private static final double FAHRENHEIT_FREEZING_POINT = 32.0;

	/**
	 * Demonstrates problems that can occur when doing mixed mode arithmetic.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {

		String temperature = JOptionPane
				.showInputDialog("Fahrenheit temperature:");
		double fahrenheit = Double.parseDouble(temperature);
		double celsius = (fahrenheit - FAHRENHEIT_FREEZING_POINT)
				* CONVERSION_FACTOR;
		JOptionPane.showMessageDialog(null, "Celsius: " + celsius);
		System.exit(0);
	}
}

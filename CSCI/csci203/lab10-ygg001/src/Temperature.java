/**
 * Prints a table of temperatures in Celsius to Fahrenheit.
 * 
 * @author Dan Hyde
 * 
 */
public class Temperature {

	public Temperature() {

	}

	/**
	 * Prints a table of temperatures in Celsius and Fahrenheit from
	 * lowerCelsius to upperCelsius in steps of 5 degrees Celsius using a while
	 * loop. If lowerCelsius greater than or equal upperCelsius, the method
	 * prints an error message and then returns. The temperatures are printed
	 * with one decimal point.
	 * 
	 * 
	 * @param lowerCelsius
	 *            smallest Celsius value in the table
	 * @param upperCelsius
	 *            upper bound on Celsius value in the table
	 */
	public void celsiusToFahrenheit(double lowerCelsius, double upperCelsius) {
		if (lowerCelsius >= upperCelsius)
			System.err.println("Lower bound must be less than upper bound.\n");
		else {
			System.out.println("Celsius	  Fahrenheit");
			double temperature = lowerCelsius;
			while (temperature < upperCelsius) {
				double fahrenheit = temperature * 9 / 5 + 32;
				System.out.printf(" %5.1f %11.1f\n", temperature, fahrenheit);
				temperature += 5.0;
			}
		}

	}

	/**
	 * Tests the celsiusToFahrenheit method.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		System.out.println("Testing a Table from 0 to 20 Celsius");
		Temperature table1 = new Temperature();
		table1.celsiusToFahrenheit(0.0, 20.0);

		System.out.println("Expected:\nCelsius   Fahrenheit\n"
				+ "   0.0        32.0\n" + "   5.0        41.0\n"
				+ "  10.0        50.0\n" + "  15.0        59.0\n"
				+ "  20.0        68.0\n");

		System.out.println("Testing a Table from -10 to 3 Celsius");
		table1.celsiusToFahrenheit(-10.0, 3.0);
		System.out.println("Expected:\nCelsius   Fahrenheit\n"
				+ " -10.0        14.0\n" + "  -5.0        23.0\n"
				+ "   0.0        32.0 \n");

		System.out.println("Testing a Table from 20 to 10 Celsius");
		table1.celsiusToFahrenheit(20.0, 10.0);
		System.out
				.println("Expected: Lower bound must be less than upper bound.\n");

		System.out.println("Testing a Table from 10 to 10 Celsius");
		table1.celsiusToFahrenheit(10.0, 10.0);
		System.out
				.println("Expected: Lower bound must be less than upper bound.\n");
	}

}

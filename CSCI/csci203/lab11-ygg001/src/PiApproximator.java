import java.util.Random;

/**
 * This class implements the throwing of a dart to approximate pi.
 */
public class PiApproximator {
	private static final double AREA_OF_SQUARE = 4.0;
	private Random generator;
	private int hits;
	private int tries;

	/**
	 * Creates a pi approximator object.
	 */
	public PiApproximator() {
		generator = new Random();
		generator.setSeed(17);
		hits = 0;
		tries = 0;
	}

	/**
	 * Throws a dart into the unit square and records whether it hits the unit
	 * circle. Generate values for x and y in the range [-1.0, 1.0) and see if
	 * the point (x,y) is in the unit circle.
	 */
	private void throwDartIntoSquare() {
		tries++;
		double x = 1.0 - 2 * generator.nextDouble();
		double y = 1.0 - 2 * generator.nextDouble();
		if (Math.sqrt(x * x + y * y) <= 1)
			hits++;
	}

	/**
	 * Throws a dart the requested number of times.
	 * 
	 * @param n
	 *            the number of times to throw a dart
	 */
	public void throwDartNTimes(int n) {
		for (int i = 0; i < n; i++)
			throwDartIntoSquare();
	}

	/**
	 * Gets the current approximation to pi.
	 * 
	 * @return an approximation to pi
	 */
	public double getApproximation() {
		return AREA_OF_SQUARE * hits / tries;
	}

	/**
	 * Simulates throwing a dart into a square, trying to hit a circle.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		final int tries = 100000;
		PiApproximator myApproximator = new PiApproximator();
		myApproximator.throwDartNTimes(tries);
		System.out.println("Approximation of pi = "
				+ myApproximator.getApproximation());
	}
}

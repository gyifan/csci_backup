/**
 * CSCI 203, Yifan Ge
 * Oct 5, 2010, 10:51:07 AM
 */

/**
 * This class takes attendance of a sports arena.
 * 
 * @author Yifan Ge
 * 
 */
public class Attendance {

	/**
	 * Takes attendance of the given sports arena.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		Clicker northCount = new Clicker();
		Clicker southCount = new Clicker();
		Clicker westCount = new Clicker();
		Clicker eastCount = new Clicker();
		int total;

		// Counts the North door.

		northCount.increment();
		northCount.increment();
		northCount.increment();

		// Counts the South door.

		southCount.increment();
		southCount.increment();

		// Counts the West door.

		westCount.increment();
		westCount.increment();
		westCount.increment();
		westCount.increment();
		westCount.increment();

		// Counts the East door.

		// Calculate the total attendance.
		total = northCount.getValue() + southCount.getValue()
				+ westCount.getValue() + eastCount.getValue();
		System.out.println("Total number of people who attend the event: "
				+ total);

	}

}

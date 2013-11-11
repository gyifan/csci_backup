/**
 * This class determines if a year is a leap year.
 */
public class Year {
	private static final int GREGORIAN_START = 1582;
	private int year;

	/**
	 * Creates a Year object to test whether a particular year is a leap year.
	 * 
	 * @param aYear
	 *            is the year to be tested
	 */
	public Year(int aYear) {
		year = aYear;
	}

	/**
	 * Gets the year.
	 * 
	 * @return the year
	 */
	public int getYear() {
		return year;
	}

	/**
	 * Sets the year.
	 * 
	 * @param year
	 *            the year to set
	 */
	public void setYear(int year) {
		this.year = year;
	}

	/**
	 * Determines if a year is a leap year.
	 * 
	 * @return boolean true year is a leap year
	 */
	public boolean isLeapYear() {
		int leapYearDividingFactor1 = 4;
		int leapYearDividingFactor2 = 100;
		int leapYearDividingFactor3 = 400;
		if (year < 1582 && year % leapYearDividingFactor1 == 0)
			return true;
		else if (year >= 1582
				&& year % leapYearDividingFactor1 == 0
				&& !(year % leapYearDividingFactor2 == 0 && year
						% leapYearDividingFactor3 != 0))
			return true;
		else
			return false;
	}

	/**
	 * Tests the Year class.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Year y = new Year(1980);
		System.out.printf("%8d: %s\n", y.getYear(), y.isLeapYear());
		System.out.println("Expected: true\n");

		y.setYear(1900);
		System.out.printf("%8d: %s\n", y.getYear(), y.isLeapYear());
		System.out.println("Expected: false\n");

		y.setYear(2000);
		System.out.printf("%8d: %s\n", y.getYear(), y.isLeapYear());
		System.out.println("Expected: true\n");

		y.setYear(1500);
		System.out.printf("%8d: %s\n", y.getYear(), y.isLeapYear());
		System.out.println("Expected: true\n");

		y = new Year(1501);
		System.out.printf("%8d: %s\n", y.getYear(), y.isLeapYear());
		System.out.println("Expected: false\n");
	}
}

import java.text.DateFormatSymbols;

/**
 * This Class has constructors and methods about dates.
 * 
 * @author Yifan Ge
 * 
 */
public class Dates implements Date {

	private int month;
	private int day;
	private int year;

	/**
	 * Constructs a default Dates object.
	 */
	public Dates() {
		month = 1;
		day = 1;
		year = 1970;
	}

	/**
	 * Constructs a Dates object with given values
	 * 
	 * @param month
	 *            the month
	 * @param day
	 *            the day
	 * @param year
	 *            the year
	 */
	public Dates(int month, int day, int year) {
		super();
		this.month = month;
		this.day = day;
		this.year = year;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see Date#displayShort()
	 */
	@Override
	public void displayShort() {
		String year = "" + this.year;
		String yearShort = year.substring(2);
		System.out.printf("%02d" + "/" + "%02d" + "/" + yearShort, month, day);

	}

	/*
	 * (non-Javadoc) || month == 12
	 * 
	 * @see Date#displayVerbose()
	 */
	@Override
	public void displayVerbose() {
		String monthVerbose = new DateFormatSymbols().getMonths()[month - 1];
		System.out.printf(monthVerbose + " %02d, " + year, day);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see Date#nextDay()
	 */
	@Override
	public void nextDay() {
		day += 1;
		if (day < 29) {
		} else if ((day == 32 && (month == 1 || month == 3 || month == 5
				|| month == 7 || month == 8 || month == 10))
				|| (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))) {
			day = 1;
			month += 1;
		} else if (day == 32 && month == 12) {
			day = 1;
			month = 1;
			year += 1;
		} else if (!isLeapYear() && month == 2) {
			day = 1;
			month += 1;
		} else if (month == 2 && day == 30) {
			day = 1;
			month += 1;
		}

	}

	/**
	 * Checks wether the year is a leap year.
	 * 
	 * @return wether the year is a leap year
	 */
	public boolean isLeapYear() {
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		else if (year % 400 == 0)
			return true;
		else
			return false;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see Date#setDate(int, int, int)
	 */
	@Override
	public void setDate(int month, int day, int year) {
		this.month = month;
		this.day = day;
		this.year = year;

	}
}

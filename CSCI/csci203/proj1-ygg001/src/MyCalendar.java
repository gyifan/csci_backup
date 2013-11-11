import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Locale;

/**
 * CSCI 203, Section 1, Yifan Ge
 * Sep 16, 2010, 1:58:02 AM
 */

/**
 * @author GALEN
 * 
 */
public class MyCalendar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		GregorianCalendar today = new GregorianCalendar();
		System.out.println("Today is " + (today.get(Calendar.MONTH) + 1) + "/"
				+ today.get(Calendar.DAY_OF_MONTH) + "/"
				+ today.get(Calendar.YEAR));

		GregorianCalendar myBirthday = new GregorianCalendar(1990,
				Calendar.JANUARY, 15);
		String dayOfBirthday = myBirthday.getDisplayName(Calendar.DAY_OF_WEEK,
				2, Locale.ENGLISH);
		System.out.println("The weekday of my birthday is " + dayOfBirthday
				+ ".");
		GregorianCalendar tenThousandDaysAfterMyBirthday;
		myBirthday.add(Calendar.DAY_OF_MONTH, 10000);
		tenThousandDaysAfterMyBirthday = myBirthday;
		System.out.println("10,000 days from my birthday is "
				+ (tenThousandDaysAfterMyBirthday.get(Calendar.MONTH) + 1)
				+ "/"
				+ tenThousandDaysAfterMyBirthday.get(Calendar.DAY_OF_MONTH)
				+ "/" + tenThousandDaysAfterMyBirthday.get(Calendar.YEAR));

	}
}

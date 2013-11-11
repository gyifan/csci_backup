import java.util.Scanner;

/**
 * CSCI 203, Yifan Ge
 * Nov 5, 2010, 3:05:38 AM
 */

/**
 * This class translates information from icalendar to html format.
 * 
 * @author Yifan Ge
 * 
 */
public class CalendarTranslater {

	/**
	 * Converts icalendar file to html file
	 * 
	 * @param args
	 *            ical file
	 */
	public static void main(String[] args) {
		if (args.length != 1 || !args[0].endsWith(".ics")) {
			System.err.println("Please enter a .ics file!");
			System.exit(0);
		}
		Scanner file = TranslatorUtils.openFile(args[0]);
		int numberOfEvent = 0;

		System.out.println("<html>\n" + "<head>\n" + "<title>" + args[0]
				+ "</title>\n" + "</head>\n");
		System.out.println("<body>\n" + "<ul>");
		file = TranslatorUtils.openFile(args[0]);
		String line = file.nextLine();
		while (!line.equals("BEGIN:VEVENT")) {
			line = file.nextLine();
		}
		while (!line.equals("END:VCALENDAR")) {
			if (line.equals("BEGIN:VEVENT")) {
				numberOfEvent++;
				System.out.println("<li>Event " + numberOfEvent + "\n"
						+ "  <ul>");
			}
			if (line.startsWith("LOCATION")) {
				String[] location = line.split(":");
				System.out.println("  <li><b>Location:</b> " + location[1]
						+ "</li>");
			}
			if (line.startsWith("DTSTART")) {
				System.out.println("  <li><b>Start time:</b> "
						+ timeConverter(line) + "</li>");
			}
			if (line.startsWith("SUMMARY")) {
				String[] summary = line.split(":");
				System.out.println("  <li><b>Summary:</b> " + summary[1]
						+ "</li>");
			}
			if (line.startsWith("DTEND")) {
				System.out.println("  <li><b>End time:</b> "
						+ timeConverter(line) + "</li>");
			}
			if (line.startsWith("DURATION")) {
				System.out.println("  <li><b>Duration:</b> "
						+ durationConverter(line) + "</li>");
			}
			if (line.startsWith("DESCRIPTION")) {
				String[] description = line.split(":");
				System.out.println("  <li><b>Description:</b> "
						+ description[1] + "</li>");
			}
			if (line.equals("END:VEVENT")) {
				System.out.println("  </ul>\n" + "</li>");
			}
			line = file.nextLine();
		}
		System.out.println("</ul>\n" + "</body>\n" + "</html>");
	}

	/**
	 * Converts ical time format to MM/DD/YEAR HH:MM
	 * 
	 * @param time
	 *            start/end time string in ical file
	 * @return the time in format of MM/DD/YEAR HH:MM
	 */
	private static String timeConverter(String time) {
		String[] split = time.split(":");
		int timeArray = 1;
		int yearStartsIndex = 0;
		int yearEndsIndex = 4;
		int monthStartsIndex = 4;
		int monthEndsIndex = 6;
		int dayStartsIndex = 6;
		int dayEndsIndex = 8;
		int hourStartsIndex = 9;
		int hourEndsIndex = 11;
		int minStartIndex = 11;
		int minEndsIndex = 13;
		String year = split[timeArray]
				.substring(yearStartsIndex, yearEndsIndex);
		String month = split[timeArray].substring(monthStartsIndex,
				monthEndsIndex);
		String day = split[timeArray].substring(dayStartsIndex, dayEndsIndex);
		String hour = split[timeArray]
				.substring(hourStartsIndex, hourEndsIndex);
		String min = split[timeArray].substring(minStartIndex, minEndsIndex);
		return month + "/" + day + "/" + year + " " + hour + ":" + min;
	}

	/**
	 * Converts duration time from ical format to HH:MM
	 * 
	 * @param duration
	 *            duration string in ical file
	 * @return the duration in format of HH:MM
	 */
	private static String durationConverter(String duration) {
		if (duration.length() > 13) {
			int hourStartsIndex = 11;
			int hourEndsIndex = 12;
			int minStartsIndex = 13;
			int minEndsIndex = 14;
			String hour = duration.substring(hourStartsIndex, hourEndsIndex);
			String min = duration.substring(minStartsIndex, minEndsIndex);
			return "0" + hour + ":0" + min;
		} else {
			int hourStartsIndex = 11;
			int hourEndsIndex = 12;
			String hour = duration.substring(hourStartsIndex, hourEndsIndex);
			return "0" + hour + ":00";
		}
	}
}

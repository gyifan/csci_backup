/*
 * HTMLTagCounter
 * 
 * Simple text-based HTML tag parser. It will ask the user for the name of a URL, open a connection
 * to it, and sift through it looking for a given HTML tag. It will print the occurrences it finds
 * and count occurrences of the tag, reporting the number of occurrences at the end
 * 
 * CSCI204
 * 
 * @author Professor King
 */
import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;

/*
 * HTMLTagCounter - open a connection to a given URL and sift through the input stream looking
 * for a specified HTML tag.
 */
public class HTMLTagCounter {

	/*
	 * Purpose: Obtain the URL from the user.
	 * 
	 * How: Ask the user to enter one of: b, q, or a URL If the user enters b,
	 * use http://www.bucknell.edu If the user enters q, quit If the user enters
	 * a URL, use that URL
	 * 
	 * Returns the URL or null (for quitting)
	 * 
	 * TODO: You need to modify this to repeat until a user enters a correctly
	 * formed URL. Check the API for java.net.URL and see what exception the
	 * constructor throws. Make sure it still properly checks to see if the user
	 * enters a 'q'.
	 */
	public static URL readURLFromUser() {
		// Set up the Scanner on the console input
		Scanner in = new Scanner(System.in);
		while (1 == 1) {
			try {

				// Prompt the user
				System.out
						.println("Enter a valid URL [Or, 'b' for http://www.bucknell.edu, or 'q' to quit]: ");

				// Read in the next String token -- which is hopefully a URL
				String sURL = in.next();

				// If the user entered q, then they want to quit
				if (sURL.equalsIgnoreCase("q"))
					return null;

				// If the user entered b, then use the default URL
				else if (sURL.equals("b"))
					sURL = new String("http://www.bucknell.edu");

				// We have a URL string -- convert it to a URL
				return (new URL(sURL));
			} catch (MalformedURLException e) {
				System.out
						.println("Your URL was invalid, please check your URL.");
			}
		}
	}

	/*
	 * Purpose: Print the count of <ul> and <p> tags in an HTML webpage.
	 * 
	 * How: Get a URL from the user. (If the URL is null, quit) Then open an
	 * HTTP connection to that URL and open a BufferedInputStream to read the
	 * characters on the website. Read the characters and count the <ul> and <p>
	 * tags.
	 * 
	 * Warning: Tags may contain excess data such as <p attr_name="blahblah"> or
	 * use upper case letters <P> and <UL>
	 * 
	 * Prints: the count of <ul> and <p> tags
	 * 
	 * TODO: You need to modify this to count the <ul> and <p> tags. You will
	 * need to read the Java API to learn how to read characters off a
	 * BufferedInputStream.
	 */
	public static void main(String[] args) {

		// Get a valid URL from the user
		URL u = readURLFromUser();

		// If u was null, then exit.
		if (u == null) {
			System.out.println("Goodbye");
			System.exit(1);
		}
		try {
			// Open the connection to the URL
			HttpURLConnection connection = (HttpURLConnection) u
					.openConnection();

			// Create the stream from the connection
			BufferedInputStream in = new BufferedInputStream(connection
					.getInputStream());
			System.out.println("Connected to: " + connection.getURL());

			int numOfP = 0;
			int numOfUl = 0;
			int input;
			char readChar;
			boolean startCount = false;
			boolean isPTag = false;
			int ul = 0;

			System.out.print("Scanning... ");
			while ((input = in.read()) != -1) {
				readChar = (char) input;
				if (readChar == '<')
					startCount = true;
				else if (startCount && !isPTag && (ul == 0)) {
					if (readChar == 'p')
						isPTag = true;
					else if (readChar == 'u')
						ul++;
					else
						startCount = false;
				} else if (isPTag && ((readChar == '>') || (readChar == ' '))) {
					numOfP++;
					isPTag = false;
				} else if ((ul == 1) && (readChar == 'l'))
					ul++;
				else if ((ul == 2) && ((readChar == '>') || (readChar == ' '))) {
					numOfUl++;
					ul = 0;
				} else {
					startCount = false;
					isPTag = false;
					ul = 0;
				}
			}

			System.out.println("finished.\n");
			System.out.println("<p>: " + numOfP + "\n");
			System.out.println("<ul>: " + numOfUl + "\n");
		} catch (IOException e) {
		}
		System.out.println("Closing connection.");
	}
}

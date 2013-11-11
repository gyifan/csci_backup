import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Project:
 * File: TranslatorUtils.java
 * Author: Shane Markstrum, sm053
 * Date: Apr 3, 2010
 */

/**
 * Utility method for opening files.
 * 
 * @author sm053
 * 
 */
public class TranslatorUtils {

	/**
	 * Opens a file for reading from a Scanner. If the file does not exist, this
	 * method will end the program.
	 * 
	 * @param fileName
	 *            the name of a file to open
	 * @return a Scanner set to read from the file
	 */
	public static Scanner openFile(String fileName) {
		File file = new File(fileName);
		Scanner fileIn = null;
		try {
			fileIn = new Scanner(file);
		} catch (FileNotFoundException e) {
			System.err.println(fileName + " not found!");
			System.exit(0);
		}
		return fileIn;
	}

}
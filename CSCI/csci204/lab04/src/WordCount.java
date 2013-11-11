/**
 * WordCount.java
 * 
 * A slightly simplified version of the Linux wc utility program. 
 */
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * WordCount - Class that opens a file and counts the total number of bytes,
 * words and lines.
 * 
 */
public class WordCount {

	final static int TAB = 9;
	final static int NEWLINE = 10;
	final static int SPACE = 32;

	private BufferedReader in;
	private int wordCount;
	private int lineCount;
	private int charCount;
	private File f;
	private FileReader reader;

	public WordCount(File f) {
		wordCount = 0;
		lineCount = 0;
		charCount = 0;
		this.f = f;

		try {
			reader = new FileReader(f);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}

		in = new BufferedReader(reader);
		int count = 0;
		boolean ifInWord = false;

		try {
			while ((count = in.read()) != -1) {
				charCount++;
				if (count == NEWLINE) {
					lineCount++;
					ifInWord = false;
				} else if (count == SPACE)
					ifInWord = false;
				else if (count == TAB)
					ifInWord = false;
				else if (!ifInWord) {
					wordCount++;
					ifInWord = true;
				}
			}
		} catch (IOException e) {
		}

	}

	public void printResult() {
		System.out.println(lineCount + "\t" + wordCount + "\t" + charCount
				+ "\t" + f.getName());
	}

	public static void main(String[] args) {
		System.out.println("WordCount - Enter a filename: ");
		String filename = (new Scanner(System.in)).next();
		File f = new File(filename);
		if (!f.exists()) {
			System.err.println(filename
					+ ": File not found. Program terminated.");
			System.exit(1);
		}

		WordCount wc = new WordCount(f);
		wc.printResult();
	}
}

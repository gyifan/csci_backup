package Streams;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

/*
 * What happens if you forget to close an output file?
 * What happens if you forget to close a file and then try to open it again?
 * Does the PrintWriter overwrite or append a file when used?
 */
public class NonClosed {
	public static void main(String[] args) {
		try {
			// Write to a file (or PrintWriter)
			FileWriter out = new FileWriter("nonclosedFileIO.txt", false);
			out.write("3 4 5\n");
			out.close(); // forget to close it

			/*
			 * String temp = ""; FileReader inFile2 = new
			 * FileReader("nonclosedFileIO.txt"); Scanner in2 = new
			 * Scanner(inFile2); while (in2.hasNext()) { temp += in2.nextLine();
			 * }
			 */

			FileWriter out2 = new FileWriter("nonclosedFileIO.txt", true);
			// out2.println(temp);
			out2.write("6 5 7\n");
			out2.write("8 1 4\n");
			out2.close();

			// Read from the file
			FileReader inFile = new FileReader("nonclosedFileIO.txt");
			Scanner in = new Scanner(inFile);
			while (in.hasNextInt()) {
				System.out.println(in.nextInt());
			}

		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}

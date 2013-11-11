package Streams;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

//Reading from/writing to files
public class FileIO {
	public static void main(String[] args) {
		try {
			// Write to a file
			PrintWriter out = new PrintWriter("FileIO.txt");
			out.println("3 4 5");
			out.close();

			// Read from the file
			FileReader inFile = new FileReader("FileIO.txt");
			Scanner in = new Scanner(inFile);
			int x = in.nextInt();
			int y = in.nextInt();
			int z = in.nextInt();

			// Double-check what we read in
			System.out.println(x + " " + y + " " + z);
		} catch (Exception e) {
			// let exceptions be quiet
		}
	}
}

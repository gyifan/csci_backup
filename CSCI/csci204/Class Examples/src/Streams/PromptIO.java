package Streams;

import java.util.Scanner;

//Reading and writing to/from the prompt
public class PromptIO {
	public static void main(String[] args) {
		// Reading
		Scanner in = new Scanner(System.in);
		System.out.print("Type in some text and hit return: ");
		String s = in.nextLine();

		// Writing
		System.out.println(s);
	}

}

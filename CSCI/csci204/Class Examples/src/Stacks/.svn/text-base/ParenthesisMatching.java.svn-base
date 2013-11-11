package Stacks;

import java.util.Scanner;
import java.util.Stack;

public class ParenthesisMatching {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Stack stack = new Stack();
		String open = "({[";
		String closed = ")}]";

		// while (scanner.hasNextLine()) {
		String line = scanner.nextLine();
		String[] tokens = line.split(" ");
		for (String next : tokens) {
			// System.out.println(next);
			if (open.contains(next)) {
				stack.push(next);
			} else if (closed.contains(next)) {
				try {
					String popped = (String) stack.pop();
					int index = open.indexOf(popped);
					if (closed.indexOf(next) != index) {
						System.out.println("Unmatched Brace");
						return;
					}
				} catch (Exception e) {
					System.out.println("Unmatched Brace");
					return;
				}
			}

		}
		if (stack.isEmpty())
			System.out.println("We're good");

		else
			System.out.println("Extra open braces");
	}

}

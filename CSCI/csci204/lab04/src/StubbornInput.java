import java.util.Scanner;

/**
 * CSCI 204, Yifan Ge
 * Assiangment lab04
 * Created: Feb 10, 2011, 10:36:02 AM
 */

/**
 * @author ygg001
 * 
 */
public class StubbornInput {
	Scanner in;

	public StubbornInput() {
		in = new Scanner(System.in);
	}

	public int nextInt(String prompt, String errorMessage) {
		while (1 == 1) {
			try {
				System.out.print(prompt);
				int x = Integer.parseInt(in.next());
				return x;
			} catch (java.lang.NumberFormatException e) {
				System.out.println(errorMessage);
			}
		}

	}

	public boolean nextBool(String prompt, String errorMessage) {
		while (1 == 1) {
			try {
				System.out.print(prompt);
				boolean b = in.nextBoolean();
				return b;
			} catch (java.util.InputMismatchException e) {
				System.out.println(errorMessage);
				in.next();
			}
		}

	}
}

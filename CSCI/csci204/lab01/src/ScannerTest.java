import java.util.Scanner;

/**
 * CSCI 204, Yifan Ge
 * Assiangment lab01
 * Created: &{date}, 10:22:41 AM
 */

/**
 * It is an exercise in lab 1 to practice using the scanner class.
 * 
 * @author Yifan Ge
 * 
 */
public class ScannerTest {

	/**
	 * Marks starting location of printing.
	 * 
	 * @param x
	 *            x coordinate
	 * @param y
	 *            y coordinate
	 */
	public static void printXY(int x, int y) {
		System.out.println("x = " + x + ", y = " + y);
	}

	/**
	 * Checks if the count is zero
	 * 
	 * @param count
	 *            the count
	 * @return whether the count is zero
	 */
	public boolean isZero(int count) {
		return count == 0;
	}

	/**
	 * Reviews Scanner Class.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println(" Enter an int, double , word , and line : ");
		int anInt = keyboard.nextInt();
		double aDouble = keyboard.nextDouble();
		String aWord = keyboard.next();
		String line = keyboard.nextLine();
		System.out.println(anInt + ":" + aDouble + ":" + aWord + ":" + line);

	}

}

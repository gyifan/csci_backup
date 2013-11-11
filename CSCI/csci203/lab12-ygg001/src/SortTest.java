import java.util.Scanner;

/**
 * CSCI 203, Yifan Ge
 * Nov 19, 2010, 7:15:03 PM
 */

/**
 * @author Yifan Ge
 * 
 */
public class SortTest {

	/**
	 * Sorts the array in to order.
	 * 
	 * @param array
	 *            the assigned array
	 */
	private static int[] sort(int[] array) {
		int temp;
		int startingNumber = 1;
		int timesOfChanges = startingNumber;
		while (timesOfChanges != 0) {
			timesOfChanges = 0;
			for (int i = 1; i < array.length - 1; i++) {
				if (array[i] < array[i - 1]) {
					temp = array[i];
					array[i] = array[i - 1];
					array[i - 1] = temp;
					timesOfChanges++;
				}
				if (array[i] > array[i + 1]) {
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					timesOfChanges++;
				}
			}
		}
		return array;
	}

	/**
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		System.out.print("Input numbers: ");
		Scanner keyboard = new Scanner(System.in);
		int[] array = new int[10];
		for (int i = 0; i < 10; i++) {
			array[i] = keyboard.nextInt();
		}
		System.out.print("Sorted output: ");
		array = sort(array);
		for (int i = 0; i < 10; i++) {
			System.out.print(array[i] + " ");
		}
	}

}

/**
 * Class for practice with arrays.
 * 
 * @author Dan Hyde
 * 
 */
public class UseArrays {

	/**
	 * Assigns to an array squaresArray the squares of the integers from 1 to n
	 * then prints on one line the array backwards separated by commas. Use a
	 * for loop to compute the squares, but use a while loop to print them out.
	 * Avoid printing a comma after the last element.
	 * 
	 * Pre-condition: n >= 1.
	 * 
	 * @param n
	 *            the number of elements
	 */
	public static void computed(int n) {
		System.out.print("computed: ");
		int[] squareArray = new int[n];
		for (int i = 0; i < n; i++)
			squareArray[i] = (i + 1) * (i + 1);
		int element = n - 1;
		while (element > 0) {
			System.out.print(squareArray[element] + ", ");
			element--;
		}
		System.out.println(squareArray[0]);
	}

	/**
	 * Runs computed; does not use its parameter args.
	 */
	public static void main(String[] args) {

		UseArrays.computed(3);
		System.out.println("Expected: 9, 4, 1");

		UseArrays.computed(10);
		System.out.println("Expected: 100, 81, 64, 49, 36, 25, 16, 9, 4, 1");

		UseArrays.computed(1);
		System.out.println("Expected: 1");
	}
}

import java.util.ArrayList;

/**
 * This class provides practice with using an ArrayList.
 * 
 * @author Rick Zaccone
 * 
 */
public class Words {
	/**
	 * Returns all short words (length <= 3) in an array list of words
	 * 
	 * @param words
	 *            an array of strings
	 * @return an array list containing the short words in words
	 */
	public ArrayList<String> shortWords(String[] words) {
		ArrayList<String> result = new ArrayList<String>();
		for (int i = 0; i < words.length; i++) {
			if (words[i].length() < 4)
				result.add(words[i]);
		}
		return result;
	}

	/**
	 * Tests the shortWords method.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Words tester = new Words();
		String[] test1 = { "Mary", "had", "a", "little", "lamb" };
		ArrayList<String> result = tester.shortWords(test1);
		tester.print(result);
		System.out.println("Expected: had a\n");

		String[] test2 = { "Its", "fleece", "was", "white", "as", "snow" };
		result = tester.shortWords(test2);
		tester.print(result);
		System.out.println("Expected: Its was as\n");
	}

	/**
	 * Prints an array list of strings on a single line.
	 * 
	 * @param result
	 *            the array list to print
	 */
	private void print(ArrayList<String> result) {
		System.out.print("Result:   ");
		for (String word : result)
			System.out.print(word + " ");
		System.out.println();
	}
}

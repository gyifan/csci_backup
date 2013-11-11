/**
 * This class provides a getMiddle method that extracts the middle of a word.
 * 
 * @author zaccone
 * 
 */
public class Words {
	/**
	 * Gets the middle character or character pair from this word when possible.
	 * 
	 * @param word
	 *            a word
	 * @return the middle character (if the word length is odd) or middle two
	 *         characters (if it is even), or the empty string if the word is
	 *         empty, or null if it is null.
	 */
	public String getMiddle(String word) {

		if (word == null)
			return "null";
		int halfLength = word.length() / 2;
		if (word.length() == 0)
			return "";
		else if (word.length() == 1 || word.length() == 2)
			return word;
		else if (word.length() == halfLength * 2)
			return word.substring(halfLength - 1, halfLength + 1);
		else
			return word.substring(halfLength, halfLength + 1);
	}

	/**
	 * Tests the getMiddle method.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Words wordTest = new Words();
		String s = null;
		System.out.println("Middle of null string: " + wordTest.getMiddle(s));
		System.out.println("Expected: null\n");

		s = "";
		System.out.println("Middle of \"" + s + "\": \""
				+ wordTest.getMiddle(s) + "\"");
		System.out.println("Expected: \"\"\n");

		s = "abcdefg";
		System.out.println("Middle of \"" + s + "\": \""
				+ wordTest.getMiddle(s) + "\"");
		System.out.println("Expected: \"d\"\n");

		s = "abcdefgh";
		System.out.println("Middle of \"" + s + "\": \""
				+ wordTest.getMiddle(s) + "\"");
		System.out.println("Expected: \"de\"\n");

		s = "a";
		System.out.println("Middle of \"" + s + "\": \""
				+ wordTest.getMiddle(s) + "\"");
		System.out.println("Expected: \"a\"\n");
	}
}

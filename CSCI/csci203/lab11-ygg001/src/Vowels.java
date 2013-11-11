/**
 * This class uses a loop to extract vowels from a string.
 * 
 * @author zaccone
 * 
 */
public class Vowels {
	/**
	 * Gets a string consisting of all vowels contained in a given string.
	 * Vowels are A E I O U a e i o u
	 * 
	 * @param s
	 *            the string from which vowels will be extracted
	 * @return a string with all vowels in s, in the order in which they appear
	 *         in s
	 */
	public String getVowels(String s) {
		String result = "";
		String sLowerCase = s.toLowerCase();
		for (int i = 0; i < s.length(); i++) {
			if (sLowerCase.charAt(i) == 'a' || sLowerCase.charAt(i) == 'e'
					|| sLowerCase.charAt(i) == 'i'
					|| sLowerCase.charAt(i) == 'o'
					|| sLowerCase.charAt(i) == 'u')
				result += s.charAt(i);
		}

		return result;
	}

	/**
	 * Tests the class.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Vowels vowels = new Vowels();

		String s = "now is the time";
		String expected = "oieie";
		String result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "metamorphosis";
		expected = "eaooi";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "xyz";
		expected = "";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "AEiOU";
		expected = "AEiOU";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "a";
		expected = "a";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "";
		expected = "";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);

		s = "abcdefghijklmno";
		expected = "aeio";
		result = vowels.getVowels(s);
		System.out.printf("%-28s %s\n", "Vowels in \"" + s + "\":", result);
		System.out.printf("Expected:                    %s\n\n", expected);
	}
}

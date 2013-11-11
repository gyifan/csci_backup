/**
 * Count the number of syllables in a word. Each group of adjacent vowels (a, e,
 * i, o, u, y) counts as one syllable (for example, the "ea" in "real"
 * contributes one syllable, but the "e..a" in "regal" count as two syllables.)
 * However, an "e" at the end of a word doesn't count as a syllable. Also, each
 * word has at least one syllable, even if the previous rules give a count of 0.
 * 
 * This code adopted from 'Big Java'
 * 
 * @author <a href="mailto:zaccone@bucknell.edu">Rick Zaccone</a>
 * @version 1.0
 */
public class Word {

	private String text;

	/**
	 * Creates a new <code>Word</code> instance. Constructs a word by removing
	 * leading and trailing nonletter characters, such as punctuation marks.
	 * 
	 * @param s
	 *            the input string
	 */
	public Word(String s) {
		int i = 0;
		while (i < s.length() && !Character.isLetter(s.charAt(i))) {
			i++;
		}
		int j = s.length() - 1;
		while (j > i && !Character.isLetter(s.charAt(j))) {
			j--;
		}
		text = s.substring(i, j + 1);
	}

	/**
	 * Returns the text of the word, after removal of the leading and trailing
	 * nonletter characters.
	 * 
	 * @return the text of the word.
	 */
	public String getText() {
		return text;
	}

	public int countSyllables() {
		int count = 0;
		int end = text.length() - 1;
		// the empty string has no syllables
		if (end < 0) {
			return 0;
		}
		// an e at the end of the word doesn't
		// count as a vowel.

		char ch = Character.toLowerCase(text.charAt(end));
		if (ch == 'e') {
			end--;
		}

		boolean insideVowelGroup = false;
		for (int i = 0; i <= end; i++) {
			ch = Character.toLowerCase(text.charAt(i));

			// if ch is a vowel

			if ("aeiouy".indexOf(ch) >= 0) {

				// Start of a new vowel group

				if (!insideVowelGroup) {
					count++;
					insideVowelGroup = true;
				}
			} else {
				insideVowelGroup = false;
			}

		}
		// Every word has at least one syllable
		if (count == 0) {
			count = 1;
		}

		return count;
	}
}

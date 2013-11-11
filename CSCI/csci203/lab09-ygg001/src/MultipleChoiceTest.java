/**
 * This class validates choices on a multiple choice test.
 * 
 * @author zaccone
 * 
 */
public class MultipleChoiceTest {
	private String maxChoice;

	/**
	 * Constructs a new test object.
	 * 
	 * @param maxChoice
	 *            the maximum legal choice
	 */
	public MultipleChoiceTest(String maxChoice) {
		this.maxChoice = maxChoice;
	}

	/**
	 * Determines if the user input on a multiple choice test is valid.
	 * 
	 * @param choice
	 *            the user choice
	 * @return true if the choice was valid. That is, it was between "A" and the
	 *         maximum choice. false otherwise.
	 */
	public boolean isValidChoice(String choice) {
		if (!(choice == null) && choice.length() == 1
				&& choice.compareToIgnoreCase("A") >= 0
				&& choice.compareToIgnoreCase(maxChoice) <= 0)
			return true;
		else
			return false;
	}

	/**
	 * Tests the isValidChoice method.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		MultipleChoiceTest test = new MultipleChoiceTest("D");
		String choice = "A";
		if (test.isValidChoice(choice))
			System.out.println(choice + ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: valid\n");

		choice = "AB";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = null;
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = "B";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: valid\n");

		choice = "C";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: valid\n");

		choice = "c";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: valid\n");

		choice = "d";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: valid\n");

		choice = "E";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = "xyz";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = "XYZ";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = "";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");

		choice = "1";
		if (test.isValidChoice(choice))
			System.out.printf("%8s%s\n", choice, ": valid");
		else
			System.out.printf("%8s%s\n", choice, ": not valid");
		System.out.println("Expected: not valid\n");
	}
}

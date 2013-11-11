import javax.swing.JOptionPane;

/**
 * Program to practice using do/while to validate input.
 * 
 * @author Dan Hyde
 * 
 */
public class ValidateInput {

	/**
	 * Asks in a JOptionPane dialog box "Continue?  Type yes or no" and allows
	 * the user to input a response. If the response is not "yes" or "no", force
	 * the user to repeat the input otherwise return the string.
	 * 
	 * @return response
	 */
	public String yesNo() {
		String response = "";
		do {
			response = JOptionPane.showInputDialog("Continue? Type yes or no");
		} while (!response.equals("yes") && !response.equals("no"));
		return response;

	}

	/**
	 * Tests the yesNo method.
	 * 
	 * @param args
	 *            not used
	 */
	public static void main(String[] args) {

		ValidateInput validator = new ValidateInput();
		String response = validator.yesNo();

		if (response.equals("yes") || response.equals("no")) {
			System.out.println("response: valid");
		} else {
			System.out.println("response: invalid");
		}

		System.out.println("Expected: valid");
		System.exit(0);
	}
}

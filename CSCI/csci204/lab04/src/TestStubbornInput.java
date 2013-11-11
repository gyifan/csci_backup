/**
 * A class for testing the lab-generated StubbornInput class.
 */
public class TestStubbornInput {

	/**
	 * Tests the StubbornInput class.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		StubbornInput in = new StubbornInput();
		int x = in.nextInt("Int please: ", "No really, I mean an int.");
		System.out.println(x);

		boolean b = in
				.nextBool("Bool please: ", "No really, I mean a boolean.");
		System.out.println(b);
	}
}
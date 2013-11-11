/**
 * CSCI 203, Yifan Ge
 * Oct 26, 2010, 10:30:53 AM
 */

/**
 * This class compares strings
 * 
 * @author Ge
 * 
 */
public class CompareStrings {

	/**
	 * Compares strings
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		System.out.println("apple".equals("book"));
		System.out.println("coma".equals("comma"));
		System.out.println("soup".equalsIgnoreCase("SoUp"));
		System.out.println("apple".compareTo("book"));
		System.out.println("comment".compareTo("comma"));
		System.out.println("Easy".compareTo("Easy"));
		System.out.println("easy".compareTo("Easy"));
		System.out.println("easy".compareToIgnoreCase("Easy"));
		System.out.println("Horse".compareTo("buggy"));
		System.out.println("needles".compareTo("needless"));
		System.out.println("then".compareTo("the"));
	}

}

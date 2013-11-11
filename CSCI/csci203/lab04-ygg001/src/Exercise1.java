/**
 * CSCI 203, Yifan Ge
 * Sep 21, 2010, 10:20:10 AM
 */

/**
 * @author ygg001
 * 
 */
public class Exercise1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s1 = "them";
		String s2 = "the";
		String s3 = s1 + s2;
		System.out.println("The length of s3 is " + s3.length());
		System.out.println("The fourth character of s3 is " + s3.charAt(3)
				+ ". The sixth character of s3 is " + s3.charAt(5) + ".");
		System.out
				.println("The results of checking if the second input string is part of the first input string is "
						+ s1.indexOf(s2));
		s1 = "bucknell";
		s2 = "university";
		s3 = s1 + s2;
		System.out.println("The length of s3 is " + s3.length());
		System.out.println("The fourth character of s3 is " + s3.charAt(3)
				+ ". The sixth character of s3 is " + s3.charAt(5) + ".");
		System.out
				.println("The results of checking if the second input string is part of the first input string is "
						+ s1.indexOf(s2));
	}

}

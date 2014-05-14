/**
 * An implementation of a hash function
 */

public class Hash {

	public static int hash(String inStr, int radix, int modulus ) {

		/*
		   Complete the implementation of the method hash(); be sure to
		   change the value returned!

		   Use (int)inStr.charAt(i) to convert the character at position i
		   to the integer value of its ASCII code.

		   NOTE that the indexing of the characters in a Java string is reversed
		   from what we used in lecture.
		   */
		int h = 0;
		int length = inStr.length();
		for (int i=0; i<length; i++){
			h = (h*radix + (int)inStr.charAt(i))%modulus;
		}
		return h; // To allow compilation


	}

}



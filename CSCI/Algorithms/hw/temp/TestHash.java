/**
 * A class to test hash function variations
 * Requires two integers to be provided on the command line
 */
import java.util.Scanner;
import java.io.*;

public class TestHash {

    public static void main(String[] args) {

	try {
	    int radix = Integer.parseInt(args[0]);
	    int modulus = Integer.parseInt(args[1]);
	    File inFile = new File(args[2]);
	    Scanner in = new Scanner(inFile);
	    String inStr;
	    
	    System.out.println();
	    System.out.println("Using radix " + radix + " and modulus "
			       + modulus
			       + ".");
	    System.out.println();
	    System.out.println("  Input  |  hash value");
	    System.out.println("----------------------");

	    while (in.hasNext()){
		inStr = in.next();
		System.out.printf("%7s  |%8d\n", inStr,
				  Hash.hash(inStr, radix, modulus));
	    }
	    
	    System.out.println("\n");
	    
	}
	catch (FileNotFoundException e) {
	    System.out.println("ERROR: File not found." + e);
	}
    }
}

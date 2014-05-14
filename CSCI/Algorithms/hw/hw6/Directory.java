// Directory.java
// CSCI 311

// phone directory program
// CHANGE THIS PROGRAM ONLY WHERE INDICATED IN THE SWITCH STATEMENT

import java.io.*;
import java.util.*;

// The overall running time is Sum of log(Ni) from i=0 to the length of the command.
// where Ni is the current number of nodes at the time when the command was executed.
// So in general, the running time is O(nlog(n))
public class Directory {

    public static void main(String[] args) {
	
	BST<String> directory = new BST<String>();
	char code;
	String name, temp;
	Scanner in;

	if (args.length != 1) {
	    System.err.println("Usage:  java Directory fileName");
	    System.exit(1);
	}

	try {
	    in = new Scanner(new BufferedReader(new FileReader(args[0])));
	    while (in.hasNext()) {
		temp = in.next();
		if (temp.length() > 1) {
		    System.err.println("ERROR IN INPUT.  TERMINATING");
		    System.exit(1);
		}
		code = temp.charAt(0);
		name = in.next();

		switch (code) {
		case 'A': case 'a': {
		    directory.Insert(name);
		    break;
		}
		case 'R': case 'r': {

		    // ADD CODE FOR REMOVAL CASE HERE
			directory.Remove(name);
		    
		    break;
		}
		default:
		    System.err.println("Invalid code: " + code);
		}
		System.out.println("======== " + code + " " + name + " ========");
		directory.Print();
		System.out.println();
		System.out.println();
	    }
	}
	catch (FileNotFoundException e) {
	    System.err.println("Directory: Error opening file.");
	    System.exit(1);
	}
	
	System.out.println("\n\nDirectory\n---------");
	directory.Print();
	System.out.println();
	
    }
    
}


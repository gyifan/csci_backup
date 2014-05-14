/**
 * A class to test quicksort variations
 */

import java.util.Random;

public class TestQuicksort {

    public static void main(String[] args) {
    //int arrsize = 16;
	int arrsize = 10000000*2;
	int[] A = new int[arrsize];
	Random rand = new Random();

	for (int i = 0; i < arrsize; i++) {
	    A[i] = rand.nextInt(3*arrsize);

	    // Comment out the preceding line and uncomment the following
	    // to test a bad input (warning: will cause stack overflow
	    // if used with basic quicksort algorithm):

	    // A[i] = i;
	}

	Quicksort.QSort(A, 0, arrsize-1);
	
	boolean inOrder = true; // Flag for testing result
	System.out.println("Testing array order");
	for (int i = 0; i < arrsize-1; i= i+1000) {
	    if (A[i] > A[i+1])
		inOrder = false;
	}
	if (!inOrder)
	    System.out.println("ERROR: array not sorted.\n");
	else
	    System.out.println("Array sorted correctly.\n");

	System.out.println("\n");

    }
}



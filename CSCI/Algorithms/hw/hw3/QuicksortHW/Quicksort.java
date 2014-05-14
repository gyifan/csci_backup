/**
 * An implementation of quicksort as static functions
 */

import java.util.Random;

public class Quicksort {

    public static void QSort(int[] A, int p, int r) {
	System.out.println("Sorting with QS");

	Random rand = new Random(); // For Random Quicksort - pass as argument

	// The following line determines which recursive method is used:
	// QS(A, p, r); 

	// Add code for calling your improvements below; remember to comment
	// out calls you are not using.
   
	// RandomQS(A, p, r, rand);
	// MedOf3QS(A, p, r);
	// SmallFilesQS(A, p, r);
	SmallFilesPlusMed3QS(A, p, r);
	
	
	// For the "small subfiles" exercise, add the needed
	// final top-level code here:
	
	InsertionSort(A, r-p+1);


    }
    
    // Plain vanilla quicksort:
    public static void QS(int[] A, int p, int r) {
	
	if (p < r) {
	    int q = Partition(A, p, r);
	    QS(A, p, q-1);
	    QS(A, q+1, r);
	}
    }

    // Randomized quicksort (see the text - this is easy with
    // the correct RandomPartition method):
    public static void RandomQS(int[] A, int p, int r, Random rand) {
        if (p < r) {
            int q = RandomPartition(A, p, r, rand);
            RandomQS(A, p, q-1, rand);
            RandomQS(A, q+1, r, rand);
        }	
    }

    // Median-of-3 quicksort:
    public static void MedOf3QS(int[] A, int p, int r) {
    	// System.out.printf("%d, %d\n", p, r);
    	if (p < r) {
    		int q = MedOf3Partition(A, p, r);
    		MedOf3QS(A, p, q-1);
    		MedOf3QS(A, q+1, r);
    	}
    }
	
    // Quicksort with the "small subfiles" modification (this is easy if you
    // think about the base case for the recursion):
    public static void SmallFilesQS(int[] A, int p, int r) {
    	if (r-p > 25){
    		int q = Partition(A, p, r);
    		SmallFilesQS(A, p, q-1);
    		SmallFilesQS(A, q+1, r);
    	}
    }

    // Quicksort with the "small subfiles" modification plus the median-of-3
    // modification:
    public static void SmallFilesPlusMed3QS(int[] A, int p, int r) {
    	if (r-p > 25){
    		int q = MedOf3Partition(A, p, r);
    		SmallFilesPlusMed3QS(A, p, q-1);
    		SmallFilesPlusMed3QS(A, q+1, r);
    	}
    }

    // Plain vanilla partitioning
    public static int Partition(int[] A, int p, int r) {

		int pivot = A[r];
		int i = p-1;
		int temp;
		// Partition the array
		for (int j = p; j < r; j++) {
		    if (A[j] <= pivot) {
				i = i + 1;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
		    }
		}
		// Swap the pivot element into its proper position
		temp = A[i+1];
		A[i+1] = A[r];
		A[r] = temp;
		
		return i+1;
    }

	// Randomized partitioning (see the text for an easy way to do):
	public static int RandomPartition(int[] A, int p, int r, Random rand) {
	
		int index = rand.nextInt(r-p+1)+p;
		Swap(A, index, r);
		int pivot = A[r];
		int i = p-1;
		// Partition the array
		for (int j = p; j < r; j++) {
			if (A[j] <= pivot) {
				i = i + 1;
				Swap(A, i, j);
			}
		}
	 // Swap the pivot element into its proper position
		Swap(A, i+1, r);	
		return i+1;
	
	}

    public static void Swap(int[] A, int i, int j){
        int temp;
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
    }

    public static int FoundMedOf3(int[] A, int p, int r){
    	
    	int m = (p+r)/2; // Get the middle index
    	
    	int index = m;
    	if(A[m]>A[p]){
    		if(A[r]>A[m])
    			index = m;
    		else if(A[p]>A[r])
    			index = p;
    		else 
    			index = r;
    	}else{ 
    		if(A[r]>A[p])
    			index = p;
    		else if(A[r]>A[m])
    			index = r;
    		else
    			index = m;
    	}
    	// System.out.printf("%d, %d, %d, median = %d\n", A[p],A[m],A[r],A[index]);
    	return index;
    }

    // Median-of-three partitioning
    public static int MedOf3Partition(int[] A, int p, int r) {
    	
    	int index = FoundMedOf3(A, p, r);
    	if(index != r)
    		Swap(A, r, index);
    	int pivot = A[r];
		int i = p-1;
		 // Partition the array
		for (int j = p; j < r; j++) {
			if (A[j] <= pivot) {
				i = i + 1;
				Swap(A, i, j);
			}
		}
		 // Swap the pivot element into its proper position
		Swap(A, i+1, r);	
		return i+1;

    }
    
    // Insertion Sort
    public static void InsertionSort(int[] A, int size){
    	// printArray(A, r-p+1);
    	int key = A[0];
    	int i, j;
    	for(j = 1; j < size; j++){
    		key = A[j];
    		i = j-1;
    		while((i >= 0) && (A[i] > key) ){
    			A[i+1] = A[i];
				i = i -1;
    		}
    		A[i+1] = key;
    	}
    	// printArray(A, r-p+1);
    }
    
    // print array
    public static void printArray(int[] A, int size){
    	for(int i = 0; i < size; i ++){
    		System.out.printf("%d ", A[i]);
    	}
    	System.out.println();
    }
}
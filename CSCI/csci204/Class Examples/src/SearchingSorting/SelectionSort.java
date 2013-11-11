/**
 * 
 */
package SearchingSorting;

import java.util.Arrays;

/**
 * The Selection sort algorithm from Big Java 4
 * 
 * @author lwittie
 * 
 */
public class SelectionSort {
	private int[] a;

	public SelectionSort(int[] anArray) {
		a = anArray;
	}

	// sort the array
	public void sort(boolean verbose) {
		for (int i = 0; i < a.length; i++) {
			int minPos = minimumPosition(i);
			swap(minPos, i);
			if (verbose)
				System.out.println(Arrays.toString(a));
		}
	}

	// Find the position of the smallest content from 'from' to the end
	private int minimumPosition(int from) {
		int minPos = from;
		for (int i = from + 1; i < a.length; i++)
			if (a[i] < a[minPos])
				minPos = i;
		return minPos;
	}

	// Swap the contents at positions i and k
	private void swap(int i, int k) {
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}

	public static void main(String[] args) {
		int[] a = ArrayUtil.randomIntArray(5, 100);
		System.out.println(Arrays.toString(a));
		SelectionSort sorter = new SelectionSort(a);
		sorter.sort(true);
		System.out.println(Arrays.toString(a));

	}
}

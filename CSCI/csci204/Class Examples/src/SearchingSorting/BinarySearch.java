/**
 * 
 */
package SearchingSorting;

import java.util.Arrays;

public class BinarySearch {
	private int[] a;

	public BinarySearch(int[] anArray) {
		a = anArray;
	}

	public void search(int value) {
		int where = binarySearch(0, a.length - 1, value);
		if (where == -1)
			System.out.println(value + " was not found");
		else
			System.out.println(value + " was found in position " + where);
	}

	// search the array
	public int binarySearch(int first, int last, int value) {
		int mid = (first + last) / 2;

		// base case #1: value not present
		if (first > last)
			return -1;

		// base case #2: value is the mid point
		else if (value == a[mid])
			return mid;

		// recursive #1: search the left half
		else if (value < a[mid])
			return binarySearch(first, mid - 1, value);

		// recursive #2: search the right half
		else
			return binarySearch(mid + 1, last, value);
	}

	public static void main(String[] args) {
		int[] a = ArrayUtil.randomIntArray(20, 30);
		SelectionSort sorter = new SelectionSort(a);
		sorter.sort(false);
		System.out.println(Arrays.toString(a));
		BinarySearch searcher = new BinarySearch(a);
		searcher.search(0);
		searcher.search(2);
		searcher.search(9);
		searcher.search(12);
		searcher.search(20);
	}
}
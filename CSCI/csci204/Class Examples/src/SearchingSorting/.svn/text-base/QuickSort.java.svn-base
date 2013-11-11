package SearchingSorting;

import java.util.Arrays;

public class QuickSort {
	private int[] a;

	public QuickSort(int[] anArray) {
		a = anArray;
	}

	public void sort(boolean verbose) {
		quicksort(verbose, 0, a.length - 1);
	}

	/**
	 * Sorts an input array of integers using the quicksort algorithm. Pre: the
	 * array 'a' contains the collection of integers to be sorted, 'first' and
	 * 'last' contains the bounds of the section. Post: the array 'a' has been
	 * sorted
	 * 
	 * @param first
	 *            index of the start of the region to be sorted
	 * @param last
	 *            index of the end of the region to be sorted
	 */
	public void quicksort(boolean verbose, int first, int last) {
		if (first >= last)
			return;
		if (verbose)
			System.out.print("Pivot is " + a[first] + " ");
		int split = partition(first, last);
		if (verbose)
			System.out.println(Arrays.toString(Arrays.copyOfRange(a, first,
					last + 1)));
		quicksort(verbose, first, split - 1);
		quicksort(verbose, split + 1, last);
	}

	/**
	 * Partitions a region of the array around a pivot element. The pivot is
	 * chosen to be the first element in the array. Everything in the first
	 * partition is <= the pivot element. Everything in the second partition is
	 * greater than the pivot. The pivot element gets moved to its final
	 * destination in the sorted array.
	 * 
	 * @param first
	 *            index of the start of the region to be partitioned
	 * @param last
	 *            index of the end of the region to be partitioned
	 * @return the index of the partition (pivot) element
	 */
	private int partition(int first, int last) {
		int lastSmall = first;
		for (int i = first + 1; i <= last; i++) {
			if (a[i] <= a[first]) {
				lastSmall++;
				swap(lastSmall, i);
			}
		}
		swap(first, lastSmall);
		return lastSmall;
	}

	/**
	 * Swaps two elements in an array.
	 * 
	 * @param first
	 *            the index of the first element to be swapped.
	 * @param second
	 *            the index of the second element to be swapped.
	 */
	private void swap(int first, int second) {
		int temp = a[first];
		a[first] = a[second];
		a[second] = temp;
	}

	/**
	 * Returns a random integer between min and max inclusive.
	 * 
	 * @param min
	 *            the minimum value for the next random number.
	 * @param max
	 *            the maximum value for the next random number.
	 * @return a random number in the specified range.
	 */
	private static int randInt(int min, int max) {
		return (int) ((Math.random() * (max - min + 1))) + min;
	}

	/**
	 * Tests the quicksort algorithm by generating <tt>n</tt> random integers
	 * then sorting them. n ranges over the powers of 2 from 2<sup>3</sup> to
	 * 2<sup>14</sup>.
	 * 
	 * @param argv
	 *            command line arguments (not used)
	 */
	public static void main(String[] argv) {
		int[] a = ArrayUtil.randomIntArray(10, 100);
		System.out.println(Arrays.toString(a));
		QuickSort sorter = new QuickSort(a);
		sorter.sort(true);
		System.out.println(Arrays.toString(a));

	}
}

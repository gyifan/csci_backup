public class Quicksort {

	private static int keyComparison;

	/**
	 * Sorts an input array of integers using the quicksort algorithm. Pre: the
	 * array 'a' contains the collection of integers to be sorted, 'first' and
	 * 'last' contains the bounds of the section. Post: the array 'a' has been
	 * sorted
	 * 
	 * @param a
	 *            [] the array to be sorted
	 * @param first
	 *            index of the start of the region to be sorted
	 * @param last
	 *            index of the end of the region to be sorted
	 */
	public static void quicksort(int[] a, int first, int last) {
		if (first >= last)
			return;
		int split = partition(a, first, last);
		quicksort(a, first, split - 1);
		quicksort(a, split + 1, last);
	}

	/**
	 * Sorts an input array of integers using the quicksort algorithm with
	 * Median-of-Three pivot selecting method.
	 * 
	 * @param a
	 *            the array to be sorted
	 * @param first
	 *            index of the start of the region to be sorted
	 * @param last
	 *            index of the end of the region to be sorted
	 */
	public static void quicksortm(int[] a, int first, int last) {
		if (first >= last)
			return;
		int split = partitionm(a, first, last);
		quicksortm(a, first, split - 1);
		quicksortm(a, split + 1, last);
	}

	/**
	 * Partitions a region of the array around a pivot element. The pivot is
	 * chosen to be the first element in the array. Everything in the first
	 * partition is <= the pivot element. Everything in the second partition is
	 * greater than the pivot. The pivot element gets moved to its final
	 * destination in the sorted array.
	 * 
	 * @param a
	 *            [] the array to be partitioned
	 * @param first
	 *            index of the start of the region to be partitioned
	 * @param last
	 *            index of the end of the region to be partitioned
	 * @return the index of the partition (pivot) element
	 */
	private static int partition(int[] a, int first, int last) {
		int lastSmall = first;
		for (int i = first + 1; i <= last; i++) {
			keyComparison++;
			if (a[i] <= a[first]) {
				lastSmall++;
				swapElements(a, lastSmall, i);
			}
		}
		swapElements(a, first, lastSmall);
		return lastSmall;
	}

	/**
	 * Partitions a region of the array around a pivot element with
	 * Median-of-Three pivot selecting method.
	 * 
	 * @param a
	 *            [] the array to be partitioned
	 * @param first
	 *            index of the start of the region to be partitioned
	 * @param last
	 *            index of the end of the region to be partitioned
	 * @return the index of the partition (pivot) element
	 */
	private static int partitionm(int[] a, int first, int last) {
		int midPoint = (last + first) / 2;
		if (a[first] > a[last]) {
			swapElements(a, first, last);
		}
		if (a[midPoint] > a[last]) {
			swapElements(a, midPoint, last);
		}
		if (a[midPoint] > a[0]) {
			swapElements(a, first, midPoint);
		}
		keyComparison += 3;
		int lastSmall = first;
		for (int i = first + 1; i <= last; i++) {
			keyComparison++;
			if (a[i] <= a[first]) {
				lastSmall++;
				swapElements(a, lastSmall, i);
			}
		}
		swapElements(a, first, lastSmall);
		return lastSmall;
	}

	/**
	 * Swaps two elements in an array.
	 * 
	 * @param a
	 *            [] the array whose two elements will be swapped.
	 * @param first
	 *            the index of the first element to be swapped.
	 * @param second
	 *            the index of the second element to be swapped.
	 */
	private static void swapElements(int[] a, int first, int second) {
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
		int[] arrays;
		for (int i = 8; i <= 16384; i *= 2) {
			arrays = new int[i];
			for (int j = 0; j < i; j++) {
				// arrays[j] = j;
				arrays[j] = randInt(0, 20000);
			}
			keyComparison = 0;
			quicksortm(arrays, 0, i - 1);
			System.out.println(i + "   " + keyComparison);
		}

	}
}

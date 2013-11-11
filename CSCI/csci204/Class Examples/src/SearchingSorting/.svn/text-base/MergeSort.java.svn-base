package SearchingSorting;

import java.util.Arrays;

public class MergeSort {
	private int[] a;

	public MergeSort(int[] anArray) {
		a = anArray;
	}

	// sort the array
	public void sort() {
		if (a.length <= 1)
			return;

		// Split the array in half
		int[] left = new int[a.length / 2];
		int[] right = new int[a.length - left.length];
		for (int i = 0; i < left.length; i++)
			left[i] = a[i];
		for (int i = 0; i < right.length; i++)
			right[i] = a[left.length + i];

		// recursively sort the two parts
		MergeSort leftSorter = new MergeSort(left);
		MergeSort rightSorter = new MergeSort(right);
		leftSorter.sort();
		rightSorter.sort();

		// merge them back together
		merge(left, right);
	}

	// merge two arrays
	private void merge(int[] left, int[] right) {
		int iLeft = 0;
		int iRight = 0;
		int open = 0;

		// pick out numbers till one side is finished
		while (iLeft < left.length && iRight < right.length) {
			if (left[iLeft] < right[iRight]) {
				a[open] = left[iLeft];
				iLeft++;
			} else {
				a[open] = right[iRight];
				iRight++;
			}
			open++;
		}

		// copy the remaining side into a (one is already empty)
		while (iLeft < left.length) {
			a[open] = left[iLeft];
			iLeft++;
			open++;
		}
		while (iRight < right.length) {
			a[open] = right[iRight];
			iRight++;
			open++;
		}
	}

	public static void main(String[] args) {
		int[] a = ArrayUtil.randomIntArray(10, 100);
		System.out.println(Arrays.toString(a));
		MergeSort sorter = new MergeSort(a);
		sorter.sort();
		System.out.println(Arrays.toString(a));
	}
}

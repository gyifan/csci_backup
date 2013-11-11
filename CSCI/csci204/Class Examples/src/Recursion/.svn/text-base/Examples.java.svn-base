package Recursion;

public class Examples {
	// A recursive method
	static void methodOne(int counter) {

		if (counter == 0) // base case
			return;
		else { // recursive case
			System.out.println("Hello" + counter);
			methodOne(counter - 1);
			return;
		}
	}

	// Another recursive method with work before and after the recursive call
	static void methodTwo(int counter) {
		if (counter == 0) // base case
			return;
		else { // recursive case
			System.out.println("Hello" + counter);
			methodTwo(counter - 1);
			System.out.println("Bye" + counter);
			return;
		}
	}

	// iterative factorial
	static int factIter(int n) {
		int tmp = 1;
		for (int k = 1; k <= n; k++)
			tmp = tmp * k;
		return tmp;
	}

	// recursive factorial
	static int fact(int n) {
		if (n == 0) // base case
			return 1;
		else
			// recursive case
			return n * fact(n - 1);
	}

	// Print the given string backwards recursively
	static String writeBackwards(String aString) {
		if (aString.length() <= 1) {
			return aString;
		} else {
			return aString.charAt(aString.length() - 1)
					+ writeBackwards(aString.substring(1, aString.length() - 1))
					+ aString.charAt(0);
		}

	}

	// recursive fibonacci (multiple cases)
	static int fib(int n) {
		if (n == 0) // base case
			return n;
		if (n == 1) // base case
			return n;
		// recursive case
		return fib(n - 1) + fib(n - 2);
	}

	// iterative fibonacci (difficult to write)
	static int fibIter(int n) {
		int last = 0;
		int curr = 1;

		for (int i = 2; i <= n; i++) {
			int penultimate = last;
			last = curr;
			curr = penultimate + last;
		}
		return curr;
	}

	// recursive binary search (difficult to do iteratively)
	static int binarySearch(int[] list, int first, int last, int value) {
		int mid = (first + last) / 2;
		System.out.println("first=" + first + " last=" + last + " mid=" + mid);

		// base case #1: value not present
		if (first > last)
			return -1;

		// base case #2: value is the mid point
		else if (value == list[mid])
			return mid;

		// recursive #1: search the left half
		else if (value < list[mid])
			return binarySearch(list, first, mid - 1, value);

		// recursive #2: search the right half
		else
			return binarySearch(list, mid + 1, last, value);
	}

	// recursive linear search
	static int linearSearch(int[] list, int first, int last, int value) {
		if (first > last)
			return -1;
		if (list[first] == value)
			return first;
		else {
			return linearSearch(list, first + 1, last, value);
		}
	}

	public static void main(String[] args) {
		// methodOne
		// methodOne(3);
		// System.out.println("-----------");
		// methodOne(2);
		// System.out.println("-----------");
		// methodOne(1);
		// System.out.println("-----------");
		// methodOne(0);
		// System.out.println("-----------");

		// Hit Cntrl-/ to comment and uncomment a selected region

		// // methodTwo methodTwo(3); System.out.println("-----------");
		// methodTwo(2);
		// System.out.println("-----------");
		// methodTwo(1);
		// System.out.println("-----------");
		// methodTwo(0);
		// System.out.println("-----------");

		// factIter
		// System.out.println(factIter(1000));
		// fact
		// System.out.println(fact(1000));
		//
		/*
		 * System.out.println(writeBackwards(""));
		 * System.out.println(writeBackwards("h"));
		 * System.out.println(writeBackwards("he"));
		 * System.out.println(writeBackwards("hello"));
		 * System.out.println(writeBackwards("hellos"));
		 */
		//
		// // fib System.out.println(fib(5)); // fibIter
		// System.out.println(fibIter(5));
		//
		// // For searches
		int[] list = { 2, 8, 10, 13, 15, 22, 31 };
		int where;
		//
		// // recursive binary search
		where = binarySearch(list, 0, list.length - 1, 10);
		if (where == -1)
			System.out.println("Not found");
		else
			System.out.println("Found in position " + where);

		System.out.println("-----------");
		where = binarySearch(list, 0, list.length - 1, 21);
		if (where == -1)
			System.out.println("Not found");
		else
			System.out.println("Found in position " + where);
		//
		// // recursive linear search
		// where = linearSearch(list, 0, list.length - 1, 10);
		// if (where == -1)
		// System.out.println("Not found");
		// else
		// System.out.println("Found in position " + where);
		// System.out.println("-----------");
		// where = linearSearch(list, 0, list.length - 1, 21);
		// if (where == -1)
		// System.out.println("Not found");
		// else
		// System.out.println("Found in position " + where);

	}
}

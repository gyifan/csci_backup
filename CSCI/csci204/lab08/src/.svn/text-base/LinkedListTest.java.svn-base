import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Iterator;
import java.util.Random;

import org.junit.Test;

public class LinkedListTest {
	LinkedList<Integer> theList;
	java.util.ArrayList<Integer> theArray;

	/**
	 * This helper method will create a new Linked List and an identical array
	 * of integers for comparison purposes
	 * 
	 * @param count
	 * @param bDoRandom
	 */
	private void fillList(int count, boolean bDoRandom) {
		theList = new LinkedList<Integer>();
		theArray = new java.util.ArrayList<Integer>();
		Random rand = new Random();
		for (int i = 0; i < count; i++) {
			int num;
			if (bDoRandom)
				num = rand.nextInt();
			else
				num = i + 1;
			theList.addLast(num);
			theArray.add(num);
		}
	}

	@Test
	public final void testAddLast() {
		final int SIZE = 10;
		fillList(SIZE, false);
		assertArrayEquals(theArray.toArray(), theList.toArray());
	}

	@Test
	public final void testAddFirst() {
		final int SIZE = 10;
		fillList(SIZE, false);
		Random rand = new Random();
		int num = rand.nextInt();
		theList.addFirst(num);
		theArray.add(0, num);
		assertArrayEquals(theArray.toArray(), theList.toArray());
	}

	@Test
	public final void testSize() {
		// Test on an empty list
		theList = new LinkedList<Integer>();
		assertTrue(theList.size() == 0);

		// Test on a filled list
		final int SIZE = 1000;
		fillList(SIZE, false);
		assertTrue(theList.size() == SIZE);
	}

	@Test
	public final void testClear() {
		final int SIZE = 10;
		fillList(SIZE, false);
		theList.clear();
		assertTrue(theList.size() == 0);
	}

	@Test
	public final void testGet() {
		theList = new LinkedList<Integer>();

		try {
			theList.get(0);
			assertTrue(
					"get() on empty list did not generate ArrayIndexOutOfBounds",
					false);
		} catch (ArrayIndexOutOfBoundsException e) {
		}

		final int SIZE = 10;
		fillList(SIZE, false);
		for (int i = 0; i < SIZE; i++)
			assertEquals(theList.get(i), theArray.get(i));
		try {
			theList.get(-1);
			assertTrue(
					"get(-1) did not generate ArrayIndexOutOfBoundsException",
					false);
		} catch (ArrayIndexOutOfBoundsException e) {
		}
		try {
			theList.get(SIZE);
			assertTrue(
					"get(SIZE) did not generate ArrayIndexOutOfBoundsException",
					false);
		} catch (ArrayIndexOutOfBoundsException e) {
		}
	}

	@Test
	public final void testInsert() {
		// Test inserting on empty list
		theList = new LinkedList<Integer>();
		theList.insert(0, 100);
		assertEquals(theList.size(), 1);
		assertEquals(theList.get(0), new Integer(100));

		// Test inserting in the beginning of an existing list
		int SIZE = 10;
		fillList(SIZE, false);
		theList.insert(0, 1000);
		theArray.add(0, 1000);
		assertArrayEquals(theArray.toArray(), theList.toArray());

		// Test inserting in the middle of an existing list
		theList.insert(theList.size() / 2, 50);
		theArray.add(theArray.size() / 2, 50);
		assertArrayEquals(theArray.toArray(), theList.toArray());

		// Test using insert to add something to the end of the list
		theList.insert(theList.size(), 77);
		theArray.add(theArray.size(), 77);
		assertArrayEquals(theArray.toArray(), theList.toArray());

		// Test to make sure excceptions are thrown if we try to add elsewhere
		try {
			theList.insert(theList.size() + 1, -1);
			assertFalse("insert did not generate exception", true);
		} catch (ArrayIndexOutOfBoundsException e) {
		}
	}

	@Test
	public final void testRemove() {
		fillList(1000, true);
		// Remove at the beginning
		assertEquals(theList.remove(0), theArray.remove(0));
		assertArrayEquals(theList.toArray(), theArray.toArray());

		// Remove in the middle
		assertEquals(theList.remove(theList.size() / 2), theArray
				.remove(theArray.size() / 2));
		assertArrayEquals(theList.toArray(), theArray.toArray());

		// Remove an element at the end of the list
		assertEquals(theList.remove(theList.size() - 1), theArray
				.remove(theArray.size() - 1));
		assertArrayEquals(theList.toArray(), theArray.toArray());

		// Test to make sure exceptions are thrown at appropriate indices
		try {
			theList.remove(-1);
			assertFalse("remove did not generate exception at -1", true);
		} catch (ArrayIndexOutOfBoundsException e) {
		}

		try {
			theList.remove(theList.size());
			assertFalse("remove did not generate excepton at size()", true);
		} catch (ArrayIndexOutOfBoundsException e) {
		}

	}

	@Test
	public final void testIterator() {
		final int SIZE = 10000;
		fillList(SIZE, true);

		// Get the iterator
		Iterator<Integer> iterList = theList.iterator();
		Iterator<Integer> iterArray = theArray.iterator();

		for (int i = 0; i < SIZE; i++) {
			assertTrue(iterList.hasNext());
			assertTrue(iterArray.hasNext());
			assertEquals(iterList.next(), iterArray.next());
		}
		assertFalse(iterList.hasNext());
		assertFalse(iterArray.hasNext());
	}

	@Test
	public final void testFindFirst() {
		final int SIZE = 10000;
		final int TEST_VALUE = 1000000;

		// Fill the list with a sequence of numbers from 1...SIZE
		fillList(SIZE, false);

		// Insert the number at a couple different places
		theList.insert(SIZE / 2, TEST_VALUE);
		theList.insert(SIZE / 3, TEST_VALUE);

		// Make sure it returns the first occurrence
		assertTrue(theList.findFirst(1000000) == SIZE / 3);

		// Search for a number that we know doesn't exist. Make sure it returns
		// -1
		assertTrue(theList.findFirst(TEST_VALUE + 1) == -1);
	}

	@Test
	public final void testFindLast() {
		final int SIZE = 10000;
		final int TEST_VALUE = 1000000;

		fillList(SIZE, false);

		theList.insert(SIZE / 3, TEST_VALUE);
		theList.insert(SIZE / 2, TEST_VALUE);

		assertTrue(theList.findLast(TEST_VALUE) == SIZE / 2);
		assertTrue(theList.findLast(TEST_VALUE + 1) == -1);

	}

}

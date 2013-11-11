package Lists;

import java.util.Random;

public class LinkedListTest {
	LinkedList theList;
	java.util.ArrayList<Integer> theArray;

	/**
	 * This helper method will create a new Linked List and an identical array
	 * of integers for comparison purposes
	 * 
	 * @param count
	 * @param bDoRandom
	 */
	private void fillList(int count, boolean bDoRandom) {
		theList = new LinkedList();
		theArray = new java.util.ArrayList<Integer>();
		Random rand = new Random();
		for (int i = 0; i < count; i++) {
			int num;
			if (bDoRandom)
				num = rand.nextInt();
			else
				num = i + 1;
			theList.insertLast(num);
			theArray.add(num);
		}
	}

	@Test
	public final void testAdd() {
		final int SIZE = 10;
		fillList(SIZE, false);
		assertArrayEquals(theArray.toArray(), theList.toArray());
	}

	@Test
	public final void testSize() {
		// Test on an empty list
		theList = new LinkedList();
		assertTrue(theList.size() == 0);

		// Test on a filled list
		final int SIZE = 1000;
		fillList(SIZE, false);
		assertTrue(theList.size() == SIZE);
	}

	@Test
	public final void testGet() {
		theList = new LinkedList();

		try {
			theList.get(0);
			assertTrue(
					"get() on empty list did not generateArrayIndexOutOfBounds",
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
		theList = new LinkedList();
		theList.insert(0, 100);
		assertEquals(theList.size(), 1);
		assertEquals(theList.get(0), 100);

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

		// Test to make sure exceptions are thrown if we try to add elsewhere
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
}

/**
 * A complete JUnit test to test the QueueArray<T> implemetation
 * 
 * CSCI 204 - Fall 2010
 * 
 * @author Brian R. King
 */

import static org.junit.Assert.*;

import java.util.LinkedList;
import java.util.Random;

import org.junit.Test;

public class QueueArrayTest {
    LinkedList<Integer> javaQueue;
    QueueArray<Integer> myQueue;
    
    private final static int QUEUE_SIZE = 100;
    
	/**
	 * Fill the test queues with sample data
	 */
	private void initQueues(int initCapacity, int n, boolean bDoRandom) {
		javaQueue = new LinkedList<Integer>();
		myQueue = new QueueArray<Integer>(initCapacity);
		Random rand = new Random(System.nanoTime());
		try {
			for(int i = 0; i < n; i++) {
				int num;
				if (bDoRandom)
					num = rand.nextInt();
				else
					num = i+1;

				javaQueue.addLast(num);
				myQueue.enqueue(num);
			}
		} catch (QueueArray.QueueException e) {
			fail("initQueues(): QueueException thrown, but shouldn't have been!");
		}
	}


	/**
	 * Test the default constructor
	 */
	@Test
	public final void testQueueArray() {
		myQueue = new QueueArray<Integer>();
		
		// Make sure that there are no items in the queue, and that 
		// there is obvious space left in the queue
		assertEquals(0,myQueue.size());
		assertTrue(myQueue.getSpaceLeft() > 0);
	}

	@Test
	public final void testQueueArrayInt() throws QueueArray.QueueException {
		myQueue = new QueueArray<Integer>(QUEUE_SIZE);
		assertEquals(QUEUE_SIZE,myQueue.getSpaceLeft());		
	}

	@Test
	public final void testSize() {
		initQueues(QUEUE_SIZE,(int)(QUEUE_SIZE/2),true);
		assertEquals((int)(QUEUE_SIZE/2),myQueue.size());
	}

	@Test
	public final void testGetSpaceLeft() {
		initQueues(QUEUE_SIZE,(int)(QUEUE_SIZE/2),true);
		assertEquals(QUEUE_SIZE-(int)(QUEUE_SIZE/2),myQueue.getSpaceLeft());
	}

	@Test
	public final void testIsEmpty() {
		final int QUEUE_SIZE = 500;
		myQueue = new QueueArray<Integer>(QUEUE_SIZE);
		try {
			assertTrue(myQueue.isEmpty());
			for(int i = 1; i <= QUEUE_SIZE; i++) {
				myQueue.enqueue(i);
				assertFalse(myQueue.isEmpty());
			}			
		}
		catch (QueueArray.QueueException e) {
			fail("testIsEmpty() - should NOT have generated exception!");
		}
	}

	@Test
	public final void testIsFull() {
		final int QUEUE_SIZE = 500;
		myQueue = new QueueArray<Integer>(QUEUE_SIZE);
		try {
			assertFalse(myQueue.isFull());
			for(int i = 1; i < QUEUE_SIZE; i++) {
				myQueue.enqueue(i);
				assertFalse(myQueue.isFull());
			}
			//Add one more to fill the last slot
			myQueue.enqueue(0);
			assertTrue(myQueue.isFull());
		}
		catch (QueueArray.QueueException e) {
			fail("testIsFull() - should NOT have generated exception!");
		}
	}

	@Test
	public final void testGetCopyOfArray() {
		// Generate a full queue
		initQueues(QUEUE_SIZE,QUEUE_SIZE,true);
		
		// Get the array from both, and test it out
		assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
		try {
			javaQueue.removeFirst();
			myQueue.dequeue();
			assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
		}
		catch (QueueArray.QueueException e) {
			fail("testGetCopyOfArray() - QueueException should NOT have been thrown");
		}
	}
	
	@Test
	public final void testEnqueue() {
		initQueues(QUEUE_SIZE,QUEUE_SIZE,true);
		// Get the array version
		assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
		assertTrue(myQueue.isFull());
		assertTrue(myQueue.size() == QUEUE_SIZE);
		try {
			myQueue.enqueue(1);
			fail("enqueue() - should have generated an exception!");
		}
		catch (QueueArray.QueueException e) {
		}

		// The element should NOT have been added above, so let's make sure it wasn't
		assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
		assertTrue(myQueue.isFull());
		assertTrue(myQueue.size() == QUEUE_SIZE);
	}

	@Test
	public final void testDequeue() {
		myQueue = new QueueArray<Integer>(QUEUE_SIZE);
		
		// First, test to make sure you can't remove anything from a new queue
		try {
			myQueue.dequeue();
			fail("testDequeue() - should have generated an QueueException!");
		}
		catch (QueueArray.QueueException e) { }
		
		// Next, generate a full queue
		initQueues(QUEUE_SIZE,QUEUE_SIZE,true);
		assertFalse(myQueue.isEmpty());
		assertTrue(myQueue.isFull());
		assertEquals(QUEUE_SIZE,myQueue.size());
		
		// Remove half of them, checking size and state of the array, after each
		// step
		try {
			for(int i = 1; i <= QUEUE_SIZE/2; i++) {
				// Check to make sure both items removed were the same
				assertEquals(myQueue.dequeue(),javaQueue.removeFirst());
				
				// Verify the size of the queue
				assertEquals(QUEUE_SIZE-i,myQueue.size());
				
				// Verify the integrity of the entire queue
				assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
			}
		}
		catch (QueueArray.QueueException e) { 
			fail("testDequeue() - QueueException should NOT have been thrown!");
		}

		// Fill the queues back up...
		int i = 0;
		try {
			while(!myQueue.isFull()) {
				myQueue.enqueue(i);
				javaQueue.addLast(i);
				i++;
			}
			while(i > 0) {
				assertEquals(javaQueue.removeFirst(),myQueue.dequeue());
				i--;
			}
		}
		catch (QueueArray.QueueException e) {
			fail("testDequeue() - should NOT have generated exception here!");
		}
		
		// Verify the integrity of the entire queue
		assertArrayEquals(javaQueue.toArray(),myQueue.getCopyOfArray());
	}

	@Test
	public final void testPeek() {
		try {
			initQueues(QUEUE_SIZE,QUEUE_SIZE/2,true);
			while(!myQueue.isEmpty()) {
				assertEquals(javaQueue.getFirst(),myQueue.peek());
				assertEquals(javaQueue.removeFirst(),myQueue.dequeue());
			}
		}
		catch (QueueArray.QueueException e) {
			fail("testPeek() - QueueException should NOT have been thrown!");
		}
	}

}

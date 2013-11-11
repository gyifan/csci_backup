/**
 * This class is a simple implementation of a fixed-size, array-based queue
 * 
 * @author Prof. Brian King, Fall 2010
 */
public class QueueArray<T> {
	public static class QueueException extends Exception {

		private static final long serialVersionUID = 1L;

		QueueException() {
			super();
		}

		QueueException(String msg) {
			super(msg);
		}
	}

	/** The queue of objects represented internally by an array */
	private Object[] theList;

	/** Size of the queue */
	private int nMaxQueueSize;

	/** Index to head and tail */
	private int iHead, iTail;

	/** The actual count of objects in the queue */
	private int nActualCount;

	/** The size of the queue */
	private static final int DEFAULT_QUEUE_SIZE = 500;

	/**
	 * Create a new queue that is empty
	 */
	public QueueArray() {
		this(DEFAULT_QUEUE_SIZE);
	}

	/**
	 * Create a new queue of a specified size
	 */
	public QueueArray(int size) {
		nMaxQueueSize = size;
		theList = new Object[size];
		nActualCount = 0;
		iHead = iTail = 0;
	}

	/**
	 * Return the number of elements in the queue
	 */
	public int size() {
		return nActualCount;
	}

	/**
	 * Return the number of objects that can still be added to the queue
	 */
	public int getSpaceLeft() {
		return nMaxQueueSize - nActualCount;
	}

	/**
	 * Check if the queue is empty
	 * 
	 * @return <code>true</code> if the queue is empty, <code>false</code>
	 *         otherwise
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/**
	 * Check if the quue is full
	 * 
	 * @return <code>true</code> if the queue is full and has no more space,
	 *         <code>false</code> otherwise
	 */
	public boolean isFull() {
		return size() == nMaxQueueSize;
	}

	/**
	 * Adds a new object at the end of the queue
	 * 
	 * @param val
	 *            is the object to add to the queue
	 * @throws StackException
	 *             if there is no more room in the queue
	 */
	public void enqueue(T val) throws QueueException {
		if (isFull())
			throw new QueueException("enqueue() - queue full");
		theList[iTail] = val;
		iTail = (iTail + 1) % nMaxQueueSize;
		nActualCount++;
	}

	/**
	 * Removes the object at the head of the queue, and returns it
	 * 
	 * @return the object at the head of the queue
	 * @throws StackException
	 *             if there was no object to remove
	 */
	@SuppressWarnings("unchecked")
	public T dequeue() throws QueueException {
		if (isEmpty())
			throw new QueueException("dequeue() - queue empty");
		T temp = (T) theList[iHead];
		iHead = (iHead + 1) % nMaxQueueSize;
		nActualCount--;
		return temp;
	}

	/**
	 * Return the object at the head of the queue, but do not remove it
	 */
	@SuppressWarnings("unchecked")
	public T peek() throws QueueException {
		if (isEmpty())
			throw new QueueException("peek() - queue empty");
		return (T) theList[iHead];
	}

	/**
	 * Return a COPY of the existing array, trimmed to be the exact size of the
	 * number of elements in the actual list
	 * 
	 * @return the copied arraylist
	 */
	@SuppressWarnings("unchecked")
	public T[] getCopyOfArray() {
		Object[] copyOf = new Object[nActualCount];
		for (int i = 0; i < nActualCount; i++) {
			copyOf[i] = theList[(iHead + i) % nMaxQueueSize];
		}
		return (T[]) copyOf;
	}

	/**
	 * Simple program to test the Array List implementation
	 * 
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws QueueException {
		QueueArray<Integer> theQueue = new QueueArray<Integer>();

		for (int i = 0; i < 10; i += 2)
			theQueue.enqueue(i);

		while (!theQueue.isEmpty())
			System.out.println(theQueue.dequeue());

	}

}

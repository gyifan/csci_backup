/**
 * CSCI 204, Yifan Ge
 * Assiangment Class Examples My
 * Created: Apr 13, 2011, 11:12:49 AM
 */

/**
 * This class defines a queue, which follows the FIFO rule.
 * 
 * @author Yifan Ge
 * 
 */
public class Queue<T> {

	/** The head of the queue */
	private Node<T> head;

	/** The tail of the queue */
	private Node<T> tail;

	/** The number of items in the queue */
	private int count;

	/**
	 * Constructs a default queue object.
	 */
	public Queue() { // O(1+1)=O(1)
		head = null; // O(1)
		tail = null; // O(1)
	}

	/**
	 * Checks whether the queue is empty.
	 * 
	 * @return whether the queue is empty
	 */
	public boolean isEmpty() { // O(1)
		return count == 0; // O(1+1)
	}

	/**
	 * Checks whether the queue is full.
	 * 
	 * @return whether the queue is full
	 */
	public boolean isFull() { // O(1)
		return false; // O(1)
	}

	/**
	 * Removes the first item in the queue. If the queue is empty, do nothing.
	 */
	public void dequeue() { // O(1+1+1+1) = O(1)
		if (isEmpty()) // O(1)
			;
		else {
			head = head.getNext(); // O(1+1) = O(1)
			count--; // O(1)
		}
		if (isEmpty()) { // O(1)
			tail = null; // O(1)
		}
	}

	/**
	 * Adds an item to the end of the queue.
	 * 
	 * @param data
	 *            the item
	 */
	public void enqueue(T data) { // O(1+1+1+1+1+1) = O(1)
		Node<T> node = new Node<T>(); // O(1+1) = O(1)
		node.setData(data); // O(1)
		if (isEmpty()) { // O(1)
			head = node; // O(1)
			tail = node; // O(1)
		} else {
			tail.setNext(node); // O(1)
			tail = node; // O(1)
		}
		count++; // O(1)
	}

	/**
	 * Gets the first item in the queue without remove it.
	 * 
	 * @return the first item in the queue
	 */
	public T peek() { // O(1)
		return head.getData();
	}

	/**
	 * This class defines a node, which has data and pointer to the next node.
	 * 
	 * @author Yifan
	 * 
	 * @param <T>
	 *            the data type
	 */
	private class Node<T> {

		// instance fields

		/** The data stored in the node */
		private T data;

		/** The pointer to the next node */
		private Node<T> next;

		/**
		 * Constructs a default node.
		 */
		public Node() { // O(1)
			data = null;
			next = null;
		}

		/**
		 * Gets the data in the node.
		 * 
		 * @return the data
		 */
		public T getData() { // O(1)
			return data;
		}

		/**
		 * Gets the next node.
		 * 
		 * @return the next node
		 */
		public Node<T> getNext() { // O(1)
			return next;
		}

		/**
		 * Sets the data in the node.
		 * 
		 * @param data
		 *            the data
		 */
		public void setData(T data) { // O(1)
			this.data = data;
		}

		/**
		 * Sets the next node.
		 * 
		 * @param next
		 *            the next node
		 */
		public void setNext(Node<T> next) { // O(1)
			this.next = next;
		}
	}
}

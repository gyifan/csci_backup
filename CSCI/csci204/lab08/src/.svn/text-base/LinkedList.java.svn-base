import java.util.Iterator;
import java.util.Random;

/**
 * Basic Linked List ADT
 * 
 * @author Brian R. King
 * @param <T>
 *            is the object type that is stored in the linked list
 */
public class LinkedList<T> implements Iterable<T> {

	/** head - Reference to the first node in the list */
	private Node<T> head;

	/** tail - Reference to the last node in the list */
	private Node<T> tail;

	/** count - Count of the number of nodes in the list */
	private int count;

	/**
	 * Construct a new empty linked list
	 */
	LinkedList() {
		head = null;
		tail = null;
		count = 0;
	}

	/**
	 * Internal helper function to return the node at a specified index
	 * location.
	 * 
	 * @param index
	 *            is the location of the node specified
	 * @return the node at the location specified
	 * @throws ArrayIndexOutOfBoundsException
	 *             if a bad index is specified
	 */
	private Node<T> getNode(int index) throws ArrayIndexOutOfBoundsException {
		if (index < 0 || index >= count)
			throw new ArrayIndexOutOfBoundsException(index);
		Node<T> iter = head;
		for (int i = 1; i <= index; i++)
			iter = iter.getNext();
		return iter;
	}

	/**
	 * Return the object at the specified index location
	 * 
	 * @param index
	 *            is the location of the object requested
	 * @return the object at the specified location
	 * @throws ArrayIndexOutOfBoundsException
	 *             if a bad index is specified
	 */
	public T get(int index) {
		return getNode(index).getObject();
	}

	/**
	 * Return the number of objects in the list
	 */
	public int size() {
		return count;
	}

	/**
	 * Removes all of the elements from the list
	 */
	public void clear() {
		head = null;
		count = 0;
	}

	/**
	 * Add a new object to the end of the list
	 * 
	 * @param obj
	 *            - New object to add to the end of the list
	 */
	public void addLast(T obj) {
		Node<T> newNode = new Node<T>(obj);
		if (head == null)
			head = newNode;
		else
			tail.setNext(newNode);
		tail = newNode;
		count++;
	}

	public void addFirst(T obj) {
		Node<T> newNode = new Node<T>(obj);
		newNode.setNext(head);
		head = newNode;
		count++;
	}

	/**
	 * Insert an object at a specified index location. If the index is 0, then
	 * the object is inserted to the beginning of the list. If index == count,
	 * then the object is added to the end of the list
	 */
	public void insert(int index, T obj) {
		if (index < 0 || index > count)
			throw new ArrayIndexOutOfBoundsException(index);

		// If index == count, then just add the object to the end
		if (index == count) {
			addLast(obj);
			return;
		}

		// Insert node at a specified location in the list
		Node<T> newNode = new Node<T>(obj);
		if (index == 0) {
			newNode.setNext(head);
			head = newNode;
		} else {
			Node<T> iter = getNode(index - 1);
			newNode.setNext(iter.getNext());
			iter.setNext(newNode);
		}
		count++;
	}

	/**
	 * Remove the object at the specified location
	 * 
	 * @param index
	 *            is the location of the object to be removed from the linked
	 *            list
	 * @returns the object at the location that was removed
	 * @throws ArrayIndexOutOfBoundsException
	 *             if the index specified is invalid
	 */
	public T remove(int index) {
		if (index < 0 || index >= count)
			throw new ArrayIndexOutOfBoundsException(index);

		Node<T> node; // The node to be returned
		if (index == 0) {
			node = head;
			head = head.getNext();
		} else {
			Node<T> prev = getNode(index - 1);
			node = prev.getNext();
			prev.setNext(node.getNext());
		}

		count--;
		return node.getObject();
	}

	/**
	 * Search through the list for a specific object. This method assumes that
	 * the object in question has properly overridden the equals() method.
	 * 
	 * @param <code>obj</code> is the specific object you are looking for
	 * @returns the index location of the object, or -1 if it was not found
	 */
	public int findFirst(T obj) {
		int i = 0;
		Iterator<T> iter = iterator();
		while (iter.hasNext()) {
			if (obj.equals(iter.next()))
				break;
			i++;
		}
		if (i == size())
			return -1;
		else
			return i;
	}

	public int findLast(T obj) {
		int index = 0;
		int i = 0;
		Iterator<T> iter = iterator();
		while (iter.hasNext()) {
			if (obj.equals(iter.next()))
				index = i;
			i++;
		}
		if (index == 0)
			return -1;
		else
			return index;
	}

	/**
	 * Create a new iterator for the linked list. This is an instance of
	 * LinkedListIterator.
	 * 
	 * @return a new instance of {@link LinkedListIterator}
	 */
	@Override
	public Iterator<T> iterator() {
		return new LinkedListIterator();
	}

	/**
	 * Create a string representing the list of objects. This relies on the
	 * object stored having implemented the toString() method
	 */
	@Override
	public String toString() {
		String s = count + ":[";
		Node<T> iter = head;
		while (iter != null) {
			s += iter.getObject().toString();
			iter = iter.getNext();
			if (iter != null)
				s += ",";
		}
		s += "]";
		return s;
	}

	/**
	 * toArray - Creates an array representation of this linked list
	 * 
	 * @return a new array
	 */
	@SuppressWarnings("unchecked")
	public T[] toArray() {
		T[] a = (T[]) new Object[count];
		Iterator<T> iter = iterator();
		for (int i = 0; i < count; i++)
			a[i] = iter.next();
		return a;
	}

	/**
	 * <code>Node</code> is a nested class used to manage each node in the
	 * linked list. It is private, and used for implementation of the linked
	 * list only. No instance of Node<T> should ever be exposed outside of the
	 * data structure.
	 * 
	 * @author brk009
	 * 
	 * @param <T>
	 *            The type of the object stored inside of each node in the
	 *            linked list
	 */
	private static class Node<T> {
		private T obj;
		private Node<T> next;

		/**
		 * Create a new node with a null linked reference
		 * 
		 * @param obj
		 */
		Node(T obj) {
			this.obj = obj;
			next = null;
		}

		void setNext(Node<T> next) {
			this.next = next;
		}

		Node<T> getNext() {
			return this.next;
		}

		boolean hasNext() {
			return (this.next != null);
		}

		public T getObject() {
			return this.obj;
		}

		public void setObject(T obj) {
			this.obj = obj;
		}
	}

	/**
	 * Iterator for the Linked List. This is implemented as an inner class
	 * (non-static) because the iterator should be associated with a specific
	 * instance of the outer class
	 */
	public class LinkedListIterator implements Iterator<T> {
		private Node<T> iter;

		public LinkedListIterator() {
			iter = head;
		}

		@Override
		public boolean hasNext() {
			return (iter != null);
		}

		@Override
		public T next() {
			if (iter == null)
				return null;
			T obj = iter.getObject();
			iter = iter.getNext();
			return obj;
		}

		@Override
		public void remove() {
			throw new UnsupportedOperationException(
					"remove in LinkedListIterator not supported");
		}
	}

	/**
	 * Test program for LinkedList
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		int[] counts = new int[10];
		Random rand = new Random();
		int size = 500000;

		for (int i = 0; i < size; i++)
			list.addLast(rand.nextInt(10) + 1);

		Iterator<Integer> iter = list.iterator();
		while (iter.hasNext())
			counts[iter.next() - 1]++;

		for (int i = 0; i < 10; i++) {
			int num = i + 1;
			double percentage = (double) counts[i] * 100 / (double) size;
			System.out.printf("Number %d :	%6d	%4.2f%%\n", num, counts[i],
					percentage);
		}
	}
}

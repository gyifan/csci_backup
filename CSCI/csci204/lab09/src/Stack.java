/**
 * A Stack using a LinkedList to store elements.
 */
public class Stack<E> {
	private LinkedList<E> data;

	/**
	 * Construct a Stack object.
	 */
	public Stack() {
		data = new LinkedList<E>();
	}

	/**
	 * Pushes an item onto the top of this stack.
	 *
	 * @param item
	 *            the item to be pushed onto this stack.
	 * @return the item argument.
	 */
	public E push(E item) {
		data.addFirst(item);
		return item;
	}

	/**
	 * Removes the object at the top of this stack and returns that object as
	 * the value of this function.
	 *
	 * @return The object at the top of this stack.
	 */
	public E pop() {
		return data.removeFirst();
	}

	/**
	 * Looks at the object at the top of this stack without removing it from the
	 * stack.
	 *
	 * @return the object at the top of this stack
	 */
	public E peek() {
		return data.getFirst();
	}

	/**
	 * Tests if this stack is empty.
	 *
	 * @return true if and only if this stack contains no items, false
	 *         otherwise.
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/**
	 * Gets the number of items in the stack.
	 *
	 * @return the size
	 */
	public int size() {
		return data.size();
	}

	/**
	 * Clears the stack.
	 */
	public void clear() {
		while (data.size() > 0)
			data.removeFirst();
	}
}

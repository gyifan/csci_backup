package Stacks;

public interface IStack<T> {

	/**
	 * Returns the number of elements in the stack
	 */
	public int size();

	/**
	 * Returns true if the stack is empty and false otherwise.
	 */
	public boolean isEmpty();

	/**
	 * Pushes the given item onto the Stack
	 */
	public void push(T item);

	/**
	 * Pop the stack
	 */
	public void pop();

	/**
	 * Returns the top item on the Stack without changing the Stack.
	 */
	public T peek();
}

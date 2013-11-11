/**
 * CSCI 204, Yifan Ge
 * Assiangment CSCI 204 Class
 * Created: Mar 30, 2011, 11:44:53 AM
 */
package Stacks;

import java.util.Scanner;

/**
 * @author ygg001
 * @param <T>
 * 
 */
public class LinkedStack<T> implements IStack<T> {

	private Node<T> head;
	private int counter;

	public LinkedStack() {
		head = null;
		counter = 0;
	}

	@Override
	public boolean isEmpty() {
		return counter == 0; // O(1)
	}

	@Override
	public T peek() {
		if (head != null) // O(1)
			return head.getData(); // O(1)
		else
			return null;
	}

	@Override
	public void pop() {
		if (head != null) { // O(1)
			head = head.getNext(); // O(1)
			counter--; // O(1);
		}
	}

	@Override
	public void push(T item) {
		Node<T> n = new Node<T>();
		n.setData(item);
		n.setNext(head);
		head = n;
		counter++;
	}

	@Override
	public int size() {
		return counter;
	}

	private class Node<T> {
		private T data;
		private Node<T> next;

		public Node() {
			data = null;
			next = null;
		}

		public T getData() {
			return data;
		}

		public Node<T> getNext() {
			return next;
		}

		public void setData(T data) {
			this.data = data;
		}

		public void setNext(Node<T> next) {
			this.next = next;
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String word = scan.next();

		LinkedStack<String> stack = new LinkedStack<String>();
		for (int i = 0; i < word.length(); i++) {
			stack.push(word.substring(i, i + 1));
		}

		boolean isPalindromes = true;
		int index = 0;

		while (!stack.isEmpty()) {
			if (!(stack.peek().equals(word.substring(index, index + 1))))
				isPalindromes = false;
			stack.pop();
			index++;
		}

		if (isPalindromes)
			System.out.println("It is palindromes");
		else
			System.out.println("It is not palindromes");

	}
}

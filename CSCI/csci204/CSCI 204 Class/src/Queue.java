import java.util.Scanner;

import Stacks.LinkedStack;

/**
 * CSCI 204, Yifan Ge
 * Assiangment Class Examples My
 * Created: Apr 13, 2011, 11:12:49 AM
 */

/**
 * @author ygg001
 * 
 */
public class Queue<T> {

	private Node<T> head;
	private Node<T> tail;
	private int count;

	public Queue() { // O(1)
		head = null;
		tail = null;
	}

	public boolean isEmpty() { // O(1)
		return count == 0;
	}

	public boolean isFull() { // O(1)
		return false;
	}

	public void dequeue() { // O(1)
		if (isEmpty())
			;
		else {
			head = head.next;
			count--;
		}
		if (isEmpty()) {
			tail = null;
		}
	}

	public void enqueue(T data) { // O(1)
		Node<T> node = new Node<T>();
		node.data = data;
		if (isEmpty()) {
			head = node;
			tail = node;
		} else {
			tail.next = node;
			tail = node;
		}
		count++;
	}

	public T peek() { // O(1)
		return head.data;
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

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		LinkedStack<Character> stack = new LinkedStack<Character>();
		Queue<Character> queue = new Queue<Character>();
		Scanner scan = new Scanner(System.in);
		boolean isPalindromes = false;

		String line = scan.next().toLowerCase();
		for (int i = 0; i < line.length(); i++) {
			char ch = line.charAt(i);
			queue.enqueue(ch);
			stack.push(ch);
		}

		while (!queue.isEmpty()) {
			if (queue.peek() == stack.peek())
				isPalindromes = true;
			else
				isPalindromes = false;
			queue.dequeue();
			stack.pop();
		}

		if (isPalindromes)
			System.out.println("It is Palindromes");
		else
			System.out.println("It is not Palindromes");

	}
}

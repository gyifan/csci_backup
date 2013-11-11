package Stacks;

public class LinkedStackSolution<T> implements IStack<T> {

	public class Node {
		Node next;
		T data;
	}

	private Node head;

	// default constructor makes head null

	@Override
	public boolean isEmpty() { // O(1)
		return head == null;
	}

	@Override
	// What do do if empty? crash? throw exceptions? return null?
	// i'm choosing to return null
	public T peek() { // O(1)
		if (null == head)
			return null;
		else
			return head.data;
	}

	@Override
	// What do do if empty? crash? throw exceptions? nothing?
	// i'm choosing to do nothing
	public void pop() { // O(1)
		if (null != head)
			head = head.next;
	}

	@Override
	public void push(T item) { // O(1)
		Node n = new Node();
		n.data = item;
		n.next = head; // real item or null if empty anyway
		head = n;
	}

	@Override
	// i'm not keeping a counter
	public int size() { // O(n)
		int count = 0;
		for (Node temp = head; temp != null; temp = temp.next)
			count++;
		return count;
	}

	public static void main(String[] args) {
		LinkedStackSolution<Integer> stack = new LinkedStackSolution();
		System.out.println(stack.isEmpty()); // true
		System.out.println(stack.size()); // 0
		stack.push(3);
		stack.push(4);
		stack.push(5);
		System.out.println(stack.peek()); // 5
		System.out.println(stack.isEmpty()); // false
		System.out.println(stack.size()); // 3
		stack.pop();
		System.out.println(stack.peek()); // 4
		System.out.println(stack.isEmpty()); // false
		System.out.println(stack.size()); // 2
		stack.pop();
		System.out.println(stack.peek()); // 3
		stack.pop();
		System.out.println(stack.peek()); // null
		System.out.println(stack.isEmpty()); // true
		System.out.println(stack.size()); // 0

		stack.push(8);
		stack.push(7);
		stack.pop();
		stack.push(6);
		System.out.println(stack.size()); // 2
		// this was just in case pop makes future pushes not work.
	}

}

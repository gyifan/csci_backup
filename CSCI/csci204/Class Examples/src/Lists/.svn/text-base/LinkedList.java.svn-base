package Lists;

public class LinkedList {

	public class Node {
		int item;
		Node next;
	}

	Node head;
	int counter;

	public LinkedList() {
		head = null;
		counter = 0;
	}

	public boolean isEmpty() {
		return true;
	}

	public int size() {
		return -1;
	}

	public void insert(int item, int index) {
		Node n = new Node();
		n.item = item;

		// empty
		if (counter == 0) {
			head = n;
		}
		// first
		else if (index <= 0) {

		}

		// last
		else if (index >= size()) {
			// Get temp to last node
			Node temp = head;
			for (temp = head; temp.next != null; temp = temp.next)
				;
			temp.next = n;
		}

		// middle somewhere
		else {

		}

		counter++;
	}

	public void insertFirst(int item) {

	}

	public void insertLast(int item) {

	}

	public int get(int index) {
		return -1;
	}

	public void remove(int index) { // O(index)
		// O(n-index) but index is smaller than n so O(n)
		if (index < 0)
			return;
		if (index >= counter)
			return;

		// first
		if (index == 0) {
			head = n.next;
		} else {
			// Get temp to index-1th node
			Node temp = head;
			for (int i = 0; i < index - 1; i++)
				temp = temp.next;

			temp.next = n.next;
		}
		counter--;
	}

}

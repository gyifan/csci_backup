package Stacks;

public class ArrayStack<T> implements IStack<T> {

	T[] array;
	int count;

	public ArrayStack() {
		array = (T[]) new Object[20]; // silly generics syntax
		count = 0; // default constructor set it to 0 too
	}

	@Override
	public boolean isEmpty() { // 1
		return count == 0;
	}

	@Override
	public T peek() { // 1
		if (!isEmpty()) {
			return array[count - 1];
		}
		return null;
	}

	@Override
	public void pop() { // 1
		if (!isEmpty()) {
			count--;
		}

	}

	@Override
	public void push(T item) { // 1 or n
		if (count < array.length) {// O(1)
			array[count] = item;
			count++;
		} else { // O(n) where n is size of stack
			T[] temp = (T[]) new Object[array.length * 2];
			for (int i = 0; i < array.length; i++) {
				temp[i] = array[i];
			}
			array = temp;
			push(item);
		}
	}

	@Override
	public int size() { // 1
		return count;
	}

	public static void main(String[] args) {
		ArrayStack<Integer> s = new ArrayStack();
		System.out.println(s.isEmpty()); // true
		System.out.println(s.size()); // 0
		s.push(3);
		System.out.println(s.peek()); // 3
		System.out.println(s.isEmpty()); // false
		System.out.println(s.size()); // 1
		s.push(5);
		s.pop();
		System.out.println(s.peek()); // 3
		System.out.println(s.isEmpty()); // false
		System.out.println(s.size()); // 1
		s.push(6);
		s.push(8);
		System.out.println(s.peek()); // 8
		System.out.println(s.isEmpty()); // false
		System.out.println(s.size()); // 3

	}
}

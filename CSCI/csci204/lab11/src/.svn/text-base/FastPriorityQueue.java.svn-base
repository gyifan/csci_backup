import java.util.ArrayList;
import java.util.LinkedList;

/**
 * Fast priority queue. For this implementation, you need to know the maximum
 * priority in advance.
 * 
 * 2008-03-20
 * 
 * @author zaccone
 * 
 * @param <E>
 *            the type of the elements in the priority queue.
 */
public class FastPriorityQueue<E> {
	private ArrayList<LinkedList<E>> itemLists;

	/**
	 * Constructs a new priority queue.
	 * 
	 * @param maxPriority
	 *            the maximum priority of any item in the queue
	 */
	public FastPriorityQueue(int maxPriority) {
		itemLists = new ArrayList<LinkedList<E>>();
		for (int i = 0; i <= maxPriority; i++)
			itemLists.add(new LinkedList<E>());
	}

	/**
	 * Adds an item to the priority queue.
	 * 
	 * @param priority
	 *            the priority of the item we are adding. Precondition: priority
	 *            must be <= the max priority specified in the constructor. The
	 *            highest priority is one.
	 * @param item
	 *            the item to add to the priority queue.
	 */
	public void add(int priority, E item) {
		itemLists.get(priority).addLast(item);
	}

	/**
	 * Removes the highest priority item from the priority queue.
	 * 
	 * @return the highest priority item, null if the priority queue is empty.
	 */
	public E remove() {
		for (int i = 0; i < itemLists.size(); i++) {
			if (!itemLists.get(i).isEmpty()) {
				return itemLists.get(i).removeFirst();
			}
		}
		return null;

	}

	/**
	 * Returns the number of items in the priority queue.
	 * 
	 * @return the size of the priority queue
	 */
	public int size() {
		int size = 0;
		for (int i = 0; i < itemLists.size(); i++)
			size += itemLists.get(i).size();
		return size;
	}
}

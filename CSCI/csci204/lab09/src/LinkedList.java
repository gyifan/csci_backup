import java.util.NoSuchElementException;

/**
 * A linked list is a sequence of nodes with efficient element insertion and
 * removal. This class contains a subset of the methods of the standard
 * java.util.LinkedList class.
 */
public class LinkedList<E> {
    private Node first;
    private Node last;
    private int size;

    /**
     * Constructs an empty linked list. (changed)
     */
    public LinkedList() {
        first = null;
        last = null;
        size = 0;
    }

    /**
     * Returns the first element in the linked list.
     *
     * @return the first element in the linked list
     */
    public E getFirst() {
        if (first == null)
            throw new NoSuchElementException();
        return first.data;
    }

    /**
     * Removes the first element in the linked list. (changed)
     *
     * @return the removed element
     */
    public E removeFirst() {
        if (first == null)
            throw new NoSuchElementException();
        if (first == last)
            last = null;
        E element = first.data;
        first = first.next;
        size--;
        return element;
    }

    /**
     * Adds an element to the front of the linked list. (changed)
     *
     * @param element
     *            the element to add
     */
    public void addFirst(E element) {
        Node newNode = new Node();
        newNode.data = element;
        newNode.next = first;
        first = newNode;
        if (last == null)
            last = first;
        size++;
    }

    /**
     * Adds an element to the end of the linked list (new)
     *
     * @param element
     *            the element to add
     */
    public void add(E element) {
        Node newNode = new Node();
        newNode.data = element;
        newNode.next = null;
        if (last != null)
            last.next = newNode;
        last = newNode;
        if (first == null)
            first = last;
        size++;
    }

    /**
     * Returns the size of the list
     *
     * @return the size of the list
     */
    public int size() {
        return size;
    }

    /**
     * Counts the nodes in the list.
     *
     * @return the size of the list
     */
    public int count() {
        if (first == null)
            return 0;
        int count = 1;
        Node current = first.next;
        while (current != null) {
            current = current.next;
            count++;
        }
        return count;
    }

    /**
     * Returns an iterator for iterating through this list.
     *
     * @return an iterator for iterating through this list
     */
    public ListIterator<E> listIterator() {
        return new LinkedListIterator();
    }

    private class Node {
        public E data;
        public Node next;
    }

    private class LinkedListIterator implements ListIterator<E> {
        private Node position; // Last visited node
        private Node previous; // The node visited before position

        /**
         * Constructs an iterator that points to the front of the linked list.
         */
        public LinkedListIterator() {
            position = null;
            previous = null;
        }

        /**
         * Moves the iterator past the next element.
         *
         * @return the traversed element
         */
        public E next() {
            if (!hasNext())
                throw new NoSuchElementException();
            previous = position; // Remember for remove

            if (position == null)
                position = first;
            else
                position = position.next;

            return position.data;
        }

        /**
         * Tests if there is an element after the iterator position.
         *
         * @return true if there is an element after the iterator position
         */
        public boolean hasNext() {
            if (position == null)
                return first != null;
            else
                return position.next != null;
        }

        /**
         * Adds an element before the iterator position and moves the iterator
         * past the inserted element. (changed)
         *
         * @param element
         *            the element to add
         */
        public void add(E element) {
            if (position == null) {
                addFirst(element);
                position = first;
            } else {
                Node newNode = new Node();
                newNode.data = element;
                newNode.next = position.next;
                position.next = newNode;
                position = newNode;
                if (newNode.next == null)
                    last = newNode;
            }
            previous = position;
            size++;
        }

        /**
         * Removes the last traversed element. This method may only be called
         * after a call to the next() method. (changed)
         */
        public void remove() {
            if (previous == position)
                throw new IllegalStateException();

            if (position == first) {
                removeFirst();
            } else {
                previous.next = position.next;
                if (previous.next == null)
                    last = previous;
            }
            position = previous;
            size--;
        }

        /**
         * Sets the last traversed element to a different value.
         *
         * @param element
         *            the element to set
         */
        public void set(E element) {
            if (position == null)
                throw new NoSuchElementException();
            position.data = element;
        }
    }
}

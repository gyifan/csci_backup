/**
 * This class encapsulates a simple task description as a work order.
 *
 * Last Modified: 11/17/2009
 * @author unknown, sm053
 */
public class WorkOrder {
    /**
     * A description of the task.
     */ 
    private String description;

    /**
     * Constructs a work order with a given priority and description.
     *
     * @param aDescription
     *            the description of this work order
     */
    public WorkOrder(String aDescription) {
        description = aDescription;
    }

    @Override
    public String toString() {
        return description;
    }

    /**
     * Tests the <tt>FastPriorityQueue</tt> implementation via use of
     * of <tt>WorkOrder</tt>.
     *
     * @param args unused
     */
    public static void main(String[] args) {
        FastPriorityQueue<WorkOrder> q = new FastPriorityQueue<WorkOrder>(10);
        q.add(3, new WorkOrder("Shampoo carpets"));
        q.add(7, new WorkOrder("Empty trash"));
        q.add(8, new WorkOrder("Water plants"));
        q.add(10, new WorkOrder("Remove pencil sharpener shavings"));
        q.add(6, new WorkOrder("Replace light bulb"));
        q.add(1, new WorkOrder("Fix broken sink"));
        q.add(6, new WorkOrder("Pet the dog"));
        q.add(9, new WorkOrder("Clean coffee maker"));
        q.add(2, new WorkOrder("Order cleaning supplies"));
        q.add(6, new WorkOrder("Take a nap"));

        while (q.size() > 0)
            System.out.println(q.remove());
    }
}

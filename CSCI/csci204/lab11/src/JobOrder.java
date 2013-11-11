import java.util.PriorityQueue;

/**
 * CSCI 204, Yifan Ge
 * Assiangment lab11
 * Created: Apr 21, 2011, 10:28:31 AM
 */

/**
 * This class uses PriorityQueue class in Java Library to sort jobs.
 * 
 * @author Yifan Ge
 * 
 */
public class JobOrder implements Comparable<JobOrder> {

	// Instance fields
	/** The description of the job */
	private String description;
	/** The priority of the job. Smaller integer means higher priority. */
	private int priority;

	/**
	 * Constructs a JobOrder object which contains the description and priority
	 * information about the job.
	 * 
	 * @param priority
	 *            the priority
	 * @param description
	 *            the description
	 */
	public JobOrder(int priority, String description) {
		this.priority = priority;
		this.description = description;
	}

	/**
	 * Returns a string that in the format of "Priority %d: %s", where %d is the
	 * priority and %s is the description.
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return "Priority " + priority + ": " + description;
	}

	/**
	 * Compares the priority of two jobs. If the original job has higher
	 * priority, returns a negative number, vice versa.
	 * 
	 * @param job
	 *            the job that compared with
	 * 
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(JobOrder job) {
		return priority - job.priority;
	}

	/**
	 * Tests the JobOrder class and uses PriorityQueue Class in Java Library to
	 * sort jobs.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		PriorityQueue<JobOrder> q = new PriorityQueue<JobOrder>();

		q.add(new JobOrder(3, "Shampoo carpets"));
		q.add(new JobOrder(7, "Empty trash"));
		q.add(new JobOrder(8, "Water plants"));
		q.add(new JobOrder(10, "Remove pencil sharpener shavings"));
		q.add(new JobOrder(6, "Replace light bulb"));
		q.add(new JobOrder(1, "Fix broken sink"));
		q.add(new JobOrder(6, "Pet the dog"));
		q.add(new JobOrder(9, "Clean coffee maker"));
		q.add(new JobOrder(2, "Order cleaning supplies"));
		q.add(new JobOrder(6, "Take a nap"));

		while (q.size() > 0) {
			System.out.println(q.peek());
			q.remove();
		}

	}

}

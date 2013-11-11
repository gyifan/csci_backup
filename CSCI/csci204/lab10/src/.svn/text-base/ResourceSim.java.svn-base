import java.util.Random;

/**
 * A simple resource manager with a neat GUI to show the current load of each
 * server queue
 * 
 * CSCI 204 - Fall 2010
 * 
 * @author Brian R. King
 */
public class ResourceSim {

	/** Number of servers to simulate */
	public final static int NUM_SERVER = 100;

	/** Initial delay between submitting requests to the server pool */
	public final static int REQUEST_DELAY_MS = 50;

	/** Maximum delay to allow */
	public final static int MAX_REQUEST_DELAY_MS = 250;

	public final static int QUEUE_SIZE = 25;

	/** Number of servers being simulated */
	private int nServer;

	/** Array of server instances */
	Server[] servers;

	/** Reference to the GUI */
	private static GUI gui;

	/** Random number generator to be used throughout the simulation */
	private Random rand;

	private int serverNumber;

	/**
	 * Constructor -- creates a new simulator with GUI, initialized with
	 * <code>nServer</code> servers
	 */
	public ResourceSim(int nServer) {
		this.nServer = nServer;
		rand = new Random(System.nanoTime());
		gui = new GUI("Resource Manager Simulation", nServer,
				MAX_REQUEST_DELAY_MS, REQUEST_DELAY_MS);
		servers = new Server[NUM_SERVER];
		for (int i = 0; i < NUM_SERVER; i++)
			servers[i] = new Server(i);
		gui.display();
		serverNumber = 0;
	}

	/**
	 * This is perhaps the most important method of the simulation. This is
	 * where you determine how you want the next server to be selected when the
	 * next incoming request comes in.
	 * 
	 * @return the index of the server to be selected next
	 */
	public int scheduleNextServer() {

		// TODO -- Finish this method by first implementing a round-robin
		// scheduling
		// scheme. This amounts to nothing more than returning the next server
		// in line
		// When you go to implement the random scheduler, use the method call
		// 
		// gui.getSampleSliderValue()
		// 
		// to get the current number of samples to take. Then, write a loop to
		// randomly
		// select that number of servers, and return the index of the server
		// that has
		// the lowest load
		int iNextToSchedule = 0;
		double minLoad = 100.0;
		for (int i = 0; i < gui.getSampleSliderValue(); i++) {
			int sample = rand.nextInt(NUM_SERVER);
			if (minLoad >= servers[sample].getCurrentLoad()) {
				minLoad = servers[sample].getCurrentLoad();
				iNextToSchedule = sample;
			}
		}

		return iNextToSchedule;
	}

	/**
	 * Start the thread that simulates the ith server
	 */
	public void startServer(int i) {
		servers[i].start();
	}

	/**
	 * Start ALL of the server simulation threads
	 */
	public void startAllServers() {
		for (int i = 0; i < NUM_SERVER; i++) {
			startServer(i);
		}
	}

	/**
	 * Add a new job to one of the servers. The server selected is determined by
	 * the result of <code>scheduleNextServer</code>
	 * 
	 * @param val
	 *            is the integer that represents the length of the job
	 */
	public void addJob(Integer val) {
		servers[scheduleNextServer()].addJob(val);
	}

	/**
	 * Compute the average load over all of the servers and return it
	 */
	public double getAverageLoad() {
		// - You need to write a function to return the average load over
		// all of the servers. First get a sum of each individual server load,
		// and then
		// take the average of that sum and return it.
		double averageLoad = 0.0;
		double sum = 0.0;
		for (int i = 0; i < NUM_SERVER; i++)
			sum += servers[i].getCurrentLoad();
		averageLoad = sum / NUM_SERVER;
		return averageLoad;
	}

	/**
	 * Compute the load variance among all of the servers.
	 */
	public double getLoadVariance() {
		double mean = getAverageLoad();
		double var = 0.0;
		for (int i = 0; i < NUM_SERVER; i++) {
			var += Math.pow(servers[i].getCurrentLoad() - mean, 2.0);
		}
		return Math.sqrt(var);
	}

	/**
	 * Update the current load output and current variance on the GUI
	 */
	public void updateLoadOutput() {
		String s = "Total Load: %"
				+ String.format("%.1f", getAverageLoad() * 100.0)
				+ "    Variance: " + String.format("%.3f", getLoadVariance());
		gui.setGraphLabel(s);
	}

	/**
	 * Static nested class to simulate a server. Since it is extended from
	 * Thread, it amounts to nothing more than overloading the Thread class run
	 * method. When start() is invoked on this server, the server thread is
	 * executed
	 * 
	 * @author Brian King
	 */
	public static class Server extends Thread {
		QueueArray<Integer> requestQueue;
		int id;

		/**
		 * Server constructor -- create a new simulated server with identifier
		 * id
		 */
		Server(int id) {
			this.id = id;
			requestQueue = new QueueArray<Integer>(QUEUE_SIZE);
		}

		public void run() {
			while (true) {
				try {
					// - if (the queue is empty) ... fill in the missing
					// boolean
					// expression here (i.e. it should not be true)
					if (requestQueue.isEmpty()) {
						// Thread is idle
						Thread.sleep(10);
					} else {
						// We have a request! Get the integer from the request,
						// which
						// represents how CPU intensive the request is. Simulate
						// being
						// busy by putting the thread to sleep that amount of
						// time. When
						// the request is finish, update the bar for this server

						// - Call the Thread.sleep method to put this
						// thread
						// to sleep the amount of time specified by the integer
						// in the top of the queue. Then, call dequeue to remove
						// the "job"
						Thread.sleep(requestQueue.dequeue());

						// The job was removed from the queue. Update the load
						gui.adjustBarHeight(id, getCurrentLoad());
					}
				} catch (InterruptedException e) {
				} catch (QueueArray.QueueException e) {
				}
			}
		}

		/**
		 * add a new job to this server's queue
		 * 
		 * @param val
		 */
		public void addJob(Integer val) {
			try {
				requestQueue.enqueue(val);
				gui.adjustBarHeight(id, getCurrentLoad());
			} catch (QueueArray.QueueException e) {
				System.err.println("The server is full");
			}
			// add the request (parameter val) to the server's queue. This
			// is nothing
			// more than calling the server's enqueue method. However, be sure
			// to
			// handle the possibility that the server is full, in which case you
			// should
			// output a message to system.err indicating this problem, and just
			// return.
			// NOTE,
			// to catch a nested exception, use catch QueueArray.QueueException
			// for the
			// exception type

			// Adjust the graphical bar representing the load on this server
			// AFTER
			// SUCCESSFULLY adding the job to the queue. LEAVE THIS LINE ALONE!
			// Just
			// make sure it goes in its proper place
		}

		/**
		 * Return this server's current load, which is estimated by computing
		 * how full the server is.
		 */
		public double getCurrentLoad() {
			// return the server's load. THis is the number of items in the
			// queue
			// divided by the total queue length. (i.e. do NOT return 0.0 as
			// below!)

			return (double) requestQueue.size() / QUEUE_SIZE;
		}
	}

	/**
	 * The main program. Here, we create a new simulator, start all of the
	 * servers, and then handle generating new random jobs of various durations.
	 */
	public static void main(String[] args) {
		ResourceSim r = new ResourceSim(NUM_SERVER);
		r.startAllServers();

		try {
			while (true) {
				r.addJob((int) (Math.random() * 2000));
				Thread.sleep(r.gui.getRequestDelaySliderValue());
				r.updateLoadOutput();
			}
		} catch (InterruptedException e) {
		}
	}

}

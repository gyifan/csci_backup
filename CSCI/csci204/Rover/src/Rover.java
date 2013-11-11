import java.awt.Image;
import java.awt.Point;
import java.util.LinkedList;
import java.util.Random;
import java.util.Stack;

/**
 * CSCI 204, Yifan Ge
 * Assignment Rover
 * Created: Apr 21, 2011, 4:03:43 PM
 */

/**
 * Extra credits: 1. inventory is alphabetized. 2. reasoning whether the stack
 * back home can contain loops: In my code, I push portals to the stack. And
 * unvisited portal will always generate a new room. So all the portals that
 * pushed into the stack are different. Thus, my stack won't contain loops.
 * 
 * I'm using one late card for this project. But the extra credits are done.
 * 
 * This program is a simple roll play game. In the game, the player is going to
 * control a rover and follows the instructions to fix a space ship. The
 * detailed instructions are given in the task window of the program. In order
 * to accomplish the tasks, the player would need to find required materials.
 * There will be three materials available, which are Cake, Gear, and Screw. The
 * map also has portal which can teleport the rover to another map. The rover
 * can also use the previous portal to teleport back. There will be a show the
 * way back button. After all the tasks are finished, the space ship will be
 * fixed and the player will win the game.
 * 
 * This program uses Queue to store tasks, Image arrays to represent rooms,
 * LinkedList to store inventory, and stack to store the portals. Based on that,
 * the program will be able to display the maps, teleport the rover to the
 * linked portal, store the picked objects and display them, and display and
 * change tasks.
 * 
 * 
 * @author Yifan Ge
 * 
 */
public class Rover implements IRover {

	// instance fields

	/** The room information that the rover is located. */
	private Room room;

	/** The location of the rover. */
	private Point location;

	/** The queue for tasks. */
	private Queue<Task> taskList;

	/** The list of inventory that rover picked up. */
	private LinkedList<String> list;

	/** The map leads the rover back to base. */
	private Stack<Portal> portalStack;

	/** The variable to generate random numbers. */
	private Random rand;

	/**
	 * Constructs a new rover object with base room, new list of tasks, and
	 * other default values.
	 */
	public Rover() {
		rand = new Random();
		room = new Room();
		room.setBaseRoom();
		location = new Point(rand.nextInt(Room.SIZE), rand.nextInt(Room.SIZE));
		taskList = new Queue<Task>();
		generateTasks();
		list = new LinkedList<String>();
		portalStack = new Stack<Portal>();
	}

	/**
	 * Returns the image of the rover. This is an accessor method. Called by the
	 * GuiPanel so it can draw the rover. If the image refuses to load, this
	 * method will return null.
	 * 
	 * @return the image of the rover
	 * 
	 * @see IRover#getImage()
	 */
	@Override
	public Image getImage() {
		return Icon.ROVER.getImage();
	}

	/**
	 * Returns the inventory. Called by the Gui so it can update the inventory
	 * display. This is an accessor method.
	 * <P>
	 * The inventory will be formatted so the item count appears next to the
	 * item name. Items not found in the inventory do not appear. The string
	 * must fit inside the provide inventory window.
	 * 
	 * @see IRover#getInventory()
	 */
	@Override
	public String getInventory() {
		String inventoryList = "";

		// Checks if empty, return null.
		if (list.isEmpty())
			return inventoryList;

		// Gets the number of each item. Displays them if they are not 0.
		if (getAvailableItemNum("Cake") != 0)
			inventoryList += getAvailableItemNum("Cake") + " cake\n";
		if (getAvailableItemNum("Gear") != 0)
			inventoryList += getAvailableItemNum("Gear") + " gear\n";
		if (getAvailableItemNum("Screw") != 0)
			inventoryList += getAvailableItemNum("Screw") + " screw\n";
		return inventoryList;
	}

	/**
	 * Gets the available quantity of the item in the inventory.
	 * 
	 * @param item
	 *            the item
	 * @return the quantity
	 */
	public int getAvailableItemNum(String item) {
		int count = 0;
		LinkedList<String> temp = new LinkedList<String>(list);
		while (temp.remove(item))
			count++;
		return count;
	}

	/**
	 * Returns the current location of the rover as a coordinate: column (x) and
	 * row (y). This is an accessor method. Called by the GuiPanel so it can
	 * draw the rover.
	 * 
	 * @return the location of the rover in the current room.
	 * 
	 * @see IRover#getLocation()
	 */
	@Override
	public Point getLocation() {
		return location;
	}

	/**
	 * Returns the curent room. This is an accessor method. Called by GuiPanel
	 * so that it can draw the objects in the room.
	 * 
	 * @return the current room
	 * 
	 * @see IRover#getRoom()
	 */
	@Override
	public IRoom getRoom() {
		return room;
	}

	/**
	 * Returns the task at the front of the task queue. This is an accessor
	 * method. Called by the Gui so it can update the task display.
	 * <P>
	 * The task must fit in 4 lines and with in the provided task window. It
	 * must have a name that tells you what you are fixing. It must require
	 * exactly 3 kinds of parts and use at least 1 of each part (so
	 * "Fixing the engine: 1 Cake, 2 Gears, and 3 Screws" would be fine).
	 * 
	 * @return the current task.
	 * 
	 * @see IRover#getTask()
	 */
	@Override
	public String getTask() {
		if (taskList.isEmpty())
			return "You Won!!";
		return taskList.peek().getTask();
	}

	/**
	 * Generates a task list for the new rover. This list will includes total 5
	 * tasks. one fixing the cabin, three fixing engines, and one fixing the
	 * exhaust. These task objects will be enqueued to the task queue.
	 */
	public void generateTasks() {
		for (int i = 0; i < 8; i++) {
			if (i < 1) {
				Task task = new Task("cabin");
				task.setImage(Icon.CABIN.getImage());
				taskList.enqueue(task);
			} else if (i < 4) {
				Task task = new Task("engine");
				task.setImage(Icon.ENGINE.getImage());
				taskList.enqueue(task);
			} else if (i < 5) {
				Task task = new Task("exhaust");
				task.setImage(Icon.EXHAUST.getImage());
				taskList.enqueue(task);
			}
		}
	}

	/**
	 * This class describes the task. Each task object includes the detailed
	 * information about the task. It has task name, task needed materials, and
	 * the image of the object that performs on.
	 * 
	 * @author Yifan
	 * 
	 */
	private class Task {
		/** The name of the task. */
		private String name;
		/** The required material for the task. */
		private String task;
		/** The image of the object that task performs on. */
		private Image image;
		/** The number of cakes needed for the task. */
		private int numOfCake;
		/** The number of gears needed for the task. */
		private int numOfGear;
		/** The number of screws needed for the task. */
		private int numOfScrew;

		/**
		 * Constructs a task object with the desired name.
		 * 
		 * @param name
		 *            the name of the task
		 */
		public Task(String name) {
			this.name = name;
			image = null;
			numOfCake = rand.nextInt(4) + 1;
			numOfGear = rand.nextInt(4) + 1;
			numOfScrew = rand.nextInt(4) + 1;
			task = "Fix the " + name + "\n" + numOfCake + " " + "cake\n"
					+ numOfGear + " " + "gear\n" + numOfScrew + " " + "screw";
		}

		/**
		 * Gets the name of the task.
		 * 
		 * @return the name of the task
		 */
		public String getName() {
			return name;
		}

		/**
		 * Gets the material list of the task.
		 * 
		 * @return the material list
		 */
		public String getTask() {
			return task;
		}

		/**
		 * Sets the image object that the task is performed on.
		 * 
		 * @param image
		 *            the image for the object
		 */
		public void setImage(Image image) {
			this.image = image;
		}

		/**
		 * Gets the image of the object that the task is performed on.
		 * 
		 * @return the image of the object
		 */
		public Image getImage() {
			return image;
		}

		/**
		 * Gets the number of cakes needed to complete the task.
		 * 
		 * @return the number of cakes
		 */
		public int getNumOfCake() {
			return numOfCake;
		}

		/**
		 * Gets the number of gears needed to complete the task
		 * 
		 * @return the number of gears
		 */
		public int getNumOfGear() {
			return numOfGear;
		}

		/**
		 * Gets the number of screws needed to complete the task
		 * 
		 * @return the number of screws
		 */
		public int getNumOfScrew() {
			return numOfScrew;
		}
	}

	/**
	 * Perform the task in the task bar. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If we are not standing on the relevant broken ship part or we
	 * do not have all the supplies, nothing happens. If we do happen to
	 * accomplish the task, that part of the ship gets fixed and the next task
	 * appears. If we run out of tasks, we win.
	 * 
	 * @see IRover#performTask()
	 */
	@Override
	public void performTask() {

		// Gets the current task.
		Task task = taskList.peek();

		// Proceeds if the rover stands on the relevant part and with enough
		// materials.
		if (room.getImage(location.x, location.y) == task.getImage()
				&& getAvailableItemNum("Cake") >= task.getNumOfCake()
				&& getAvailableItemNum("Gear") >= task.getNumOfGear()
				&& getAvailableItemNum("Screw") >= task.getNumOfScrew()) {

			// Changes the inventory list.
			for (int i = 0; i < task.numOfCake; i++)
				list.remove("Cake");
			for (int i = 0; i < task.numOfGear; i++)
				list.remove("Gear");
			for (int i = 0; i < task.numOfScrew; i++)
				list.remove("Screw");

			// Fixed the part and loads the next task.
			Image fixingPart = room.getImage(location.x, location.y);
			if (fixingPart.equals(Icon.ENGINE.getImage()))
				room.setImage(location.x, location.y, Icon.FIXEDENGINE);
			if (fixingPart.equals(Icon.CABIN.getImage()))
				room.setImage(location.x, location.y, Icon.FIXEDCABIN);
			if (fixingPart.equals(Icon.EXHAUST.getImage()))
				room.setImage(location.x, location.y, Icon.FIXEDEXHAUST);
			taskList.dequeue();
		}
	}

	/**
	 * The rover steps to the right. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the right. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the right
	 * then the robot has moved one space to the right. If a wall was to the
	 * right, nothing has happened. If a portal was to the right, the robot has
	 * teleported to another room and is standing on the entry portal.
	 * 
	 * @see IRover#goRight()
	 */
	@Override
	public void goRight() {
		if (location.x + 1 < Room.SIZE) {
			location.x = location.x + 1;
			if (isPortal())
				teleport();
		}

	}

	/**
	 * The rover steps to the left. This is a mutator method. Called by the Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the left. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the left
	 * then the robot has moved one space to the left. If a wall was to the
	 * left, nothing has happened. If a portal was to the left, the robot has
	 * teleported to another room and is standing on the entry portal.
	 * 
	 * @see IRover#goLeft()
	 */
	@Override
	public void goLeft() {
		if (location.x - 1 >= 0) {
			location.x = location.x - 1;
			if (isPortal())
				teleport();
		}

	}

	/**
	 * The rover steps to the north. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the north. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the north
	 * then the robot has moved one space to the north. If a wall was to the
	 * north, nothing has happened. If a portal was to the north, the robot has
	 * teleported to another room and is standing on the entry portal.
	 * 
	 * @see IRover#goUp()
	 */
	@Override
	public void goUp() {
		if (location.y - 1 >= 0) {
			location.y = location.y - 1;
			if (isPortal())
				teleport();
		}
	}

	/**
	 * (The rover steps to the south. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the south. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the south
	 * then the robot has moved one space to the south. If a wall was to the
	 * south, nothing has happened. If a portal was to the south, the robot has
	 * teleported to another room and is standing on the entry portal.
	 * 
	 * @see IRover#goDown()
	 */
	@Override
	public void goDown() {
		if (location.y + 1 < Room.SIZE) {
			location.y = location.y + 1;
			if (isPortal())
				teleport();
		}
	}

	/**
	 * Checks if the current location is a portal.
	 * 
	 * @return whether the current location is a portal
	 */
	public boolean isPortal() {
		return Icon.PORTAL.getImage().equals(
				room.getImage(location.x, location.y))
				|| Icon.FLASHINGPORTAL.getImage().equals(
						room.getImage(location.x, location.y));
	}

	/**
	 * Teleports the rover if it arrives at a portal. According to the portal
	 * stack status and the current room information, the rover will be
	 * teleported to the other portal.
	 */
	public void teleport() {

		// Changes the flashing portal to unflashing.
		if (room.getImage(location.x, location.y).equals(
				Icon.FLASHINGPORTAL.getImage()))
			room.setImage(location.x, location.y, Icon.PORTAL);

		if (room.getPortal(location) == null) {

			// If the location has no portal, creates a new one and links the
			// portal to another portal in a different room. Then pushes this
			// and next portals to the stack.

			Portal newPortal = new Portal(location, room);
			newPortal.connectPortal();
			room.setPortal(location, newPortal);

			// Changes the room and location properties of the rover.

			room = newPortal.getNextPortal().getRoom();
			Point newLocation = new Point(newPortal.getNextPortal()
					.getlocation());
			location = newLocation;
			room.setPortal(location, newPortal.getNextPortal());

			// Pushes to the stack.

			portalStack.push(newPortal);
			portalStack.push(newPortal.getNextPortal());

		} else if (!portalStack.isEmpty()
				&& portalStack.peek().getlocation().equals(location)) {

			// If the location is the same with the stack top portal location,
			// loads the previous room and location and pops the stack.

			room = portalStack.peek().getNextPortal().getRoom();
			Point newLocation = new Point(portalStack.peek().getNextPortal()
					.getlocation());
			location = newLocation;
			portalStack.pop();
			portalStack.pop();
		} else {

			// This means it is using the old portal. Pushes stack.

			Portal reusedPortal = room.getPortal(location);
			room = reusedPortal.getNextPortal().getRoom();
			Point newLocation = new Point(reusedPortal.getNextPortal()
					.getlocation());
			location = newLocation;
			portalStack.push(reusedPortal);
			portalStack.push(reusedPortal.getNextPortal());
		}
	}

	/**
	 * Pick up an item in the room at the rover's location. This is a mutator
	 * method. Called by the Gui.
	 * <P>
	 * Strategy: If we are standing on an item, pick it up. If not, do nothing.
	 * This will not pick up ship parts or portals.
	 * <P>
	 * Postconditions: the item is now in the inventory, the item is no longer
	 * in the room.
	 */
	@Override
	public void pickUp() {
		Image image = room.getImage(location.x, location.y);
		String object = "";

		// Proceeds if the box contains an image. According to the image,
		// updates the inventory and clear the image.
		if (image != null) {
			if (image.equals(Icon.CAKE.getImage())) {
				object = "Cake";
				room.setImage(location.x, location.y, null);
				list.add(object);
			} else if (image.equals(Icon.GEAR.getImage())) {
				object = "Gear";
				room.setImage(location.x, location.y, null);
				list.add(object);
			} else if (image.equals(Icon.SCREW.getImage())) {
				object = "Screw";
				room.setImage(location.x, location.y, null);
				list.add(object);
			}
		}
	}

	/**
	 * Changes the image on the portal leading towards home. This is a mutator
	 * method. Called by the Gui.
	 * <P>
	 * Strategy: If the stack is empty, we must already be home, do nothing.
	 * Otherwise, peek at the top of the stack and set that portal to use its
	 * flashy image. (The image may not actually flash but it will look
	 * different than the standard portal image.)
	 * 
	 * @see IRover#showTheWayBack()
	 */
	@Override
	public void showTheWayBack() {
		if (portalStack.isEmpty())
			;
		else {
			// Makes the previous portal flashing.
			Point portalLocation = portalStack.peek().getlocation();
			room.setImage(portalLocation.x, portalLocation.y,
					Icon.FLASHINGPORTAL);
		}

	}

}
